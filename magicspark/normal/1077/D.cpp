#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
#define Rep(i,a,b) for (int i=(a);i<=(b);++i)
#define repit(it,a) for (__typeof(a.begin()) it=a.begin();it!=a.end();it++)
#define SZ(s) ((int)s.size())
#define All(a) a.begin(),a.end()
#define MP make_pair
#define pb push_back
using namespace std;
const int inf=0x3f3f3f3f;
const int lnf=0x3f3f3f3f3f3f3f3f;
const int Maxn=200005;
int n,k,a[Maxn],res[Maxn];
bool check(int mid)
{
	if (mid==0) return false;
	int cnt=0;
	for (int i=1;i<=200000;++i)
	{
		cnt+=a[i]/mid;
	}
	if (cnt>=k) return true;
	else return false;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie();
	cin>>n>>k;
	rep(i,n)
	{
		int x;
		cin>>x;
		a[x]++;
	}
	int l=0,r=200005,ans=1;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	int top=0;
	for (int i=1;i<=200000;++i)
	{
		int len=a[i]/ans;
		while (len--) res[top++]=i;
	}
	for (int i=0;i<min(top,k);++i) cout<<res[i]<<" ";
	return 0;
}