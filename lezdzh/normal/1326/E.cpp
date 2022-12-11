#include<cstdio>
#include<algorithm>
using namespace std;

struct dn{int l,r,ls,rs,f,c;}tr[600001];
int t;
int nw(int l,int r){
	tr[++t]=(dn){l,r,0,0,0,0};
	return t;
}
void build(int o){
	if(tr[o].l==tr[o].r)return;
	int mid=tr[o].l+tr[o].r>>1;
	build(tr[o].ls=nw(tr[o].l,mid));
	build(tr[o].rs=nw(mid+1,tr[o].r));
}
void xf(int o){
	if(tr[o].f){
		tr[o].c+=tr[o].f;
		tr[tr[o].ls].f+=tr[o].f;
		tr[tr[o].rs].f+=tr[o].f;
		tr[o].f=0;
	}
}
void xg(int o,int l,int r,int c){
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
	tr[o].c=min(tr[tr[o].ls].c,tr[tr[o].rs].c);
}
int cx(int o,int l,int r){
	xf(o);
	if(tr[o].l==l&&tr[o].r==r)
		return tr[o].c;
	int mid=tr[o].l+tr[o].r>>1;
	if(r<=mid)return cx(tr[o].ls,l,r);
	else if(l>mid)return cx(tr[o].rs,l,r);
	else return min(cx(tr[o].ls,l,mid),cx(tr[o].rs,mid+1,r));
}
int p[300001],q[300001],pp[300001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		pp[p[i]]=i;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&q[i]);
	build(nw(0,n));
	int ans=n;
	for(int i=1;i<=n;i++){
//		for(int i=1;i<=n;i++)
//			printf("%d ",cx(1,i,i));
//		printf("\n");
		for(;;){
			int w=cx(1,0,pp[ans]-1),z=cx(1,pp[ans],n);
			if(z<w){
				xg(1,pp[ans],n,1);
				ans--;
			}
			else break;
		}
		printf("%d%c",ans,i==n?'\n':' ');
		xg(1,q[i],n,-1);
	}
}