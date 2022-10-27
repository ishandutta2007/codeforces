#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAX 300300
#define mp make_pair
int n, f;
vector <int> t;
vector <pair <int, int> > s, Q(MAX);
vector <pair <pair <int, int>, int> >Ans;
void add(int i, int j, int d)
{
	i = s[i].second, j = s[j].second;
	Ans.push_back(mp(mp(i, j), d));
}
int main()
{
	cin >> n;
	s.resize(n);
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		s[i] = {x, i};
	}
	t.resize(n);
	for(int i = 0; i < n;++i)
	{
		cin >> t[i];
	}
	sort(t.begin(), t.end());
	sort(s.begin(), s.end());
	for(int i = 0; i < n; ++i)
	{
		if(s[i].first < t[i])
			Q[++f] = mp(i, t[i] - s[i].first);
		else
		{
			if(s[i].first != t[i])
			{
				int p = s[i].first - t[i];
				while(p && f)
				{
					int mv = min(p, Q[f].second);
					add(Q[f].first, i, mv);
					p -= mv;
					Q[f].second -= mv;
					if(!Q[f].second)
					{
						--f;
					}
				}
				if(p)
				{
					cout << "NO";
					return 0;
				}
			}
		}
	}
	if(f)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl << Ans.size() << endl;
	for(auto p:Ans)
	{
		cout << p.first.first + 1 << " " << p.first.second + 1 << " " << p.second << endl; 
	}
	return 0;
}