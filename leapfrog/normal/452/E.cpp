//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1e9+7;int cf[200005];
struct sam{int fa,len,ch[26];}S[600005];int sls,smt,et,head[600005];
int sz[600005][3],len[3];char c[3][200005];struct edge{int to,nxt;}e[600005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x) {for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to),sz[x][0]+=sz[e[i].to][0],sz[x][1]+=sz[e[i].to][1],sz[x][2]+=sz[e[i].to][2];}
inline void saminit() {sls=smt=1;}
inline void samins(int c)
{
	int p=sls,np=sls=++smt;S[np].len=S[p].len+1;
	for(;p&&!S[p].ch[c];p=S[p].fa) S[p].ch[c]=np;
	int q=S[p].ch[c];if(!p) return(void)(S[np].fa=1);
	if(S[q].len==S[p].len+1) return(void)(S[np].fa=q);
	int nq=++smt;S[nq]=S[q],S[nq].len=S[p].len+1,S[q].fa=S[np].fa=nq;
	for(;p&&S[p].ch[c]==q;p=S[p].fa) S[p].ch[c]=nq;
}
int main()
{
	saminit();for(int i=0;i<3;i++) scanf("%s",c[i]+1),len[i]=strlen(c[i]+1);
	for(int i=0;i<3;i++,sls=1) for(int j=1;j<=len[i];j++) samins(c[i][j]-'a');
	for(int i=0;i<3;i++) for(int j=1,p=1;j<=len[i];j++) p=S[p].ch[c[i][j]-'a'],sz[p][i]=1;
	{for(int i=2;i<=smt;i++) adde(S[i].fa,i);}dfs(1);
	for(int i=2,g;i<=smt;i++) g=1ll*sz[i][0]*sz[i][1]%P*sz[i][2]%P,(cf[S[i].len+1]+=P-g)%=P,(cf[S[S[i].fa].len+1]+=g)%=P;
	int n=min(len[0],min(len[1],len[2]));for(int i=1;i<=n;i++) (cf[i]+=cf[i-1])%=P;
	for(int i=1;i<=n;i++) printf("%d%c",cf[i],i==n?'\n':' ');
	return 0;
}