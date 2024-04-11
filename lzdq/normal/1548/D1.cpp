#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,x[MAXN],y[MAXN];
int cnt[2][2][2];
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d",x+i,y+i);
		x[i]>>=1,y[i]>>=1;
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++)
				cnt[j][k][j*x[i]+k*y[i]&1]++;
	}
	//for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++) printf("%d %d %d cnt %d\n",i,j,k,cnt[i][j][k]);
	for(int i=1; i<=n; i++)
		for(int j=1; j<i; j++){
			int a=y[i]+y[j]&1,b=x[i]+x[j]&1;
			//printf("%d %d a %d b %d %lld\n",i,j,a,b,1ll*x[i]*y[j]+1ll*x[j]*y[i]-1&1);
			ans+=cnt[a][b][1ll*x[i]*y[j]+1ll*x[j]*y[i]&1]-2;
		}
	printf("%lld\n",ans/3);
	return 0;
}