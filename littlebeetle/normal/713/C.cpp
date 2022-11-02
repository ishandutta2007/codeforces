#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3003;
int n,a[N],b[N],i,j;
long long f[N][N],k;
int abs(int x){
	return x>0?x:-x;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),a[i]-=i,b[i]=a[i];
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++){
		k=1ll<<59;
		for(j=1;j<=n;j++){
			k=min(k,f[i-1][j]);
			f[i][j]=k+abs(a[i]-b[j]);
		}
	}
	k=1ll<<59;
	for(i=1;i<=n;i++)
		k=min(k,f[n][i]);
	printf("%I64d",k);
}