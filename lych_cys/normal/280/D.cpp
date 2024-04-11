#include <bits/stdc++.h>
#define N 300005
using namespace std;

int n,m; bool tg[N];
struct num{ int val,l,r; }h[25];
struct node{ num x,y,z,s; }p[N][2];
int read(){
	int x=0; char cr=getchar(); bool flag=0;
	while (cr<'0' || cr>'9'){ if (cr=='-') flag=1; cr=getchar(); }
	while (cr>='0' && cr<='9'){ x=x*10+cr-'0'; cr=getchar(); }
	return (flag)?-x:x;
}
num operator +(const num &x,const num&y){
	return (num){x.val+y.val,min(x.l,y.l),max(x.r,y.r)};
}
void R(num &x){ x.val=-x.val; }
num mn(num x,num y){ return (x.val<y.val)?x:y; }
num mx(num x,num y){ return (x.val>y.val)?x:y; }
void mdy(int k,int x,int y){
	int i;
	for (i=0; i<2; i++)
		p[k][i].x=p[k][i].y=p[k][i].z=p[k][i].s=(num){y,x,x};
}
void maintain(int k){
	int l=k<<1,r=l|1;
	p[k][0].s=p[k][1].s=p[l][0].s+p[r][0].s;
	p[k][0].x=mn(p[l][0].x,p[l][0].s+p[r][0].x);
	p[k][0].y=mn(p[r][0].y,p[r][0].s+p[l][0].y);
	p[k][0].z=mn(p[l][0].y+p[r][0].x,mn(p[l][0].z,p[r][0].z));
	p[k][1].x=mx(p[l][1].x,p[l][1].s+p[r][1].x);
	p[k][1].y=mx(p[r][1].y,p[r][1].s+p[l][1].y);
	p[k][1].z=mx(p[l][1].y+p[r][1].x,mx(p[l][1].z,p[r][1].z));
}
void ovr(int k){
	tg[k]=!tg[k];
	int i;
	for (i=0; i<2; i++){
		R(p[k][i].x); R(p[k][i].y); R(p[k][i].z); R(p[k][i].s);
	}
	swap(p[k][0],p[k][1]);
}
void pushdown(int k){
	if (tg[k]){
		ovr(k<<1); ovr(k<<1|1); tg[k]=0;
	}
}
void build(int k,int l,int r){
	if (l==r){
		mdy(k,l,read()); return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r); maintain(k);
}
void ins(int k,int l,int r,int x,int y){
	if (l==r){
		mdy(k,x,y); return;
	}
	int mid=l+r>>1; pushdown(k);
	if (x<=mid) ins(k<<1,l,mid,x,y); else ins(k<<1|1,mid+1,r,x,y); maintain(k);
}
void turn(int k,int l,int r,int x,int y){
	if (x<=l && r<=y){
		ovr(k); return;
	}
	int mid=l+r>>1; pushdown(k);
	if (x<=mid) turn(k<<1,l,mid,x,y);
	if (y>mid) turn(k<<1|1,mid+1,r,x,y); maintain(k);
}
node qry(int k,int l,int r,int x,int y){
	if (x<=l && r<=y) return p[k][1];
	int mid=l+r>>1; pushdown(k);
	if (y<=mid) return qry(k<<1,l,mid,x,y); else
	if (x>mid) return qry(k<<1|1,mid+1,r,x,y); else{
		node u=qry(k<<1,l,mid,x,y),v=qry(k<<1|1,mid+1,r,x,y);
		return (node){mx(u.x,u.s+v.x),mx(v.y,v.s+u.y),mx(u.y+v.x,mx(u.z,v.z)),u.s+v.s};
	}
}
int main(){
	n=read();
	int i,k,x,y,z,ans=0;
	build(1,1,n);
	m=read();
	while (m--){
		k=read(); x=read(); y=read();
		if (!k) ins(1,1,n,x,y); else{
			z=read(); ans=0;
			for (i=1; i<=z; i++){
				h[i]=qry(1,1,n,x,y).z;
				if (h[i].val<0) break;
				ans+=h[i].val; turn(1,1,n,h[i].l,h[i].r);
			}
			printf("%d\n",ans);
			for (i--; i; i--) turn(1,1,n,h[i].l,h[i].r);
		}
	}
	return 0;
}