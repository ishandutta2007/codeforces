#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],ans=INT_MAX,m,n,t_case;
char s[maxn],t[]="ACTG";
int main(){
	scanf("%d%s",&n,s+1);
	for(ri i=1;i+3<=n;++i){
		ri sum=0;
		for(ri j=0;j<4;++j)
			sum+=min({abs(s[i+j]-26-t[j]),abs(s[i+j]-t[j]),abs(s[i+j]+26-t[j])});
		ckmin(ans,sum);
	}
	printf("%d",ans);
	return 0;
}