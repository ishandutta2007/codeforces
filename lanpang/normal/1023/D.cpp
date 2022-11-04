#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , q , a[maxn] , b[maxn] , i;
vector <int> v[maxn];
set <int> st;

int main()
{
	cin >> n >> q;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
		st.insert(i);
	}
	if (v[q].size() == 0)
	{
		if (v[0].size() == 0)
		{
			cout << "NO\n";
			return 0;
		}
		else
		{
			a[v[0][0]] = q;
			v[q].push_back(v[0][0]);
		}
	}
	for (i = q ; i >= 1 ; i--)
	{
		if (v[i].size() > 0)
		{
			auto it = st.lower_bound(v[i][0]);
			auto itt = it;
			if (itt != st.begin())
			{
				itt--;
				while (1)
				{
					if (a[(*itt)] == 0 || a[(*itt)] == i) a[(*itt)] = i;
					else break;
					if (itt == st.begin()) 
					{
						break;
						st.erase(itt);
					}
					auto ittt = itt;
					itt--;
					st.erase(ittt);
				}
			}
			itt = it;
			itt++;
			while (1)
			{
				if (itt == st.end()) break;
				if (a[(*itt)] == 0 || a[(*itt)] == i) a[(*itt)] = i;
				else break;
				auto ittt = itt;
				itt++;
				st.erase(ittt);
			}
			st.erase(it);
			it = st.lower_bound(v[i][v[i].size()-1]);
			if (it != st.end() && (*it) == v[i][v[i].size()-1])
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for (i = 1 ; i <= n ; i++)
		printf("%d ",a[i]);
	cout << "\n";
	return 0;
}