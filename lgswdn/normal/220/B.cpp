#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,Q,a[N],ans[N];

struct query {int l,r,id;} q[N];
int b[N],cnt[N],tot;
bool cmp(const query &x, const query &y) {
	return b[x.l]==b[y.l] ? ((b[x.l]&1) ? x.r<y.r : x.r>y.r) : b[x.l]<b[y.l];
}
void dec(int x) {
	if(a[x]>n) return;
	if(cnt[a[x]]==a[x]) tot--;
	cnt[a[x]]--;
	if(cnt[a[x]]==a[x]) tot++;
}
void inc(int x) {
	if(a[x]>n) return;
	if(cnt[a[x]]==a[x]) tot--;
	cnt[a[x]]++;
	if(cnt[a[x]]==a[x]) tot++;
}
void solve() {
	int bs=pow(n,0.5);
	rep(i,1,n) b[i]=(i-1)/bs+1;
	sort(q+1,q+Q+1,cmp);
	int l=1,r=0;
	rep(i,1,Q) {
		while(l>q[i].l) inc(--l);
		while(r<q[i].r) inc(++r);
		while(l<q[i].l) dec(l++);
		while(r>q[i].r) dec(r--);
		ans[q[i].id]=tot;
	}
	rep(i,1,Q) printf("%d\n",ans[i]);
}

int main() {
	n=read(), Q=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,Q) q[i].l=read(), q[i].r=read(), q[i].id=i;
	solve();
	return 0;
}