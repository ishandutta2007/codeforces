#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int a[2001],s[2001],c[4001];
vector<int>f[2001][4001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=n+m;i++)
		scanf("%d",&c[i]);
	f[n][0].push_back(0);
	for(int i=n;i;i--)
		for(int j=0;j<=m+n;j++)
			for(int k=0;k<f[i][j].size();k++){
				while((int)f[i-1][j].size()-1<k)
					f[i-1][j].push_back(-2e9);
				f[i-1][j][k]=max(f[i-1][j][k],f[i][j][k]);
				//printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
				if(a[i]>=j){
					int z=0,kk=k;
					for(int w=j;w<a[i];w++){
						z+=kk*c[w];
						kk/=2;
						if(kk==0)break;
					}
					kk++;
					while((int)f[i-1][a[i]].size()-1<kk)
						f[i-1][a[i]].push_back(-2e9);
					f[i-1][a[i]][kk]=max(f[i-1][a[i]][kk],f[i][j][k]+z-s[i]);
				}
			}
	int ans=-2e9;
	for(int j=0;j<=n+m;j++)
		for(int k=0;k<f[0][j].size();k++){
			int z=0,kk=k;
			for(int w=j;;w++){
				z+=kk*c[w];
				kk/=2;
				if(kk==0)break;
			}
			ans=max(ans,f[0][j][k]+z);
		}
	printf("%d\n",ans);
}