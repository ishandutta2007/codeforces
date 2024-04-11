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
struct node{int ch[26],fa,len;}S[2000005];int st,sls,rnk[2000005],sa[2000005];
int T,n,sz[2000005],tag[2000005],tagid;char s[1000005];
inline void SamIns(int c)
{
	int p=sls,np=sls=++st;memset(S[np].ch,0,sizeof(S[np].ch)),S[np].len=S[p].len+1;
	for(;p&&!S[p].ch[c];p=S[p].fa) S[p].ch[c]=np;
	int q=S[p].ch[c];if(!p) return(void)(S[np].fa=1);
	if(S[q].len==S[p].len+1) return(void)(S[np].fa=q);
	int nq=++st;S[nq]=S[q],S[nq].len=S[p].len+1,S[q].fa=S[np].fa=nq;
	for(;p&&S[p].ch[c]==q;p=S[p].fa) S[p].ch[c]=nq;
}
inline void SamInit() {st=sls=1,memset(S[1].ch,0,sizeof(S[1].ch));}
inline void solve()
{
	int p=1,len=0;long long res=0;++tagid;
	for(int i=1;i<=n;i++)
	{
		while(p!=1&&!S[p].ch[s[i]-'a']) len=S[p=S[p].fa].len;
		if(S[p].ch[s[i]-'a']) p=S[p].ch[s[i]-'a'],len++;
	}
	for(int i=1;i<=n;i++)
	{
		if(len==n)
		{
			if(tag[p]^tagid) res+=sz[p],tag[p]=tagid;
			if(--len==S[S[p].fa].len) p=S[p].fa;
		}
		while(p!=1&&!S[p].ch[s[i]-'a']) len=S[p=S[p].fa].len;
		if(S[p].ch[s[i]-'a']) p=S[p].ch[s[i]-'a'],len++;
	}
	printf("%lld\n",res);
}
int main()
{
	scanf("%s",s+1),n=strlen(s+1),SamInit();
	for(int i=1;i<=n;i++) SamIns(s[i]-'a');
	for(int i=1,p=1;i<=n;i++) sz[p=S[p].ch[s[i]-'a']]=1;
	for(int i=1;i<=st;i++) rnk[S[i].len]++;
	for(int i=1;i<=n;i++) rnk[i]+=rnk[i-1];
	for(int i=1;i<=st;i++) sa[rnk[S[i].len]--]=i;
	for(int i=st;i;i--) sz[S[sa[i]].fa]+=sz[sa[i]];
	for(read(T);T--;) scanf("%s",s+1),n=strlen(s+1),solve();
}