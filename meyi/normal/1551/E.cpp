#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2010;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],f[maxn][maxn],k,n,t_case;
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			for(ri j=0;j<=i;++j)f[i][j]=0;
		}
		for(ri i=1;i<=n;++i)
			for(ri j=0;j<i;++j){
				ckmax(f[i][j],f[i-1][j]+(a[i]==i-j));
				ckmax(f[i][j+1],f[i-1][j]);
			}
		bool flag=false;
		for(ri i=0;i<=n;++i)
			if(f[n][i]>=k){
				printf("%d\n",i);
				flag=true;
				break;
			}
		if(!flag)puts("-1");
	}
	return 0;
}