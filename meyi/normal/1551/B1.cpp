#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int ans,cnt[maxn],k,m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(ri i=1;i<=n;++i)++cnt[s[i]];
		ans=0;
		for(ri i='a';i<='z';++i)ans+=min(cnt[i],2);
		printf("%d\n",ans/2);
		for(ri i=1;i<=n;++i)cnt[s[i]]=0,s[i]=0;
	}
	return 0;
}