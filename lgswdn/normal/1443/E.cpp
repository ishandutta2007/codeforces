#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=19;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,q,tx=1,bs,fac[N],s[200009];

bool vst[N];
void modify(int x) {
	tx+=x; int t=tx;
	memset(vst,0,sizeof(vst));
	rep(i,bs,n-1) {
		int tot=0;
		rep(j,bs,n) if((!vst[j-bs])&&(tot+=fac[n-i])>=t)	
			{t-=tot-fac[n-i], s[i]=s[i-1]+j, vst[j-bs]=1; break;}
	}
	rep(j,bs,n) if(!vst[j-bs]) s[n]=s[n-1]+j;
}

signed main() {
	n=read(), q=read();
	fac[0]=1;
	rep(i,1,15) fac[i]=fac[i-1]*i;
	rep(i,1,n) s[i]=i*(i+1)/2;
	bs=max(1ll,n-15);
	while(q--) {
		int opt=read(), x=read(), y;
		if(opt==1) y=read(), printf("%lld\n",s[y]-s[x-1]);
		else modify(x);
	}
	return 0;
}