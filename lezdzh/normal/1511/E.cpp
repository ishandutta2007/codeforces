#include<cstdio>
#include<vector>
using namespace std;

const int md=998244353;
vector<int>g[300001];
int pw2[300001],f[300001];
int main(){
	for(int i=pw2[0]=1;i<=300000;i++)
		pw2[i]=pw2[i-1]*2%md;
	f[0]=f[1]=0;
	for(int i=2;i<=300000;i++)
		f[i]=(1ll*f[i-2]+f[i-1]+f[i-2]+pw2[i-2])%md;
	int n,m;
	scanf("%d%d",&n,&m);
	int sum=0;
	for(int i=1;i<=n;i++){
		char c;
		g[i].push_back(0);
		for(int j=1;j<=m;j++){
			scanf(" %c",&c);
			if(c=='*')g[i].push_back(0);
			else g[i].push_back(1),sum++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;){
			int k=j;
			while(k<=m&&g[i][k]==1)k++;
			ans=(ans+1ll*f[k-j]*pw2[sum-(k-j)])%md;
			j=k+1;
		}
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;){
			int k=i;
			while(k<=n&&g[k][j]==1)k++;
			ans=(ans+1ll*f[k-i]*pw2[sum-(k-i)])%md;
			i=k+1;
		}
	printf("%d\n",ans);
}