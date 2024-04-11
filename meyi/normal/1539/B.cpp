#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn][27],n,q,t_case;
char s[maxn];
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	for(ri i=1;i<=n;++i){
		s[i]-='a'-1;
		for(ri j=1;j<27;++j)a[i][j]=a[i-1][j];
		++a[i][s[i]];
	}
	while(q--){
		ri ans=0,l,r;
		scanf("%d%d",&l,&r);
		for(ri i=1;i<27;++i)ans+=(a[r][i]-a[l-1][i])*i;
		printf("%d\n",ans);
	}
	return 0;
}