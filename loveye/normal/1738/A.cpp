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

const int N=1e5+5;
int n,a[N],b[N],tmp[N],tot;
int main() {
	int T=read();
	while(T--) {
		n=read();
		int cnt[2]={0};
		fr(i,1,n) a[i]=read(),++cnt[a[i]];
		fr(i,1,n) b[i]=read();
		if(cnt[0]==cnt[1]) {
			cout<<accumulate(b+1,b+n+1,0ll)*2-*min_element(b+1,b+n+1)<<endl;
		} else {
			int c=cnt[0]>cnt[1]?0:1;
			ll ans=0;
			tot=0;
			fr(i,1,n) if(a[i]==!c) ans+=b[i]*2;
			else tmp[++tot]=b[i];
			sort(tmp+1,tmp+tot+1);
			fr(i,1,tot) ans+=tmp[i];
			fr(i,1,cnt[!c]) ans+=tmp[tot-i+1];
			cout<<ans<<endl;
		}
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}