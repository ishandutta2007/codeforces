#include<cstdio>

using namespace std;

int a[101][101],b[101][101];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		long long sum=0;
		for(int i=1;i<=m;i++){
			int ans=2e9,p,q;
			for(int j=1;j<=n;j++)
				for(int k=1;k<=m;k++)
					if(a[j][k]<ans){
						ans=a[j][k];
						p=j,q=k;
					}
			sum+=ans;
			b[p][i]=a[p][q];
			a[p][q]=2e9;
			for(int j=1;j<=n;j++)
				if(j!=p){
					int mx=0;
					for(int k=1;k<=m;k++)
						if(a[j][k]!=2e9&&(mx==0||a[j][k]>a[j][mx]))
							mx=k;
					b[j][i]=a[j][mx];
					a[j][mx]=2e9;
				}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				printf("%d%c",b[i][j],j==m?'\n':' ');
	}
}