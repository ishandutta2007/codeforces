#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,t_case;
bool vis[256];
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		memset(vis,0,sizeof vis);
		bool flag=false;
		for(ri i=1;i<=n;++i){
			if(s[i]!=s[i-1])vis[s[i-1]]=true;
			if(vis[s[i]])flag=true;
		}
		puts(flag?"NO":"YES");
	}
	return 0;
}