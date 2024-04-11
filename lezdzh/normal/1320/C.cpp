#include<cstdio>
#include<algorithm>
using namespace std;

struct dd{int x,c;}b[200001];
struct dn{int x,k,y,c;}d[400001];
bool operator<(dd u,dd v){
	return u.x!=v.x?u.x<v.x:u.c<v.c;
}
bool operator<(dn u,dn v){
	return u.x!=v.x?u.x<v.x:u.k<v.k;
}
struct td{int l,r,ls,rs;long long c,f;}tr[400001];
int tt;
int nw(int l,int r){
	tr[++tt]=(td){l,r,0,0,0,0};
	return tt;
}
void build(int o,int l,int r){
	if(l==r)return;
	int mid=l+r>>1;
	build(tr[o].ls=nw(l,mid),l,mid);
	build(tr[o].rs=nw(mid+1,r),mid+1,r);
}
void xf(int o){
	if(tr[o].f){
		tr[o].c+=tr[o].f;
		tr[tr[o].ls].f+=tr[o].f;
		tr[tr[o].rs].f+=tr[o].f;
		tr[o].f=0;
	}
}
void xg(int o,int l,int r,long long c){
	xf(o);
	if(tr[o].l==l&&tr[o].r==r){
		tr[o].f+=c;
		return;
	}
	int mid=tr[o].l+tr[o].r>>1;
	if(r<=mid)xg(tr[o].ls,l,r,c);
	else if(l>mid)xg(tr[o].rs,l,r,c);
	else xg(tr[o].ls,l,mid,c),xg(tr[o].rs,mid+1,r,c);
	xf(tr[o].ls);xf(tr[o].rs);
	tr[o].c=max(tr[tr[o].ls].c,tr[tr[o].rs].c);
}
int main(){
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&d[i].x,&d[i].c);
		d[i].k=0;
	}
	for(int i=1;i<=m;i++)
		scanf("%d%d",&b[i].x,&b[i].c);
	for(int i=1;i<=p;i++){
		scanf("%d%d%d",&d[i+n].x,&d[i+n].y,&d[i+n].c);
		d[i+n].k=1;
	}
	n+=p;
	sort(d+1,d+n+1);
	sort(b+1,b+m+1);
	build(nw(1,m),1,m);
	for(int i=1;i<=m;i++)
		xg(1,i,i,-b[i].c);
	long long ans=-(long long)(~0ull>>1);
	for(int i=1;i<=n;i++)
		if(d[i].k==1){
			int w=upper_bound(b+1,b+m+1,(dd){d[i].y,(int)2e9})-b;
			if(w<=m)xg(1,w,m,d[i].c);
		}
		else{
			xf(1);
			ans=max(ans,tr[1].c-d[i].c);
		}
	printf("%lld\n",ans);
}