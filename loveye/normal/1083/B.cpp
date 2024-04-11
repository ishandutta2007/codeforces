#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=5e5+5;
int n,k;
ll a[N],b[N];
char s[N],t[N];
int main() {
	cin>>n>>k>>s+1>>t+1;
	if(k==1) return printf("%d\n",n),0;
	int p=-1;
	fr(i,1,n) if(s[i]^t[i]) {
		p=i; break;
	}
	if(p==-1) return printf("%d\n",n),0;
	fr(i,p+1,n) if(s[i]=='a') ++a[n-i+1];
	fr(i,p+1,n) if(t[i]=='b') ++a[n-i+1];
	ll ans=n*2-(p-1); k-=2;
	rf(i,n,1) {
		int res=min(a[i]+b[i],0ll+k);
		k-=res; ans+=1ll*res*i;
		b[i-1]+=a[i];
		b[i-1]+=b[i]*2;
		if(!k) break;
	}
	printf("%lld\n",ans);
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}