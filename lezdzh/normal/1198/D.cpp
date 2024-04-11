#include<cstdio>
#include<algorithm>
using namespace std;

char s[52];
int a[51][51];
int f[51][51][51][51];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(s[j]=='#');
	}
	for(int p=1;p<=n;p++)
		for(int q=1;q<=n;q++)
			for(int i=1;i+p-1<=n;i++)
				for(int j=1;j+q-1<=n;j++){
					if(a[i+p-1][j+q-1]+a[i-1][j-1]-a[i-1][j+q-1]-a[i+p-1][j-1]==0){
						f[p][q][i][j]=0;
						continue;
					}
					f[p][q][i][j]=max(p,q);
					for(int ii=i+1;ii<=i+p-1;ii++)
						f[p][q][i][j]=min(f[p][q][i][j],f[ii-i][q][i][j]+f[p-ii+i][q][ii][j]);
					for(int jj=j+1;jj<=j+q-1;jj++)
						f[p][q][i][j]=min(f[p][q][i][j],f[p][jj-j][i][j]+f[p][q-jj+j][i][jj]);
					//printf("%d %d %d %d %d\n",p,q,i,j,f[p][q][i][j]);
				}
	printf("%d\n",f[n][n][1][1]);
}