#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 3e5+10;
const int maxm = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int t , p , c;
}h[maxn] , t[maxn];

int n , m , k , a , b , c , d , lh , lt , mh[maxn] , mt[maxn] , top , mad , f[maxn] , ff , time;
LL mil[maxm] , mir[maxm] , mi , cost;

bool cmp1(mmp x , mmp y)
{
	if (x.t == y.t) return x.c < y.c;
	else return x.t < y.t;
}

bool cmp2(mmp x , mmp y)
{
	if (x.t == y.t) return x.c < y.c;
	else return x.t > y.t;
}

int main ()
{
	cin >> n >> m >> k;
	mad = 0;
	for (int i = 1 ; i <= m ; i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		mad = max(mad,a);
		if (c == 0)
		{
			lh++;
			h[lh].t = a;
			h[lh].p = b;
			h[lh].c = d; 
		}
		else
		{
			lt++;
			t[lt].t = a;
			t[lt].p = c;
			t[lt].c = d; 
		}
	}
	sort(h+1,h+lh+1,cmp1);
	sort(t+1,t+lt+1,cmp2);
	top = 0;
	for (int i = 1 ; i <= lh ; i++)
	{
		int p = h[i].p;
		if (mh[p] == 0 || h[i].c < mh[p])
		{
			mh[p] = h[i].c;
			top++;
			h[top] = h[i];
		}
	}
	lh = top;
	top = 0;
	for (int i = 1 ; i <= lt ; i++)
	{
		int p = t[i].p;
		if (mt[p] == 0 || t[i].c < mt[p])
		{
			mt[p] = t[i].c;
			top++;
			t[top] = t[i];
		}
	}
	lt = top;
	for (int i = 1 ; i <= lh ; i++)
	{
		if (f[h[i].p] == 0) ff++;
		else cost -= (LL)f[h[i].p];
		cost += (LL)h[i].c;
		f[h[i].p] = h[i].c;
		time = h[i].t;
		if (ff == n) mil[time] = cost;
	}
	for (int i = 1 ; i <= mad-k-1 ; i++) if (mil[i] == 0) mil[i] = mil[i-1]; 
	ff = 0;
	for (int i = 1 ; i <= n ; i++) f[i] = 0;
	cost = 0;
	for (int i = 1 ; i <= lt ; i++)
	{
		if (f[t[i].p] == 0) ff++;
		else cost -= (LL)f[t[i].p];
		cost += (LL)t[i].c;
		f[t[i].p] = t[i].c;
		time = t[i].t;
		if (ff == n) mir[time] = cost;
	}
	for (int i = mad ; i >= k+2 ; i--) if (mir[i] == 0) mir[i] = mir[i+1]; 
	for (int i = 1 ; i <= mad-k-1 ; i++)
	{
		//cout << i << " " << mil[i] << " " << i+k+1 << " "  << mir[i+k+1] << "\n";
		if (mil[i] > 0 && mir[i+k+1] > 0)
		{
			if (mi == 0) mi = mil[i]+mir[i+k+1];
			else mi = min(mi,mil[i]+mir[i+k+1]);
		}
	}
	if (mi) cout << mi << "\n";
	else cout << "-1\n";
	//system("PAUSE");
	return 0;
}