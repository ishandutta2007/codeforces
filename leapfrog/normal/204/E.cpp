//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
struct SAM{int fa,len,ch[26];}S[200005];int sls,smt,vl[200005];
int n,K,ln[100005],ls[200005],fg[200005];char buf[200005],*s[100005],vs[200005];
inline void saminit() {sls=smt=1,memset(S[1].ch,0,sizeof(S[1].ch));}
inline void samins(int c)
{
	int p=sls,np=sls=++smt;S[np].len=S[p].len+1;
	for(;p&&!S[p].ch[c];p=S[p].fa) S[p].ch[c]=np;
	int q=S[p].ch[c];if(!p) return(void)(S[np].fa=1);
	if(S[q].len==S[p].len+1) return(void)(S[np].fa=q);
	int nq=++smt;S[nq]=S[q],S[nq].len=S[p].len+1,S[q].fa=S[np].fa=nq;
	for(;p&&S[p].ch[c]==q;p=S[p].fa) S[p].ch[c]=nq;
}
inline void update(int x,int id) {for(;x&&ls[x]!=id;x=S[x].fa) ls[x]=id,fg[x]++;}
inline void jumpf(int x) {if(x!=1&&!vs[x]) jumpf(S[x].fa),vl[x]+=vl[S[x].fa],vs[x]=1;}
int main()
{
	read(n),read(K),s[1]=buf,saminit();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1),ln[i]=strlen(s[i]+1),s[i+1]=s[i]+ln[i]+1;
	for(int i=1;i<=n;i++) {sls=1;for(int j=1;j<=ln[i];j++) samins(s[i][j]-'a');}
	for(int i=1;i<=n;i++) for(int p=1,j=1;j<=ln[i];j++) update(p=S[p].ch[s[i][j]-'a'],i);
	for(int i=1;i<=smt;i++) if(fg[i]>=K) vl[i]=S[i].len-S[S[i].fa].len;else vl[i]=0;
	for(int i=1;i<=smt;i++) jumpf(i);
	for(int i=1;i<=n;i++)
	{
		ll res=0;for(int p=1,j=1;j<=ln[i];j++) res+=vl[p=S[p].ch[s[i][j]-'a']];
		printf("%lld%c",res,i==n?'\n':' ');
	}
	return 0;
}