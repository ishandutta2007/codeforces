#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],k,n,t_case;
bool vis[26];
char s[maxn],t[5];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s%d",&n,s+1,&k);
		memset(vis,0,sizeof vis);
		while(k--)scanf("%s",t),vis[*t-'a']=true;
		ri ans=0,cnt=0;
		for(ri i=1;i<=n;++i){
			if(vis[s[i]-'a'])ckmax(ans,cnt),cnt=1;
			else ++cnt;
		}
		printf("%d\n",ans);
	}
	return 0;
}