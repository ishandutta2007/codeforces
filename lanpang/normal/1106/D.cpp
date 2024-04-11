#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
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
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , m , f[maxn];
set<int> s;
vector<int> v[maxn] , q;

int main()
{
	int i , j , x , y;
	cin >> n >> m;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	f[1] = 1;
	s.insert(1);
	for (i = 1 ; i <= n ; i++)
	{
		x = (*s.begin());
		s.erase(s.begin());
		q.push_back(x);
		for (auto j: v[x]) 
		{
			if (f[j] == 0) 
			{
				f[j] = 1;
				s.insert(j);
			}
		}
	}
	for (auto i: q) 
		printf("%d ",i);
	cout << "\n";
	return 0;
}