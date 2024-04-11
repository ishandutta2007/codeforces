#include<cstdio>
#include<algorithm>
using namespace std;
const int N=502;
int a[N][N],b[N][N],i,j,k,n,m,cnt;
int c[N],d[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",a[i]+j);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",b[i]+j);
	for(k=2;k<=n+m;k++){
		cnt=0;
		for(i=1;i<k&i<=n;i++){
			j=k-i;
			if(j>=1&&j<=m){
				cnt++;
				c[cnt]=a[i][j];
				d[cnt]=b[i][j];
			}
		}
		sort(c+1,c+cnt+1);
		sort(d+1,d+cnt+1);
		for(i=1;i<=cnt;i++)
			if(c[i]!=d[i]){
				printf("NO");
				return 0;
			}
	}
	printf("YES");
}