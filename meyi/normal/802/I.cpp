#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int f[maxn];
struct node{
	int fa,len,nxt[26];
	inline node(){fa=len=0;memset(nxt,0,sizeof nxt);}
}sm[maxn];
int cnt=1,lst=1;
inline void extend(int ch){
	int now=++cnt,p=lst;
	f[now]=1;
	sm[now].len=sm[p].len+1;
	for(;p&&!sm[p].nxt[ch];p=sm[p].fa)sm[p].nxt[ch]=now;
	if(!p)sm[now].fa=1;
	else{
		ri q=sm[p].nxt[ch];
		if(sm[q].len==sm[p].len+1)sm[now].fa=q;
		else{
			int clone=++cnt;
			f[clone]=0;
			sm[clone]=sm[q];
			sm[clone].len=sm[p].len+1;
			sm[now].fa=sm[q].fa=clone;
			for(;p&&sm[p].nxt[ch]==q;p=sm[p].fa)sm[p].nxt[ch]=clone;
		}
	}
	lst=now;
}
ll ans;
void dfs(int p,int fa){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=fa){
			dfs(e[i].to,p);
			f[p]+=f[e[i].to];
		}
	ans+=1ll*f[p]*f[p]*(sm[p].len-sm[sm[p].fa].len);
}
char s[maxn];
int n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(ri i=1;i<=n;++i)extend(s[i]-'a');
		for(ri i=2;i<=cnt;++i)addedge(sm[i].fa,i);
		dfs(1,0);
		printf("%lld\n",ans);
		clear(hd,cnt),clear(sm,cnt),clear(s,n);
		ans=len=0,cnt=lst=1;
	}
	return 0;
}