//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
struct SAM
{
	struct node{int fa,len,ch[26];}S[400005];int sls,smt,tag[400005];
	struct edge{int to,nxt;}e[400005];int et,head[400005],rs[200005];
	inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
	inline void saminit() {sls=smt=1;}SAM() {saminit();}
	inline void samins(int c)
	{
		int p=sls,np=sls=++smt;S[np].len=S[p].len+1;
		for(;p&&!S[p].ch[c];p=S[p].fa) S[p].ch[c]=np;
		int q=S[p].ch[c];if(!p) return S[np].fa=1,void();
		if(S[p].len+1==S[q].len) return S[np].fa=q,void();
		int nq=++smt;S[nq]=S[q],S[nq].len=S[p].len+1,S[q].fa=S[np].fa=nq;
		for(;p&&S[p].ch[c]==q;p=S[p].fa) S[p].ch[c]=nq;
	}
	inline void build(int n,char *s) {for(int i=1;i<=n;i++) samins(s[i]-'a');}
	inline void match(int n,char *s)
	{
		int p=1;for(int i=1;i<=n;i++) p=S[p].ch[s[i]-'a'];
		if(!p) return;else tag[p]++;
	}
	inline void pushdw(int x) {for(int i=head[x];i;i=e[i].nxt) tag[e[i].to]+=tag[x],pushdw(e[i].to);}
	inline void solve(int n,char *s)
	{
		for(int i=2;i<=smt;i++) adde(S[i].fa,i);
		pushdw(1);for(int i=1,p=1;i<=n;i++) rs[i]=tag[p=S[p].ch[s[i]-'a']];
	}
}A,B;
int n,m,ln[200005];char t[200005],buf[800005],*ch[200005];
signed main()
{
	scanf("%s",t+1),n=strlen(t+1),read(m),ch[1]=buf;ll res=0;
	for(int i=1;i<=m;i++) scanf("%s",ch[i]+1),ch[i+1]=ch[i]+(ln[i]=strlen(ch[i]+1))+2;
	A.build(n,t),reverse(t+1,t+n+1),B.build(n,t),reverse(t+1,t+n+1);
	for(int i=1;i<=m;i++) A.match(ln[i],ch[i]),reverse(ch[i]+1,ch[i]+ln[i]+1),B.match(ln[i],ch[i]);
	A.solve(n,t),reverse(t+1,t+n+1),B.solve(n,t);for(int i=1;i<=n;i++) res+=1ll*A.rs[i]*B.rs[n-i];
	return printf("%lld\n",res),0;
}