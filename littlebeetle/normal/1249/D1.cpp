#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200002;
struct Uzi{
	int l,r,id;
	bool operator<(const Uzi &k)const{
		return k.l>l;
	}
}a[N];
struct Shy{
	int l,r,id;
	bool operator<(const Shy &k)const{
		return k.r>r;
	}
}x;
priority_queue<Shy>Q;
int n,k,i,j,Ans[N],cnt;
int Max[N*4],tag[N*4];
void init(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;
	sort(a+1,a+n+1);
}
void Change(int rt,int val){
	tag[rt]+=val;
	Max[rt]+=val;
}
void Pushdown(int rt){
	if(tag[rt]){
		Change(rt<<1,tag[rt]);
		Change(rt<<1|1,tag[rt]);
		tag[rt]=0;
	}
}
void Pushup(int rt){
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
void Update(int rt,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y){
		Change(rt,z);
		return;
	}
	Pushdown(rt);
	int mid=l+r>>1;
	if(x<=mid)Update(rt<<1,l,mid,x,y,z);
	if(y>mid)Update(rt<<1|1,mid+1,r,x,y,z);
	Pushup(rt);
}
void work(){
	for(i=j=1;i<N;i++){
		while(j<=n&&a[j].l<=i){
			Update(1,1,N,a[j].l,a[j].r,1);
			x=(Shy){a[j].l,a[j].r,a[j].id};
			Q.push(x);
			j++;
		}
		while(Max[1]>k){
			x=Q.top();
			Q.pop();
			Update(1,1,N,x.l,x.r,-1);
			Ans[++cnt]=x.id;			
		}
	}
	sort(Ans+1,Ans+cnt+1);
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++)
		printf("%d ",Ans[i]);
}
int main(){
	init();
	work();
	return 0;
}