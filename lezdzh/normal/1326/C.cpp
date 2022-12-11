#include<cstdio>
#include<algorithm>
using namespace std;

int a[200001],p[200001],c[200001];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}
	long long ans=0;
	int anst=1;
	for(int i=n-k+1;i<=n;i++){
		c[++c[0]]=p[i];
		ans+=i;
	}
	sort(c+1,c+c[0]+1);
	for(int i=1;i<c[0];i++)
		anst=1ll*anst*(c[i+1]-c[i])%998244353;
	printf("%lld %d\n",ans,anst);
}