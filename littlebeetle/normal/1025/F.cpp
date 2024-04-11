#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2002;
const double Pi=acos(-1);
long long ans;
int n,m,i,j,g,x[N],y[N];
double p[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	for(i=1;i<=n;i++){
		m=0;
		for(j=1;j<=n;j++)
			if(i!=j)
				p[++m]=atan2(y[j]-y[i],x[j]-x[i]);
		sort(p+1,p+m+1);
		for(j=1,g=0;j<=m&&p[j]<=0;j++){
			while(g<m&&p[g+1]-p[j]<Pi)g++;
			ans+=1ll*(g-j)*(g-j-1)/2*(m-g+j-1)*(m-g+j-2)/2;
		}
	}
	printf("%lld",ans);
}