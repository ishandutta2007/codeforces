#include<cstdio>
#include<algorithm>
using namespace std;

int a[2001],b[2001],c[2001],d[2001];
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		c[i]=2e9;
	for(int i=1;i<=m;i++)
		d[i]=2e9;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
		for(int j=0;j<i;j++)
			c[i-j]=min(c[i-j],a[i]-a[j]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		b[i]+=b[i-1];
		for(int j=0;j<i;j++)
			d[i-j]=min(d[i-j],b[i]-b[j]);
	}
	scanf("%d",&x);
	int ans=0;
	for(int i=1,j=m;i<=n;i++){
		while(1ll*c[i]*d[j]>x)j--;
		ans=max(ans,i*j);
	}
	printf("%d\n",ans);
}