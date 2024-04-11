#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const LL INF=1e18;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int n,m;
LL h[N];
LL b[N];
int q[N];
struct node{
	int l,r;
	LL mx,laz;
}d[N<<2];
void B(int l,int r,int id){
	d[id].l=l;d[id].r=r;
	d[id].mx=-INF;
	d[id].laz=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	B(l,mid,id<<1);
	B(mid+1,r,id<<1|1);
	return;
}
#define ls id<<1
#define rs id<<1|1
void pushdown(int id){
	if(d[id].l==d[id].r) return;
	d[ls].laz+=d[id].laz;d[rs].laz+=d[id].laz;
	d[ls].mx+=d[id].laz;d[rs].mx+=d[id].laz;
	d[id].laz=0;
}
void Change(int l,int id,LL w){
	pushdown(id);
	if(d[id].l==d[id].r){
		d[id].mx=w;
		return;
	}
	if(l<=d[ls].r) Change(l,ls,w);
	else Change(l,rs,w);
	d[id].mx=max(d[ls].mx,d[rs].mx);
	return;
}
void add(int l,int r,int id,LL w){
	pushdown(id);
	if(d[id].l==l&&d[id].r==r){
		d[id].mx+=w;
		d[id].laz+=w;
		return;
	}
	if(r<=d[ls].r) add(l,r,ls,w);
	else if(l>d[ls].r) add(l,r,rs,w);
	else{
		add(l,d[ls].r,ls,w);
		add(d[rs].l,r,rs,w);
	}
	d[id].mx=max(d[ls].mx,d[rs].mx);
	return;
}
LL f[N];
void MAIN(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
    	scanf("%lld",&h[i]);
	}
	h[0]=-INF;
	for(int i=1;i<=n;++i){
		scanf("%lld",&b[i]);
	}
	B(0,n,1);
	int r=0;q[0]=0;f[0]=0;
	Change(0,1,f[0]);
	for(int i=1;i<=n;++i){
		while(r>0&&h[q[r]]>h[i]){
			add(q[r-1],q[r]-1,1,-b[q[r]]);
			--r;
		}
		q[++r]=i;
		add(q[r-1],q[r]-1,1,b[q[r]]);
		f[i]=d[1].mx;
		Change(i,1,f[i]);
	}
	printf("%lld\n",f[n]);
	return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}