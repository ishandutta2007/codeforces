#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for (int i=0;i<(n);++i)
#define rep1(i,n) for (int i=1;i<=(n);++i)
#define Rep(i,a,b) for (int i=(a);i<=(b);++i)
#define All(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define fillset(a,val) memset(a,val,sizeof(a))
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
const int inf=0x3f3f3f3f;
const ll lnf=0x3f3f3f3f3f3f3f3f;
const int Maxn=1007;
int n,a[Maxn];
int main(){
	cin>>n;
	rep1(i,n) cin>>a[i];
	int res=inf,T;
	for (int t=1;t<=100;++t)
	{
		int ans=0;
		rep1(i,n)
			if (t-1>a[i]) ans+=t-1-a[i];
			else if (t+1<a[i]) ans+=a[i]-t-1;
		if (ans<res)
			res=ans,T=t;
	}
	cout<<T<<" "<<res<<endl;
	return 0;
}