#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=205;
int n,m,k;
int a[MAXN],b[MAXN],c[MAXN],_a[MAXN];
ll f[MAXN][MAXN],ans;
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++)
		scanf("%d%d%d",a+i,b+i,c+i);
	memcpy(_a,a,sizeof(a));
	while(n&&a[n]+1ll*b[n]*m<=c[n]) n--;
	if(!n) return puts("0"),0;
	int _n=n;
	memset(f,0x3f,sizeof(f));
	ans=f[0][0];
	ll cnt;
	for(int i=0; i<m; i++){
		if(1ll*(m-i)*b[n]>c[n]) continue;
		memcpy(a,_a,sizeof(a));
		cnt=0;
		int x=c[n]-(m-i)*b[n];
		for(int j=0; j<=i; j++){
			ll sum=max(a[n]-x,0);
			for(int l=1; l<n; l++)
				sum+=a[l];
			sum-=sum%k;
			cnt+=sum/k;
			for(int l=1; l<=n; l++)
				if(sum<=a[l]){
					a[l]-=sum;
					break;
				}else sum-=a[l],a[l]=0;
			bool y(a[n]>x);
			for(int l=1; l<n; l++)
				if(a[l]) y=1;
			if(j==i) f[i][n]=cnt+y;
			y=0;
			for(int l=1; l<=n; l++)
				if(a[l]+b[l]>c[l]) y=1;
			if(y){
				sum=k;
				cnt++;
				for(int l=1; l<=n; l++)
					if(sum<=a[l]){
						a[l]-=sum;
						break;
					}else sum-=a[l],a[l]=0;
			}
			for(int l=1; l<=n; l++)
				a[l]+=b[l];
		}
	}
	while(--n){
		for(int i=0; i<m; i++){
			if(f[i][n+1]==ans||1ll*(m-i)*b[n]>c[n]) continue;
			memset(a,0,sizeof(a));
			int x=c[n]-(m-i)*b[n];
			cnt=0;
			for(int j=i; j>=0&&f[j][n+1]<ans; j--){
				ll sum=max(a[n]-x,0);
				for(int l=1; l<n; l++)
					sum+=a[l];
				sum-=sum%k;
				cnt+=sum/k;
				for(int l=1; l<=n; l++)
					if(sum<=a[l]){
						a[l]-=sum;
						break;
					}else sum-=a[l],a[l]=0;
				bool y(a[n]>x);
				for(int l=1; l<n; l++)
					if(a[l]) y=1;
				f[i][n]=min(f[i][n],f[j][n+1]+cnt+y);
				y=0;
				for(int l=1; l<=n; l++)
					if(a[l]+b[l]>c[l]) y=1;
				if(y){
					sum=k;
					cnt++;
					for(int l=1; l<=n; l++)
						if(sum<=a[l]){
							a[l]-=sum;
							break;
						}else sum-=a[l],a[l]=0;
				}
				for(int l=1; l<=n; l++)
					a[l]+=b[l];
			}
		}
	}
	//printf("n %d\n",_n); for(int i=0; i<m; i++) for(int j=1; j<=_n; j++) if(f[i][j]<ans) printf("i %d j %d f %lld\n",i,j,f[i][j]);
	for(int i=0; i<m; i++)
		ans=min(ans,f[i][1]);
	printf("%lld\n",ans);
	return 0;
}