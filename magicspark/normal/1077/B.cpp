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
int n,a[105],ans;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=2;i<=n;i++) 
		if (a[i-1]==1 && a[i]==0 && a[i+1]==1)
			ans++,a[i+1]=0;
	cout<<ans<<endl;
	return 0;
}