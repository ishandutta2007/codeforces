#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],cnt[31],m,n,pre[maxn][31],t_case;
int main(){
	for(ri i=1;i<=200000;++i)
		for(ri j=0;j<20;++j)
			pre[i][j]=pre[i-1][j]+bool(i&(1<<j));
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		ri ans=INT_MAX;
		for(ri i=0;i<20;++i)ckmin(ans,(m-n+1)-(pre[m][i]-pre[n-1][i]));
		printf("%d\n",ans);
	}
	return 0;
}