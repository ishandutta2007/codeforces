#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500002;
typedef long long ll;
struct Uzi{
	int x,y,c,yy;
	bool operator<(const Uzi &k)const{
		return k.x>x;
	}
}a[N];
int n,i,d[N],c[N],R,k,aa=1e9+1,bb=1e9+1,Y[N];
ll t[N*4],lz[N*4],ans=0;
ll max(ll x,ll y){
	return x>y?x:y;
}
bool cmp(int u,int v){
	return a[u].y<a[v].y;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
		if(a[i].x<a[i].y)
			swap(a[i].x,a[i].y);
		d[i]=i;
	}
	a[0].y=-1;
	sort(a+1,a+n+1);
	sort(d+1,d+n+1,cmp);
	for(i=1;i<=n;i++){
		a[d[i]].yy=a[d[i-1]].yy+(a[d[i]].y!=a[d[i-1]].y),
		c[a[d[i]].yy]=a[d[i]].y;
	}
	k=a[d[n]].yy;
	//for(i=1;i<=n;i++)
	//	printf("%d %d %d %d\n",a[i].x,a[i].y,a[i].yy,a[i].c);
}
void Pushup(int rt){
	t[rt]=max(t[rt<<1],t[rt<<1|1]);
}
void Build(int rt,int l,int r){
	if(l==r){
		t[rt]=-(1ll<<50);
		return;
	}
	int mid=l+r>>1;
	Build(rt<<1,l,mid);
	Build(rt<<1|1,mid+1,r);
	Pushup(rt);
}
void Change(int rt,ll z){
	lz[rt]+=z;
	t[rt]+=z;
}
void Pushdown(int rt){
	if(lz[rt]){
		Change(rt<<1,lz[rt]);
		Change(rt<<1|1,lz[rt]);
		lz[rt]=0;
	}
}
void Update(int rt,int l,int r,int x,int y,ll z){
	if(x<=l&&r<=y){
		Change(rt,z);
		return;
	}
	Pushdown(rt);
	int mid=l+r>>1;
	if(x<=mid)
		Update(rt<<1,l,mid,x,y,z);
	if(y>mid)
		Update(rt<<1|1,mid+1,r,x,y,z);
	Pushup(rt);
}
void Query(int rt,int l,int r){
	if(l==r){
		aa=c[l];
		return;
	}
	int mid=l+r>>1;
	Pushdown(rt);
	if(t[rt<<1]>t[rt<<1|1])
		Query(rt<<1,l,mid);
	else
		Query(rt<<1|1,mid+1,r);
}
void work(){
	R=0;
	//for(i=1;i<=n;i++)
	//	printf("%d\n",c[i]);
	for(i=1;i<=n;i++){
		Update(1,1,n,1,a[i].yy,a[i].c);
		while(R<k&&c[R+1]<=a[i].x){
			R++;
			//printf("   %d %d\n",R,c[R]);
			Update(1,1,n,R,R,(1ll<<50)+c[R]);
		}
		//printf("%lld\n",t[1]);
		if(a[i].x!=a[i+1].x){
			if(t[1]-a[i].x>ans){
				ans=max(ans,t[1]-a[i].x);
				bb=a[i].x;
				Query(1,1,n);
			}
		}
	}
	printf("%lld\n%d %d %d %d",ans,aa,aa,bb,bb);
}
int main(){
	init();
	Build(1,1,n);
	work();
	return 0;
}