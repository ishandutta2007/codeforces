#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int ans[maxn],k,m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%s",&n,&k,s+1);
		ri cnt=s[n+1]=0;
		for(ri i=1;i<=n;++i){
			if(cnt<k&&(s[i]&1)==(k&1))ans[i]=1,++cnt;
			else ans[i]=0;
		}
		ans[n]+=k-cnt;
		for(ri i=1;i<=n;++i)s[i]^=(k-ans[i])&1;
		puts(s+1);
		for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}