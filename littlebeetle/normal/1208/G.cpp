#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000020;
int n,m,i,j,k,a[N],phi[N];
long long ans;
bool f[N];
int main(){
	scanf("%d%d",&n,&m);
	phi[1]=1;
	for(i=2;i<=n;i++){
		if(!f[i])a[k++]=i,phi[i]=i-1;
		for(j=0;(!j||i%a[j-1])&&i*a[j]<=n;j++){
			f[i*a[j]]=1;
			phi[i*a[j]]=phi[i]*(i%a[j]?a[j]-1:a[j]);
		}
	}
	sort(phi+1,phi+n+1);
	for(i=1;i<=m+2;i++)
		ans+=phi[i];
	printf("%lld",ans-(m==1));
	//while(1);
}