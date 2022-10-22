#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=256;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt;
}e[maxn*maxn];
int deg[maxn],hd[maxn],len;
inline void addedge(int fr,int to){
	++deg[to];
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int cnt,m[maxn],n;
char ans[maxn],s[maxn][maxn];
inline void toposort(){
	queue<char>q;
	for(char i='a';i<='z';++i)
		if(!deg[i])
			q.push(i);
	while(q.size()){
		char p=q.front();q.pop();
		ans[++cnt]=p;
		for(ri i=hd[p];i;i=e[i].nxt)
			if(!--deg[e[i].to])
				q.push(e[i].to);
	}
	if(cnt<26)puts("Impossible"),exit(0);
}
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		m[i]=strlen(s[i]+1);
		for(ri j=1;j<i;++j){
			for(ri k=1,l=min(m[i],m[j]);k<=l;++k)
				if(s[i][k]!=s[j][k]){
					addedge(s[j][k],s[i][k]);
					goto skip;
				}
			if(m[i]<m[j])puts("Impossible"),exit(0);
			skip:;
		}
	}
	toposort();
	puts(ans+1);
	return 0;
}