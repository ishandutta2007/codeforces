#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e6+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,k,s[N],bs,b[N],cnt[N],tot,ans[N];

struct query {int id,l,r;} q[N];
bool cmp(const query &x,const query &y) {
	return b[x.l]==b[y.l]?x.r<y.r:x.l<y.l;
}

void inc(int x) {tot+=cnt[s[x]^k], cnt[s[x]]++;}
void dec(int x) {cnt[s[x]]--, tot-=cnt[s[x]^k];}

signed main() {
	n=read(), m=read(), k=read(), bs=pow(n,0.5);
	rep(i,1,n) s[i]=s[i-1]^read(), b[i]=(i-1)/bs+1;
	rep(i,1,m) {
		int l=read(), r=read();
		q[i]=(query){i,l-1,r};
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;
	rep(i,1,m) {
		while(l>q[i].l) inc(--l);
		while(r<q[i].r) inc(++r);
		while(l<q[i].l) dec(l++);
		while(r>q[i].r) dec(r--);
		ans[q[i].id]=tot;
	}
	rep(i,1,m) printf("%lld\n",ans[i]);
	return 0;
}