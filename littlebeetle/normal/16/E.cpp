#include<cstdio>
const int N=18;
int n,i,j,u,v,cnt[1<<N];
double f[1<<N],a[N][N];
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%lf",a[i]+j);
	f[(1<<n)-1]=1;
	for(i=1;i<(1<<n);i++)
		cnt[i]=cnt[i>>1]+(i&1);
	for(i=(1<<n)-1;i;i--)
		if(i!=(i&-i)){
			for(u=0;u<n;u++)
				for(v=u+1;v<n;v++)
					if((i>>u&1)&&(i>>v&1))
						f[i^(1<<u)]+=f[i]*a[v][u]*2/cnt[i]/(cnt[i]-1),
						f[i^(1<<v)]+=f[i]*a[u][v]*2/cnt[i]/(cnt[i]-1);
		}
	for(i=0;i<n;i++)
	printf("%.6lf ",f[1<<i]);
}