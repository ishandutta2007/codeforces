#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=5e5+9,inf=0x3f3f3f3f3f3f3f3f;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,h[N],b[N],mn[N],pos[N],f[N][29];

struct node {int l,r,f,gf,tag,mn;} t[N<<2];
void build(int p,int l,int r) {
	int mid=((t[p].l=l)+(t[p].r=r))>>1; t[p].f=t[p].gf=t[p].tag=-inf, t[p].mn=h[l];
	if(l==r) return;
	build(p*2,l,mid), build(p*2+1,mid+1,r);
}
void pushdown(int p) {
	if(t[p].tag==-inf) return;
	t[p*2].tag=t[p*2+1].tag=t[p].tag;
	t[p*2].gf=t[p*2].f+t[p].tag, t[p*2+1].gf=t[p*2+1].f+t[p].tag;
}
void add(int p,int x,int f,int gf) {
	int l=t[p].l,r=t[p].r,mid=(l+r)/2;
	if(l==x&&r==x) {t[p].f=f,t[p].gf=gf; return;}
	if(x<=mid) add(p*2,x,f,gf);
	else add(p*2+1,x,f,gf);
	t[p].f=max(t[p*2].f,t[p*2+1].f), t[p].gf=max(t[p*2].gf,t[p*2+1].gf);
}
void upd(int p,int x,int y,int g) {
	int l=t[p].l,r=t[p].r,mid=(l+r)/2;
	if(l==x&&r==y) {t[p].gf=t[p].f+g; t[p].tag=g; return;}
	pushdown(p);
	if(y<=mid) upd(p*2,x,y,g);
	else if(x>mid) upd(p*2+1,x,y,g);
	else upd(p*2,x,mid,g), upd(p*2+1,mid+1,y,g);
	t[p].gf=max(t[p*2].gf,t[p*2+1].gf);
}
int qry(int p,int x,int y) {
	int l=t[p].l,r=t[p].r,mid=(l+r)/2;
	if(l==x&&r==y) return t[p].gf;
	pushdown(p);
	if(y<=mid) return qry(p*2,x,y);
	else if(x>mid) return qry(p*2+1,x,y);
	else return max(qry(p*2,x,mid),qry(p*2+1,mid+1,y));
}

int stq(int l,int r) {
	int llen=log2(r-l+1);
	return min(f[l][llen],f[r-(1<<llen)+1][llen]);
}

signed main() {
	n=read();
	rep(i,1,n) h[i]=read();
	rep(i,1,n) b[i]=read();
	rep(i,1,n) f[i][0]=h[i];
	rep(j,1,20) rep(i,1,n) {
		if(i+(1<<j)-1>n) continue;
		f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
	}
	build(1,1,n);
	//pos[i]=j: [j,i]h[i] 
	rep(i,1,n) {
		int l=1,r=i;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(stq(mid,i)==h[i]) pos[i]=mid, r=mid-1;
			else l=mid+1;
		}
		//cout<<pos[i]<<endl;
	}
	int mpos=1;
	add(1,1,b[1],b[1]);
	if(n==1) printf("%lld\n",b[1]);
	rep(i,2,n) {
		if(h[i]<h[mpos]) mpos=i;
		upd(1,max(pos[i]-1,1ll),i-1,b[i]);
		int x=qry(1,1,i-1); x=max(x,b[mpos]);
		add(1,i,x,x+b[i]);
		if(i==n) printf("%lld\n",x);
	}
	return 0;
}