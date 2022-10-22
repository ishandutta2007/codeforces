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

const int N=2e5+5;
int n,a[N],s[N];
int main() {
	int T=read();
	while(T--) {
		n=read();
		fr(i,1,n) a[i]=read(),s[i]=s[i-1]+a[i];
		int ans1=0,ans2=0;
		fr(i,1,n) if(!a[i]) ++ans1;
		fr(i,1,n) if(a[i]) {
			int res=(i-1)-s[i-1],use=s[i-1];
			int cnt1=s[n]-s[i],cnt0=n-i-cnt1;
			ans2=max(ans2,res+1+min(use,cnt0)+cnt1);
		}
		printf("%d\n",n-max(ans1,ans2));
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}