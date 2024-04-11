#include<cstdio>
#include<algorithm>
using namespace std;

long long a[100001];
long long mx[21][100001],mn[21][100001],lg[100001];
long long qu(int l,int r,int o){
	int g=lg[r-l+1];
	return o?max(mx[g][l],mx[g][r-(1<<g)+1]):
		min(mn[g][l],mn[g][r-(1<<g)+1]);
}
int main(){
	for(int i=2;i<=100000;i++)
		lg[i]=lg[i>>1]+1;
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		a[i]+=o;
	}
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		a[i]-=o;
	}
	for(int i=2;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=0;i<=20;i++)
		for(int j=1;j<=n;j++)
			if(i==0)mx[i][j]=mn[i][j]=a[j];
			else mx[i][j]=max(mx[i-1][j],mx[i-1][min(n,j+(1<<i-1))]),
				mn[i][j]=min(mn[i-1][j],mn[i-1][min(n,j+(1<<i-1))]);
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		if(a[r]!=a[l-1]||qu(l,r,1)>a[l-1])printf("-1\n");
		else printf("%lld\n",a[l-1]-qu(l,r,0));
	}
}