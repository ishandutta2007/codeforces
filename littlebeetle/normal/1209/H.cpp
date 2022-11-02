#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=400005;
const double eps=1e-10,Inf=1e12;
int m,n,L,i,x,lst,a,b;
int id[N];
long double s[N],v[N],V,Up[N],Down[N],S[N],lz[N<<2],Max[N<<2],k,ans;
double p;
long double max(long double x,long double y){
	return x>y?x:y;
}
long double min(long double x,long double y){
	return x<y?x:y;
}
void Pushup(int rt){
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
void Build(int rt,int l,int r){
	if(l==r){
		Max[rt]=S[l];
		return;
	}
	int mid=l+r>>1;
	Build(rt<<1,l,mid);
	Build(rt<<1|1,mid+1,r);
	Pushup(rt);
}
void init(){
	scanf("%d%d",&m,&L);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		cin>>V;
		s[++n]=a-lst;
		v[n]=1;
		s[++n]=b-a;
		v[n]=V+1;
		lst=b;
	}
	s[++n]=L-lst;
	v[n]=1;
	for(i=1;i<=n;i++){
		id[i]=i;
		Up[i]=s[i]/(v[i]+1);
		if(v[i]<1+eps)
			Down[i]=(s[i]+1)*11;
		else
			Down[i]=s[i]/(v[i]-1);
		S[i]=S[i-1]-Down[i];
		s[i]+=Down[i];
	}
}
bool cmp(int x,int y){
	return v[x]<v[y];
}
void Change(int rt,long double val){
	lz[rt]+=val;
	Max[rt]+=val;
}
void Pushdown(int rt){
	if(lz[rt]>eps){
		Change(rt<<1,lz[rt]);
		Change(rt<<1|1,lz[rt]);
		lz[rt]=0;
	}
}
long double Query(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return Max[rt];
	Pushdown(rt);
	long double s=-Inf;
	int mid=l+r>>1;
	if(x<=mid)s=max(s,Query(rt<<1,l,mid,x,y));
	if(y>mid)s=max(s,Query(rt<<1|1,mid+1,r,x,y));
	return s;
}
void Update(int rt,int l,int r,int x,int y,long double z){
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
	Build(1,1,n);
	sort(id+1,id+n+1,cmp);
	for(i=1;i<=n;i++){
		x=id[i];
		k=min(-Query(1,1,n,x,n),Up[x]+Down[x]);
		ans+=(s[x]-k)/v[x];
		Update(1,1,n,x,n,k);
	}
	p=ans;
	printf("%.12lf",p);
}
int main(){
	init();
	work();
	return 0;
}