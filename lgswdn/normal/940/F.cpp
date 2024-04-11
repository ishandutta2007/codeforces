#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,a[N],bs,b[N],qcnt,ccnt,cnt[N],tot[N],ans[N];

struct disc {int id,val;} d[N];
bool cmp(const disc &x,const disc &y) {return x.val<y.val;}
void discrete() {
	rep(i,1,n+ccnt) d[i]=(disc){i,a[i]};
	sort(d+1,d+n+ccnt+1,cmp);
	int cnt=0;
	rep(i,1,n+ccnt) a[d[i].id]=(d[i].val==d[i-1].val?cnt:++cnt);
}

struct query {int id,l,r,ver;} q[N];
struct change {int p,val;} c[N];
bool cmp2(const query &x,const query &y) {
	return b[x.l]==b[y.l]?(b[x.r]==b[y.r]?x.ver<y.ver:x.r<y.r):x.l<y.l;
}

void inc(int x) {tot[cnt[a[x]]]--,tot[++cnt[a[x]]]++;}
void dec(int x) {tot[cnt[a[x]]]--,tot[--cnt[a[x]]]++;}
void mdf(int x,int i) {
	if(q[i].l<=c[x].p&&c[x].p<=q[i].r) {
		dec(c[x].p), swap(c[x].val,a[c[x].p]), inc(c[x].p);
	} else swap(c[x].val,a[c[x].p]);
}

int main() {
	n=read(), m=read(), bs=pow(n,0.66);
	rep(i,1,n) a[i]=read(), b[i]=(i-1)/bs+1;
	rep(i,1,m) {
		int opt=read(), x=read(), y=read();
		if(opt==1) q[++qcnt]=(query){qcnt,x,y,ccnt};
		else c[++ccnt]=(change){x,y};
	}
	rep(i,1,ccnt) a[n+i]=c[i].val;
	discrete();
	rep(i,1,ccnt) c[i].val=a[n+i];
	sort(q+1,q+qcnt+1,cmp2);
	int l=1,r=0,ver=0;
	rep(i,1,qcnt) {
		while(l>q[i].l) inc(--l);
		while(r<q[i].r) inc(++r);
		while(l<q[i].l) dec(l++);
		while(r>q[i].r) dec(r--);
		while(ver<q[i].ver) mdf(++ver,i);
		while(ver>q[i].ver) mdf(ver--,i);
		//rep(i,1,n) printf("%d ",cnt[i]); puts("");
		ans[q[i].id]=1;
		while(tot[ans[q[i].id]]) ans[q[i].id]++;
	}
	rep(i,1,qcnt) printf("%d\n",ans[i]);
	return 0;
}