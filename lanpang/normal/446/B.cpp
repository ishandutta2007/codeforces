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
const int maxn = 5e3+10;
const int maxk = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , k , p , x , s1[maxn] , s2[maxn];
LL ans , ss1[maxk] , ss2[maxk] , g , q1[maxk] , q2[maxk];
priority_queue<LL> p1 , p2 , pp1 , pp2;

int main()
{
	int i , j;
	cin >> n >> m >> k >> p;
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= m ; j++)
		{
			scanf("%d",&x);
			s1[i] += x;
			s2[j] += x;
		}
	}
	for (i = 1 ; i <= n ; i++)
		p1.push(s1[i]);
	for (j = 1 ; j <= m ; j++)
		p2.push(s2[j]);
	for (i = 1 ; i <= k ; i++)
	{
		pp1.push(p1.top());
		g = p1.top();
		g -= m*p;
		p1.pop();
		p1.push(g);
	}
	for (i = 1 ; i <= k ; i++)
	{
		q1[i] = pp1.top();
		pp1.pop();
	}
	for (i = 1 ; i <= k ; i++)
		ss1[i] = ss1[i-1]+q1[i];
	for (i = 1 ; i <= k ; i++)
	{
		pp2.push(p2.top());
		g = p2.top();
		g -= n*p;
		p2.pop();
		p2.push(g);
	}
	for (i = 1 ; i <= k ; i++)
	{
		q2[i] = pp2.top();
		pp2.pop();
	}
	for (i = 1 ; i <= k ; i++)
		ss2[i] = ss2[i-1]+q2[i];
	ans = -(1LL << 60);
	for (i = 0 ; i <= k ; i++)
		ans = max(ans,ss1[i]+ss2[k-i]-(LL)i*p*(k-i));
	cout << ans << "\n"; 
	return 0;
}