//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct node{int ch[26],fa,len;}S[200005];int st,sls,sa[200005],rk[200005];
int T,n,sz[200005];char c[200005];
inline void SamIns(int c)
{
	int p=sls,np=sls=++st;memset(S[np].ch,0,sizeof(S[np].ch)),S[np].len=S[p].len+1;
	S[np].fa=0,sz[np]=1;for(;p&&!S[p].ch[c];p=S[p].fa) S[p].ch[c]=np;
	int q=S[p].ch[c];if(!p) return(void)(S[np].fa=1);
	if(S[q].len==S[p].len+1) return(void)(S[np].fa=q);
	int nq=++st;S[nq]=S[q],S[nq].len=S[p].len+1,S[q].fa=S[np].fa=nq,sz[nq]=0;
	for(;p&&S[p].ch[c]==q;p=S[p].fa) S[p].ch[c]=nq;
}
inline void SA()
{
	memset(rk,0,sizeof(rk));
	for(int i=1;i<=st;i++) rk[S[i].len]++;
	for(int i=1;i<=n;i++) rk[i]+=rk[i-1];
	for(int i=1;i<=st;i++) sa[rk[S[i].len]--]=i;
	for(int i=st;i;i--) sz[S[sa[i]].fa]+=sz[sa[i]];
}
inline void solve()
{
	scanf("%s",c+1),n=strlen(c+1),st=sls=1,memset(S[1].ch,0,sizeof(S[1]));
	for(int i=1;i<=n;i++) SamIns(c[i]-'a');
	SA();long long res=0;
	for(int i=1;i<=st;i++) res+=1ll*sz[i]*sz[i]*(S[i].len-S[S[i].fa].len);
	printf("%lld\n",res);
}
int main() {for(read(T);T--;) solve();}