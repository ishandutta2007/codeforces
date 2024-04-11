#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int n,m,a[MAXN];
bool nop[MAXN];
int prm[MAXN];
ll ans;
int f[MAXN][2];
int main(){
	n=1e6;
	for(int i=2; i<=n; i++){
		if(!nop[i]) prm[++*prm]=i;
		for(int j=1; j<=*prm&&prm[j]*i<=n; j++){
			nop[prm[j]*i]=1;
			if(i%prm[j]==0) break;
		}
	}
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=m; i++)
			f[n+i][0]=f[n+i][1]=0;
		ans=0;
		for(int i=n; i; i--){
			f[i][0]=f[i][1]=0;
			if(a[i]==1){
				f[i][0]=f[i+m][0]+1;
				f[i][1]=f[i+m][1];
			}else if(!nop[a[i]]) f[i][1]=f[i+m][0]+1,ans--;
			ans+=f[i][1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}