#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2000002;
typedef long long ll;
struct skt{
	int l,r,id;
	bool operator<(const skt &k)const{
		return k.r>r;
	}
}a[N];
int n,q,p[N*10],blk,i,j,k,L,R;
int q1[N],s1,q2[N],s2,Min[N],Cnt[N],lz1[N],lz2[N],tmp=1,S;
ll Sum[N],Ans[N];
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",p+i);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
		scanf("%d%d",&a[i].l,&a[i].r),
		a[i].id=i;
	sort(a+1,a+q+1);
}
void Change1(int rt,int val){
	lz1[rt]+=val;
	Min[rt]+=val;
}
void Change2(int rt,int val){
	lz2[rt]+=val;
	Sum[rt]+=1ll*val*Cnt[rt];
}
void Pushdown(int rt){
	if(lz1[rt]){
		Change1(rt<<1,lz1[rt]);
		Change1(rt<<1|1,lz1[rt]);
		lz1[rt]=0;
	}
	if(lz2[rt]){
		if(Min[rt]==Min[rt<<1])Change2(rt<<1,lz2[rt]);
		if(Min[rt]==Min[rt<<1|1])Change2(rt<<1|1,lz2[rt]);
		lz2[rt]=0;
	}
}
void Pushup(int rt){
	Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];
	if(Min[rt<<1]==Min[rt<<1|1]){
		Min[rt]=Min[rt<<1];
		Cnt[rt]=Cnt[rt<<1]+Cnt[rt<<1|1];
		return;
	}
	if(Min[rt<<1]<Min[rt<<1|1]){
		Min[rt]=Min[rt<<1];
		Cnt[rt]=Cnt[rt<<1];
	}
	else{
		Min[rt]=Min[rt<<1|1];
		Cnt[rt]=Cnt[rt<<1|1];		
	}
}
void Build(int rt,int l,int r){
	if(l==r){
		Min[rt]=l;	
		Cnt[rt]=1;
		return;
	}
	int mid=l+r>>1;
	Build(rt<<1,l,mid);
	Build(rt<<1|1,mid+1,r);
	Pushup(rt);
}
void Update(int rt,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y){
		Change1(rt,z);
		return;
	}
	Pushdown(rt);
	int mid=l+r>>1;
	if(x<=mid)Update(rt<<1,l,mid,x,y,z);
	if(y>mid)Update(rt<<1|1,mid+1,r,x,y,z);
	Pushup(rt);
}
ll Query(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return Sum[rt];
	Pushdown(rt);
	int mid=l+r>>1;
	ll s=0;
	if(x<=mid)s+=Query(rt<<1,l,mid,x,y);
	if(y>mid)s+=Query(rt<<1|1,mid+1,r,x,y);
	return s;
}
void work(){
	Build(1,1,n);
	for(i=1,j=1;i<=n;i++){
		while(s1&&p[q1[s1]]<p[i]){
			Update(1,1,n,q1[s1-1]+1,q1[s1],-p[q1[s1]]);
			s1--;
		}
		q1[++s1]=i;
		Update(1,1,n,q1[s1-1]+1,q1[s1],p[q1[s1]]);
		while(s2&&p[q2[s2]]>p[i]){
			Update(1,1,n,q2[s2-1]+1,q2[s2],p[q2[s2]]);
			s2--;
		}
		q2[++s2]=i;
		Update(1,1,n,q2[s2-1]+1,q2[s2],-p[q2[s2]]);
		Change2(1,1);
		while(j<=q&&a[j].r==i)
			Ans[a[j].id]=Query(1,1,n,a[j].l,a[j].r),j++;
	}
	for(i=1;i<=q;i++)
		printf("%lld\n",Ans[i]);
}
int main(){
	init();
	work();
	return 0;
}