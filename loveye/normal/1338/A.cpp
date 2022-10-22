#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5;
int t,n;
int a[N];
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		fr(i,1,n) cin>>a[i];
		rf(i,n,2) a[i]=a[i]-a[i-1];
		ll sum=0,ans=0;
		fr(i,2,n) {
			sum+=a[i]; sum=min(sum,0ll);
			if(sum<0) ans=max(ans,__lg(-sum)+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}