#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=101;
int a[maxn],b[maxn],f[maxn][maxn*maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=1;i<=n;++i)scanf("%d",b+i);
		memset(f,0x3f,sizeof f);
		f[0][0]=0;
		for(ri i=1,sum=0;i<=n;++i){
			for(ri j=0;j<10001;++j)
				if(f[i-1][j]>=0){
					if(j+a[i]<10001)ckmin(f[i][j+a[i]],f[i-1][j]+(n-1)*a[i]*a[i]+2*j*a[i]+(n-1)*b[i]*b[i]+2*(sum-j)*b[i]);
					if(j+b[i]<10001)ckmin(f[i][j+b[i]],f[i-1][j]+(n-1)*b[i]*b[i]+2*j*b[i]+(n-1)*a[i]*a[i]+2*(sum-j)*a[i]);
				}
			sum+=a[i]+b[i];
		}
		ri ans=INT_MAX;
		for(ri i=0;i<10001;++i)ckmin(ans,f[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}