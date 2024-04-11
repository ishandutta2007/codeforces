#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;


const int maxn = 1e5 + 100;

vector <int> x[maxn];
vector <int> divs[maxn];
vector <pair<int, int> > ans;
vector <int> p;

bool used[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		int val = i;
		for (int j = 0; j < (int) p.size() && val != 1; j++)
		{
			if (val % p[j] != 0)
				continue;
			divs[i].push_back(j);
			while (val % p[j] == 0)
				val /= p[j];
		}
		if (val != 1)
		{
			divs[i].push_back(p.size() );
			p.push_back(val);
		}
		x[divs[i].back() ].push_back(i);
	}
	

	for (int i = p.size(); i >= 0; i--)
	{
		vector <int> cur = x[i];
		if (cur.size() == 0)
			continue;
		int some = 0;
		for (int j = 0; j < (int) cur.size(); j++)
			if (divs[cur[some] ].size() < divs[cur[j] ].size() )
				some = j;
		swap(cur[some], cur[cur.size() - 1] );
		some = cur.back();
		if (cur.size() % 2 == 1 && divs[some].size() > 1)
		{
			divs[some].pop_back();
			x[divs[some].back() ].push_back(some);
		}
		for (int j = 0; j < (int) cur.size() - 1; j += 2)
		{
			used[cur[j] ] = used[cur[j + 1] ] = true;
			ans.push_back(make_pair(cur[j], cur[j + 1] ) );
		}
	
	}
	printf("%d\n", (int) ans.size() );
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);


	return 0;
}