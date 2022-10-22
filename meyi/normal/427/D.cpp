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
struct node{
	int fa,len,nxt[26];
	inline node(){fa=len=0;memset(nxt,0,sizeof nxt);}
}sm[maxn];
int cnt=1,lst=1;
inline void extend(int ch){
	if(sm[lst].nxt[ch]){
		int p=lst,q=sm[p].nxt[ch];
		if(sm[q].len==sm[p].len+1)lst=q;
		else{
			int clone=++cnt;
			sm[clone]=sm[q];
			sm[clone].len=sm[p].len+1;
			sm[q].fa=clone;
			for(;p&&sm[p].nxt[ch]==q;p=sm[p].fa)sm[p].nxt[ch]=clone;
			lst=clone;
		}
		return;
	}
	int now=++cnt,p=lst;
	sm[now].len=sm[p].len+1;
	for(;p&&!sm[p].nxt[ch];p=sm[p].fa)sm[p].nxt[ch]=now;
	if(!p)sm[now].fa=1;
	else{
		ri q=sm[p].nxt[ch];
		if(sm[q].len==sm[p].len+1)sm[now].fa=q;
		else{
			int clone=++cnt;
			sm[clone]=sm[q];
			sm[clone].len=sm[p].len+1;
			sm[now].fa=sm[q].fa=clone;
			for(;p&&sm[p].nxt[ch]==q;p=sm[p].fa)sm[p].nxt[ch]=clone;
		}
	}
	lst=now;
}
int ans=INT_MAX,f1[maxn],f2[maxn],m,n;
char s[maxn],t[maxn];
void dfs(int p,int f){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs(e[i].to,p);
			f1[p]+=f1[e[i].to],f2[p]+=f2[e[i].to];
		}
	if(f&&f1[p]==1&&f2[p]==1)ckmin(ans,sm[sm[p].fa].len+1);
}
signed main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(ri i=1;i<=n;++i)extend(s[i]-'a'),++f1[lst];
	lst=1;
	for(ri i=1;i<=m;++i)extend(t[i]-'a'),++f2[lst];
	for(ri i=2;i<=cnt;++i)addedge(sm[i].fa,i);
	dfs(1,0);
	printf("%d",ans==INT_MAX?-1:ans);
	return 0;
}