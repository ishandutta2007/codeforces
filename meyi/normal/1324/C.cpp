#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ri ans=0,lst=0;
		for(ri i=1;i<=n;++i)
			if(s[i]=='R')
				ckmax(ans,i-lst),lst=i;
		ckmax(ans,n+1-lst);
		printf("%d\n",ans);
		for(ri i=1;i<=n;++i)s[i]=0;
	}
	return 0;
}