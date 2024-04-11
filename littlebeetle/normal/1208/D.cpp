#include<cstdio>
const int N=800002;
typedef long long ll;
int n,i,y,a[N];
ll s[N],lz[N],x;
void Pushdown(int rt){
	if(lz[rt]){
		lz[rt<<1]+=lz[rt];
		lz[rt<<1|1]+=lz[rt];
		s[rt<<1]+=lz[rt];
		s[rt<<1|1]+=lz[rt];
		lz[rt]=0;
	}
}
ll min(ll x,ll y){
	return x<y?x:y;
}
void Update(int rt,int l,int r,int x,int y,ll z){
	if(x<=l&&r<=y){
		s[rt]+=z;
		lz[rt]+=z;
		return;
	}
	Pushdown(rt);
	int mid=l+r>>1;
	if(x<=mid)Update(rt<<1,l,mid,x,y,z);
	if(y>mid)Update(rt<<1|1,mid+1,r,x,y,z);
	s[rt]=min(s[rt<<1],s[rt<<1|1]);
}
int Query(int rt,int l,int r){
	if(l==r)return l;
	Pushdown(rt);
	int mid=l+r>>1;
	if(s[rt<<1|1]==0)return Query(rt<<1|1,mid+1,r);
	return Query(rt<<1,l,mid);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&x);
		Update(1,1,n,i,i,x);
	}
	i=n;
	while(i--){
		x=Query(1,1,n);
		///printf("%d\n",x);
		a[x]=++y;
		if(x!=n)
			Update(1,1,n,x+1,n,-y);
		Update(1,1,n,x,x,1ll<<60);
	}
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
}