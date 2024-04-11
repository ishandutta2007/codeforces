#include<bits/stdc++.h>
 
using namespace std;
vector <int> dsu, rang;
int pred(int a)
{
	if(dsu[a] == a)
	{
		return a;
	}
	return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
	a = pred(a);
	b = pred(b);
	dsu[a] = b;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	dsu.resize(n + 1);
	rang.resize(n + 1);
	for(int i = 0; i <= n; i++)
	{
		dsu[i] = i;
		rang[i] = 1;
	}
	int en1 = n;
	int en2 = n;
	vector <int> go_to(n + 1, -1);
	vector <pair <int, int> > mass;
	for(int i = n - 1; i >= 0; i--)
	{
		if(s[i] == '?')
		{
			go_to[i] = max(en1, en2) - i;
		}
		else if(s[i] == '1')
		{
			go_to[i] = en1 - i;
			en2 = i;
		}
		else
		{
			go_to[i] = en2 - i;
			en1 = i;
		}
		mass.push_back({go_to[i], i});
	}
	sort(mass.begin(), mass.end());
	int it = 0;
	for(int i = 1; i <= n; i++)
	{
		int sum = 0;
		int j = 0;
		while(j < n)
		{
			j = pred(j);
			if(j == pred(n))
			{
				break;
			}
			j += i;
			sum++;
		}
		while(it < mass.size() && mass[it].first == i)
		{
			if(mass[it].second > 0 && go_to[mass[it].second - 1] == -1)
			{
				unite(mass[it].second - 1, mass[it].second);
			}
			unite(mass[it].second, mass[it].second + 1);
			go_to[mass[it].second] == -1;
			it++;
		}
		cout << sum << " ";
	}
	return 0;
}