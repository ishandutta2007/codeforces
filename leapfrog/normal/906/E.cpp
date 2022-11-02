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
struct pamn{int ch[26],fa,len,df,tp;}S[N];int smt,sls;
int n,f[N],ls[N],wh[N];char a[N],b[N],c[N];
inline void paminit() {smt=sls=2,S[1].len=-1,S[1].fa=S[2].fa=1;}
inline void pamins(int wh,int c,char *s)
{
	int p=sls;for(;s[wh]^s[wh-S[p].len-1];p=S[p].fa);
	if(S[p].ch[c]) return sls=S[p].ch[c],void();
	int np=sls=++smt,ph=S[p].fa;S[np].len=S[p].len+2;
	for(;s[wh]^s[wh-S[ph].len-1];ph=S[ph].fa);
	S[np].fa=S[ph].ch[c]?S[ph].ch[c]:2,S[p].ch[c]=np;
	S[np].df=S[np].len-S[S[np].fa].len;
	S[np].tp=(S[np].df==S[S[np].fa].df)?S[S[np].fa].tp:S[np].fa;
}
int main()
{
	scanf("%s%s",a+1,b+1),paminit(),c[0]=-1,n=strlen(a+1);
	for(int i=1,ct=0;i<=n;i++) c[++ct]=a[i]-'a',c[++ct]=b[i]-'a';
	n<<=1,wh[0]=1,memset(f+1,0x3f,n<<2);for(int i=1;i<=n;i++)
	{
		pamins(i,c[i],c);if(i%2==0&&c[i]==c[i-1]&&f[i]>f[i-2]) f[i]=f[i-2],ls[i]=i-2;
		for(int x=sls;x>2;x=S[x].tp)
		{
			wh[x]=i-S[S[x].tp].len-S[x].df;
			if(S[S[x].fa].df==S[x].df&&f[wh[x]]>f[wh[S[x].fa]]) wh[x]=wh[S[x].fa];
			if(i%2==0&&f[i]>f[wh[x]]+1) f[i]=f[wh[x]]+1,ls[i]=wh[x];
		}
	}
	//for(int i=1;i<=smt;i++) printf("%d%c",S[i].df,i==smt?'\n':' ');
	if(f[n]>1e9) return puts("-1"),0;else printf("%d\n",f[n]);
	for(int i=n;i;i=ls[i]) if(i-ls[i]!=2) printf("%d %d\n",ls[i]/2+1,i/2);
	return 0;
}