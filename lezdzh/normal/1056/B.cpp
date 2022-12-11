#include<cstdio>

using namespace std;

int main(){
	int n,m;
	long long ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			if((i*i+j*j)%m==0)
				ans+=1ll*((i<=n%m)+n/m-!i)*((j<=n%m)+n/m-!j);
	printf("%I64d\n",ans);
}