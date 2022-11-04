#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=5009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N],cnt,c[N],tot,ans[N];

struct dc {int val,id;} b[N];
bool cmp(const dc &a,const dc &b) {return a.val<b.val;}
void discrete() {
	rep(i,1,n) b[i]=(dc){a[i],i};
	sort(b+1,b+n+1,cmp);
	a[0]=-0x3f3f3f3f;
	rep(i,1,n) {
		if(b[i].val!=b[i-1].val) cnt++;
		if(b[i].val) a[b[i].id]=cnt;
		else a[b[i].id]=0;
	}
}

signed main() {
	n=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n) {
		for(int j=2;j*j<=abs(a[i]);j++) while(a[i]%(j*j)==0) a[i]/=(j*j);
	}
	discrete();
	//rep(i,1,n) printf("%lld ",a[i]); puts("");
	rep(l,1,n) {
		tot=0;
		rep(i,1,n) c[i]=0;
		rep(r,l,n) {
			if(c[a[r]]==0&&a[r]) tot++;
			c[a[r]]++;
			ans[max(tot,1ll)]++;
		}
	}
	rep(i,1,n) printf("%lld ",ans[i]);
	return 0;
}