#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5;
int n,a[N];
ll s[N];
int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		cin>>n;
		fr(i,1,n) cin>>a[i];
		int ok=0;
		fo(i,2,n) if(a[i]>1) ok=1;
		if(ok&&!(n==3&&(a[2]&1))) {
			ll ans=0;
			fo(i,2,n) ans+=a[i]+1>>1;
			cout<<ans<<endl;
		} else cout<<-1<<endl;
	}
	return 0;
}