#include<cstdio>
#include<algorithm>
using namespace std;

char s[500001];
struct nd{int l,r,ls,rs,s,c,z,l1,l2,r1,r2;}tr[500001];
int tt;
int nw(int l,int r){
	tr[++tt]=(nd){l,r};
	return tt;
}
void hb(int o){
	int ls=tr[o].ls,rs=tr[o].rs;
	tr[o].s=tr[ls].s+tr[rs].s;
	tr[o].c=max(max(tr[ls].c,tr[rs].c),max(tr[ls].r1+tr[rs].l2,tr[ls].r2+tr[rs].l1));
	tr[o].z=max(tr[ls].z+tr[rs].s,-tr[ls].s+tr[rs].z);
	tr[o].l2=max(tr[ls].l2,max(tr[ls].z+tr[rs].l1,-tr[ls].s+tr[rs].l2));
	tr[o].l1=max(tr[ls].l1,tr[ls].s+tr[rs].l1);
	tr[o].r2=max(tr[rs].r2,max(tr[rs].z+tr[ls].r1,tr[rs].s+tr[ls].r2));
	tr[o].r1=max(tr[rs].r1,-tr[rs].s+tr[ls].r1);
}
void build(int o){
	if(tr[o].l==tr[o].r){
		int w=s[tr[o].l]=='('?1:-1;
		tr[o]=(nd){tr[o].l,tr[o].r,0,0,w,1,1,max(0,w),1,max(0,-w),1};
		return;
	}
	int mid=tr[o].l+tr[o].r>>1;
	build(tr[o].ls=nw(tr[o].l,mid));
	build(tr[o].rs=nw(mid+1,tr[o].r));
	hb(o);
}
void xg(int o,int p){
	if(tr[o].l==tr[o].r){
		int w=s[tr[o].l]=='('?1:-1;
		tr[o]=(nd){tr[o].l,tr[o].r,0,0,w,1,1,max(0,w),1,max(0,-w),1};
		return;
	}
	int mid=tr[o].l+tr[o].r>>1;
	if(p<=mid)xg(tr[o].ls,p);
	else xg(tr[o].rs,p);
	hb(o);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	nw(1,2*(n-1));
	build(1);
	printf("%d\n",tr[1].c);
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		swap(s[l],s[r]);
		xg(1,l);
		xg(1,r);
		printf("%d\n",tr[1].c);
	}
}