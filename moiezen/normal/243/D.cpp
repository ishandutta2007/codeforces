#include <cstdio>
#include <iostream>
#include <algorithm>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define N 1005
int n,vx,vy,a[N][N];
int ref[N][N],dict[N*(N+2)],cnt;
long long ans;
int maxv(int a,int b){
	return a>b?a:b;
}
int minv(int a,int b){
	return a<b?a:b;
}
struct node{
	int lson,rson,info,tag;
}t[N*(N+2)*2];
int tsize;
void build(int l,int r,int x){
	t[x].info=t[x].tag=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid,t[x].lson=++tsize);
	build(mid+1,r,t[x].rson=++tsize);
}
void update(int x){
	t[x].info=maxv(t[x].info,t[x].tag);
}
void pushup(int x){
	t[x].info=minv(t[t[x].lson].info,t[t[x].rson].info);
}
void pushdown(int x){
	if(t[x].tag){
		t[t[x].lson].tag=maxv(t[t[x].lson].tag,t[x].tag);
		update(t[x].lson);
		t[t[x].rson].tag=maxv(t[t[x].rson].tag,t[x].tag);
		update(t[x].rson);
		t[x].tag=0;
	}
}
void modif(int ll,int rr,int l,int r,int v,int x){
	if(ll==l&&rr==r){
		t[x].tag=maxv(t[x].tag,v);
		update(x);
		return;
	}
	int mid=ll+rr>>1;
	if(r<=mid) modif(ll,mid,l,r,v,t[x].lson);
	else if(l>mid) modif(mid+1,rr,l,r,v,t[x].rson);
	else{
		modif(ll,mid,l,mid,v,t[x].lson);
		modif(mid+1,rr,mid+1,r,v,t[x].rson);
	}
	pushup(x);
}
int res(int ll,int rr,int l,int r,int x){
	if(ll==l&&rr==r) return t[x].info;
	pushdown(x);
	int mid=ll+rr>>1;
	if(r<=mid) return res(ll,mid,l,r,t[x].lson);
	else if(l>mid) return res(mid+1,rr,l,r,t[x].rson);
	else return minv(res(ll,mid,l,mid,t[x].lson),res(mid+1,rr,mid+1,r,t[x].rson));
}
int main(){
	scanf("%d%d%d",&n,&vx,&vy);
	rpt(i,1,n) rpt(j,1,n) scanf("%d",&a[i][j]);
	if(vx<0){
		vx=-vx;
		rpt(i,1,n/2) rpt(j,1,n) std::swap(a[i][j],a[n-i+1][j]);
	}
	if(vy<0){
		vy=-vy;
		rpt(i,1,n) rpt(j,1,n/2) std::swap(a[i][j],a[i][n-j+1]);
	}
	cnt=0;
	rpt(i,0,n) rpt(j,0,n) dict[++cnt]=ref[i][j]=i*vy-j*vx;
	std::sort(dict+1,dict+cnt+1);
	rpt(i,0,n) rpt(j,0,n) ref[i][j]=std::lower_bound(dict+1,dict+cnt+1,ref[i][j])-dict;
	build(1,cnt,tsize=1);
	ans=0;
	rpt(i,1,n) rpt(j,1,n){
		int l=ref[i-1][j],r=ref[i][j-1];
		int h=res(1,cnt,l,r-1,1);
		if(h<a[i][j]) ans+=a[i][j]-h;
		modif(1,cnt,l,r-1,a[i][j],1);
	}
	printf("%I64d",ans);
}