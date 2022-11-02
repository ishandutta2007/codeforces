//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct pamn{int ch[26],fa,len,hf,sz;}S[100005];int smt,sls,n,dep[100005];ll T[100005];char c[100005];
inline void paminit() {smt=sls=2,S[1].len=-1,S[1].fa=S[2].fa=1,S[1].hf=S[2].hf=2;}
inline void pamins(int wh,int c,char *s)
{
	int p=sls;for(;s[wh]^s[wh-S[p].len-1];p=S[p].fa);
	if(S[p].ch[c]) return sls=S[p].ch[c],S[sls].sz++,void();
	int np=sls=++smt,ph=S[p].fa;S[np].len=S[p].len+2;
	memset(S[np].ch,0,sizeof(S[np].ch));for(;s[wh]^s[wh-S[ph].len-1];ph=S[ph].fa);
	S[np].fa=S[ph].ch[c]?S[ph].ch[c]:2,S[p].ch[c]=np;
	int pw=S[p].hf;if(S[np].len<=2) return S[np].hf=S[np].fa,S[np].sz=1,void();
	for(;s[wh]^s[wh-S[pw].len-1]||((S[pw].len+2)<<1)>S[np].len;pw=S[pw].fa);
	S[np].hf=S[pw].ch[c],S[np].sz=1;
}
int main()
{
	scanf("%s",c+1),n=strlen(c+1),paminit(),c[0]=-1;
	for(int i=1;i<=n;i++) pamins(i,c[i]-='a',c);
	for(int i=smt;i>=1;i--) S[S[i].fa].sz+=S[i].sz;
	for(int i=3;i<=smt;i++) if(S[i].len/2==S[S[i].hf].len) dep[i]=dep[S[i].hf]+1;else dep[i]=1;
	for(int i=3;i<=smt;i++) T[1]+=S[i].sz,T[dep[i]+1]-=S[i].sz;
	//for(int i=1;i<=smt;i++) printf("%d , %d\n",dep[i],S[i].sz);
	for(int i=1;i<=n;i++) T[i]+=T[i-1];
	for(int i=1;i<=n;i++) printf("%lld%c",T[i],i==n?'\n':' ');
	return 0;
}