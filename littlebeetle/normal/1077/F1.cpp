#include<cstdio>
#include<cstring>
using namespace std;
const int N=202;
typedef long long ll;
int n,k,x,i,j,l,a[N];
ll f[N][N],ans=-1;
ll max(ll x,ll y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d%d",&n,&k,&x);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	memset(f,-10,sizeof(f));
	f[0][0]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=x;j++)
			for(l=i-1;l>=0&&i-l<=k;l--)
				f[i][j]=max(f[i][j],f[l][j-1]+a[i]);
		if(n-i<k)
			ans=max(ans,f[i][x]);
	}
	printf("%I64d",ans);
}