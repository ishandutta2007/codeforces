#include <bits/stdc++.h>
using namespace std;
int n, test, a[555], tar[555], cnt, cur, pos;
bool u[555], f, ff;
vector<int> anst;
vector<pair<int, int> > ansc;
void rev(int n)
{
	for (int i = 1; i <= n; i++)
	{
		ansc.push_back(make_pair(cur + n + i - 1, a[i]));
	}
	anst.push_back(n * 2);
	cur += (n * 2);
	for (int i = 1; i <= (n >> 1); i++) swap(a[i], a[n + 1 - i]); 
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		if (n & 1)
		{
			printf("-1\n");
			continue;
		}
		f = 0;
		for (int i = 1; i <= n; i++)
		{
			u[i] = 0;
		}
		cnt = 1;
		for (int i = 1; i <= n; i++)
		{
			if (u[i]) continue;
			ff = 0;
			for (int j = 1; j <= n; j++)
			{
				if (!u[j] && i != j && a[i] == a[j])
				{
					tar[cnt] = tar[cnt + (n >> 1)] = a[i];
					u[i] = u[j] = 1;
					ff = 1;
					cnt++;
					break;
				}
			}
			if (!ff)
			{
				f = 1;
				break;
			}
		}
		if (f)
		{
			printf("-1\n");
			continue;
		}
	//	for (int i = 1; i <= n; i++) cout << tar[i] << " ";
	//	cout << endl;
		anst.clear(); ansc.clear();
		cur = 0;
		for (int i = n; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++)
			{
				if (a[j] == tar[i])
				{
					pos = j;
					break;
				}
			}
			if (pos != 1) rev(pos);
			rev(i);
		}
		anst.push_back(n);
		printf("%d\n", (int)ansc.size());
		for (int i = 0; i < ansc.size(); i++)
		{
			printf("%d %d\n", ansc[i].first, ansc[i].second);
		}
		printf("%d\n", (int)anst.size());
		for (int i = 0; i < anst.size(); i++)
		{
			printf("%d ", anst[i]);
		}
		printf("\n");
	}
	return 0;
}