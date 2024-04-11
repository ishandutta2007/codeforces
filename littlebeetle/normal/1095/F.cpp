#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=400002;
struct p{
	int x,y;
	ll z;
	bool operator<(const p &k)const{
		return k.z>z;
	}
}f[N];
int n,m,i,k,fa[N],u,v;
ll a[N],ans;
int P(int x){
	return x==fa[x]?x:fa[x]=P(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	a[0]=1ll<<60;
	for(i=1;i<=n;i++)
		scanf("%I64d",a+i);
	for(i=1;i<=m;i++)
		scanf("%d%d%I64d",&f[i].x,&f[i].y,&f[i].z);
	for(i=1;i<=n;i++)
		if(a[i]<a[k])
			k=i;
	for(i=1;i<=n;i++)
		if(i!=k)
			f[++m]=(p){i,k,a[i]+a[k]};
	sort(f+1,f+m+1);
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=m;i++){
		u=f[i].x;
		v=f[i].y;
		if(P(u)!=P(v))
			ans+=f[i].z,
			fa[P(u)]=v;
	}
	printf("%I64d",ans);
}