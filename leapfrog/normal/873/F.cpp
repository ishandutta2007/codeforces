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
struct samn{int fa,len,ch[26];}S[400005];int smt,sls;
int n,qw[200005],sa[400006],sz[400005];char ch[200005];
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
	read(n),scanf("%s",ch+1),saminit();
	for(int i=1;i<=n;i++) samins(ch[i]-'a');
	for(int i=1;i<=smt;i++) qw[S[i].len]++;
	for(int i=1;i<=n;i++) qw[i]+=qw[i-1];
	for(int i=1;i<=smt;i++) sa[qw[S[i].len]--]=i;
	for(int i=1,p=1,w;i<=n;i++) scanf("%1d",&w),sz[p=S[p].ch[ch[i]-'a']]=!w;
	for(int z=smt,i=sa[z];z>1;i=sa[--z]) sz[S[i].fa]+=sz[i];
	ll mx=0;for(int i=1;i<=smt;i++) mx=max(mx,1ll*sz[i]*S[i].len);
	return printf("%lld\n",mx),0;
}