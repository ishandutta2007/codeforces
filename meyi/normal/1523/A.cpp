#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e3+10;
int m,n,nxt[maxn],pre[maxn],t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		memset(s,0,sizeof s);
		memset(nxt,0,sizeof nxt);
		memset(pre,0,sizeof pre);
		scanf("%d%d%s",&n,&m,s+1);
		bool flag=false;
		for(ri i=1;i<=n;++i)flag|=(s[i]^48);
		if(!flag){puts(s+1);continue;}
		for(ri i=1,lst=0;i<=n;++i)
			if(s[i]^48)lst=i;
			else if(lst)pre[i]=lst;
			else pre[i]=-1e7;
		for(ri i=n,lst=0;i;--i)
			if(s[i]^48)lst=i;
			else if(lst)nxt[i]=lst;
			else nxt[i]=1e7;
		for(ri i=1;i<=n;++i)
			if(s[i]=='0'&&(i-pre[i]<=m||nxt[i]-i<=m)&&i-pre[i]!=nxt[i]-i)
				s[i]='1';
		puts(s+1);
	}
	return 0;
}