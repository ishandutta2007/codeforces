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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , x , y , a[500010] , b[500010] , p[10];
LL l[10];
char c[500010] , cc;

int check(int xx , int yy)
{
	int dx = x-xx , dy = y-yy;
	if (dx == 0)
	{
		if (dy > 0) return 0;
		else return 4;
	}
	if (dy == 0)
	{
		if (dx > 0) return 6;
		else return 2;
	}
	if (dx == dy)
	{
		if (dx > 0) return 7;
		else return 3;
	}
	if (dx == -dy)
	{
		if (dx > 0) return 5;
		else return 1;
	}
	return -1;
}

LL dis(int xx , int yy)
{
	return fabs((LL)x-xx)+fabs((LL)y-yy);
}

int main ()
{
	int i , j , t;
	cin >> n >> x >> y;
	for (i = 1 ; i <= n ; i++)
	{
		cc = getchar();
		scanf("%c%d%d",&c[i],&a[i],&b[i]);
		t = check(a[i],b[i]);
		if (t >= 0 && (l[t] == 0 || l[t] > dis(a[i],b[i])))
		{
			l[t] = dis(a[i],b[i]);
			p[t] = i;
		}
	}
	t = 0;
	if (l[1] != 0 && (c[p[1]] == 'B' || c[p[1]] == 'Q')) t = 1;
	if (l[3] != 0 && (c[p[3]] == 'B' || c[p[3]] == 'Q')) t = 1;
	if (l[5] != 0 && (c[p[5]] == 'B' || c[p[5]] == 'Q')) t = 1;
	if (l[7] != 0 && (c[p[7]] == 'B' || c[p[7]] == 'Q')) t = 1;
	if (l[0] != 0 && (c[p[0]] == 'R' || c[p[0]] == 'Q')) t = 1;
	if (l[2] != 0 && (c[p[2]] == 'R' || c[p[2]] == 'Q')) t = 1;
	if (l[4] != 0 && (c[p[4]] == 'R' || c[p[4]] == 'Q')) t = 1;
	if (l[6] != 0 && (c[p[6]] == 'R' || c[p[6]] == 'Q')) t = 1;
	if (t) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}