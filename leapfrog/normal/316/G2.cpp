//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct node{int ch[26],fa,len;}S[1000005];int K,smt,sls,sz[1000005][11],L[1000005],R[1000005];
struct edge{int to,nxt;}e[1000005];int n,et,head[1000005];char ch[1000005];ll res=0;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x)
{
	for(int i=head[x];i;i=e[i].nxt)
		{dfs(e[i].to);for(int k=0;k<=K;k++) sz[x][k]+=sz[e[i].to][k];}
}
inline char chk(int x) {for(int i=1;i<=K;i++) if(sz[x][i]<L[i]||sz[x][i]>R[i]) return 0;return 1;}
inline void saminit() {smt=sls=1;}
inline void samins(int c)
{
	int p=sls,np=sls=++smt;S[np].len=S[p].len+1;
	for(;p&&!S[p].ch[c];p=S[p].fa) S[p].ch[c]=np;
	int q=S[p].ch[c];if(!p) return S[np].fa=1,void();
	if(S[p].len+1==S[q].len) return S[np].fa=q,void();
	int nq=++smt;S[nq]=S[q],S[nq].len=S[p].len+1,S[q].fa=S[np].fa=nq;
	for(;p&&S[p].ch[c]==q;p=S[p].fa) S[p].ch[c]=nq;
}
int main()
{
	scanf("%s",ch+1),saminit(),read(K),n=strlen(ch+1);
	for(int i=1;i<=n;i++) samins(ch[i]-'a'),sz[sls][0]=1;
	for(int k=1;k<=K;k++)
	{
		scanf("%s",ch+1),n=strlen(ch+1),read(L[k]),read(R[k]);
		sls=1;for(int i=1;i<=n;i++) samins(ch[i]-'a'),sz[sls][k]=1;
	}
	for(int i=2;i<=smt;i++) adde(S[i].fa,i);
	dfs(1);for(int i=2;i<=smt;i++) if(sz[i][0]&&chk(i)) res+=S[i].len-S[S[i].fa].len;
	return printf("%lld\n",res),0;
}