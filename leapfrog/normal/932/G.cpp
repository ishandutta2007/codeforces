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
const int P=1e9+7,N=1000005;
struct pamn{int ch[26],fa,len,sz,df,tp;}S[N];int smt,sls;
int n,dp[N],g[N];char inc[N],c[N];
inline int gc(char s) {return s=='A'?0:s=='C'?1:s=='G'?2:3;}
inline void paminit() {smt=sls=2,S[1].len=-1,S[1].fa=S[2].fa=1;}
inline void pamins(int wh,int c,char *s)
{
	int p=sls;for(;s[wh]^s[wh-S[p].len-1];p=S[p].fa);
	if(S[p].ch[c]) return sls=S[p].ch[c],S[sls].sz++,void();
	int np=sls=++smt,ph=S[p].fa;S[np].len=S[p].len+2;
	memset(S[np].ch,0,sizeof(S[np].ch));for(;s[wh]^s[wh-S[ph].len-1];ph=S[ph].fa);
	S[np].fa=S[ph].ch[c]?S[ph].ch[c]:2,S[p].ch[c]=np,S[np].sz=1;
	S[np].df=S[np].len-S[S[np].fa].len;
	S[np].tp=(S[np].df==S[S[np].fa].df&&S[np].df*2<=S[np].len)?S[S[np].fa].tp:S[np].fa;
}
int main()
{
	scanf("%s",inc+1),paminit(),c[0]=-1,n=strlen(inc+1);
	for(int i=1,ct=0;i<=n;i++) c[++ct]=inc[i],c[++ct]=inc[n-i+1];
	dp[0]=1;for(int i=1;i<=n;i++)
	{
		pamins(i,c[i]-='a',c);
		for(int x=sls;x>2;x=S[x].tp)
		{
			g[x]=dp[i-S[S[x].tp].len-S[x].df];
			if(S[x].df==S[S[x].fa].df) (g[x]+=g[S[x].fa])%=P;
			if(i%2==0) (dp[i]+=g[x])%=P;
		}
	}
	//for(int i=1;i<=smt;i++) printf("%d%c",S[i].tp,i==smt?'\n':' ');
	return printf("%d\n",dp[n]),0;
}