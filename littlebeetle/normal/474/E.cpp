//Pillars
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
typedef long long ll;
int n,d,m,D,i,p[N],f[N],t[N*2],pre[N];
int x,y,z,ans;
ll h[N],a[N];
bool cmp(int x,int y){
	return h[x]<h[y];
}
void init(){
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++)
		scanf("%lld",h+i),p[i]=i;
	sort(p+1,p+n+1,cmp);
	a[++m]=-(1ll<<60);
	for(i=1;i<=n;i++)
		if(h[p[i]]!=a[m])
			a[++m]=h[p[i]];
	a[++m]=1ll<<60;
	for(D=1;D<m+2;D<<=1);
}
int max(int x,int y){
	return f[x]>f[y]?x:y;
}
int leq(ll x){
	int l=1,r=m,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(a[mid]<=x)
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
int geq(ll x){
	int l=1,r=m,mid;
	while(l<r){
		mid=l+r>>1;
		if(a[mid]>=x)
			r=mid;
		else
			l=mid+1;
	}
	return r;
}
int Query(int x,int y){
	int s=0;
	for(x+=D-1,y+=D+1;x^y^1;x>>=1,y>>=1){
		if(~x&1)s=max(s,t[x^1]);
		if(  y&1)s=max(s,t[y^1]);
	}
	return s;
}
void Update(int x,int y){
	x+=D;
	t[x]=max(t[x],y);
	while(x>>=1)
		t[x]=max(t[x<<1],t[x<<1|1]);
}
void out(int x){
	if(x==0)return;
	out(pre[x]);
	printf("%d ",x);
}
void work(){
	for(i=1;i<=n;i++){
		z=leq(h[i]-d);
		y=geq(h[i]+d);
		x=leq(h[i]);
		pre[i]=max(Query(1,z),Query(y,m));
		f[i]=f[pre[i]]+1;
		ans=ans>f[i]?ans:f[i];
		Update(x,i);
	}
	printf("%d\n",ans);
	for(i=n;i;i--)
		if(f[i]==ans){
			out(i);
			break;
		}
	//while(1);
}
int main(){
	init();
	work();
	return 0;
}