#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2003;
typedef long long ll;
int n,i,j,k,c[N],p[N],x[N],y[N],pre[N];
int l[N],r[N],cnt;
ll e[N][N],dis[N],Ans;
bool usd[N];
int abs(int x){
	return x>0?x:-x;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	for(i=1;i<=n;i++)
		scanf("%d",c+i);
	for(i=1;i<=n;i++)
		scanf("%d",p+i);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)
				e[i][j]=1ll*(p[i]+p[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
	n++;
	for(i=1;i<n;i++)
		e[i][n]=e[n][i]=c[i];
}
void prim(){
	for(i=0;i<=n;i++)
		dis[i]=1ll<<60;
	dis[1]=0;
	for(i=1;i<=n;i++){
		k=0;
		for(j=1;j<=n;j++)
			if(!usd[j]&&dis[j]<dis[k])
				k=j;
		l[i]=k;r[i]=pre[k];
		Ans+=dis[k];
		usd[k]=1;
		for(j=1;j<=n;j++)
			if(e[j][k]<dis[j]){
				dis[j]=e[j][k];
				pre[j]=k;
			}
	}
	printf("%lld\n",Ans);
	for(i=2;i<=n;i++)
		if(l[i]==n||r[i]==n)
			cnt++;
	printf("%d\n",cnt);
	for(i=2;i<=n;i++)
		if(l[i]==n||r[i]==n)
			printf("%d ",l[i]+r[i]-n);
	printf("\n%d\n",n-1-cnt);
	for(i=2;i<=n;i++)
		if(l[i]!=n&&r[i]!=n)
			printf("%d %d\n",l[i],r[i]);
}
int main(){
	init();
	prim();
	return 0;
}