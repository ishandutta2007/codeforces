#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500030,M=1000000007;
typedef long long ll;
struct edg{
	int l,r;
	long long val;
	bool operator<(const edg &k)const{
		return k.val>val;
	}
}a[N];
int n,p,m,nn,i,j,k,fa[N],u,v;
long long c[N],cnt,ans;
int F(int x){
	return x==fa[x]?x:fa[x]=F(fa[x]);
}
void init(){
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n;i++)
		scanf("%lld",c+i);
	cnt=1ll<<p;
	for(i=1;i<=m;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].val=c[a[i].l]^c[a[i].r];
	}
	sort(a+1,a+m+1);
}
ll ksm(int p){
	ll s=1,x=2;
	while(p){
		if(p%2)
			s=s*x%M;
		p/=2;
		x=x*x%M;
	}
	return s;
}
void work(){
	for(i=1;i<=m;i++){
		for(j=i;a[j+1].val==a[j].val&&j<m;j++);
		for(k=i;k<=j;k++){
			fa[a[k].l]=a[k].l;
			fa[a[k].r]=a[k].r;
		}
		nn=n;
		for(k=i;k<=j;k++){
			u=a[k].l;
			v=a[k].r;
			//printf("   %d %d %d %d\n",u,v,fa[u],fa[v]);

			u=F(u);
			v=F(v);
			//printf("   %d %d %d %d\n",u,v,a[k].l,a[k].r);
			if(u!=v)
				fa[u]=v,nn--;
		}
		cnt--;
		ans=(ans+ksm(nn))%M;
		for(k=i;k<=j;k++){
			fa[a[k].l]=0;
			fa[a[k].r]=0;
		}		
		i=j;
		//printf("%d\n",nn);
	}
	cnt%=M;
	ans=(ans+cnt*ksm(n))%M;
	printf("%lld",ans);
	//while(1);
}
int main(){
	init();
	work();
}