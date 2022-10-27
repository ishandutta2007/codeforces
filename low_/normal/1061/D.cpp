#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000007
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, x, y, L[mn], R[mn];
int prv[mn];
int getprv(int u)
{
	if (u==prv[u]) return u;
	return prv[u]=getprv(prv[u]);
}

int CNP(int u, int l, int r)
{
	if (u<=R[l]) return l-1;
	if (u>R[r]) return r;
	
	int mid=(l+r)/2;
	if (u>R[mid]) return CNP(u, mid+1, r);
	else return CNP(u, l, mid);
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x>>y;
	for (int i=1; i<=n; i++) cin>>L[i]>>R[i], prv[i]=i;
	
	int ans=0;
	for (int i=1; i<=n; i++) ans=(ans+((R[i]-L[i])*y)%mod)%mod;
	
	sort(L+1, L+1+n);
	sort(R+1, R+1+n);
	
	
	for (int i=1; i<=n; i++)
	{
		int c=CNP(L[i], 1, n);
		c=getprv(c);
		
		int M;
		if (c==0) M=x;
		else 
		{
			if (x<=(L[i]-R[c])*y) M=x;
			else M=(L[i]-R[c])*y, prv[c]=c-1;
		}
		ans=(ans+M%mod)%mod;
	}
	cout<<ans;
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/