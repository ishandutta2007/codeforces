#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#include<cassert>
#define ll long long
#define db double
#define fir first
#define sec second
#define mp make_pair
using namespace std;

inline void up(int &a,const int &b){ if(a<b)a=b; }
inline void down(int &a,const int &b){ if(a>b)a=b; }
const int maxn = 1010000;
const int maxk = 30;
const int mask = 1<<20;

int n,m,K;
int a[maxn],b[maxn];

int s[maxk],t[maxk];
int sn[maxn],tn[maxn];
char str[maxk];

int trans[maxk],pos[maxk],pos2[maxk];
int f[maxk][mask],g[maxk][mask];

int main()
{
//	freopen("tmp.in","r",stdin);
	
	scanf("%d%d%d",&n,&m,&K);
	scanf("%s",str);
	for(int j=1;j<=K;j++) s[j]=str[j-1]-'0';
	scanf("%s",str);
	for(int j=1;j<=K;j++) t[j]=str[j-1]-'0';
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	
	for(int i=1;i<=K;i++) trans[i]=i;
	for(int j=1;j<=K;j++)
	{
		sn[0]|=s[j]<<(j-1);
		tn[0]|=t[j]<<(j-1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=K;j++) pos[j]=j;
		swap(pos[a[i]],pos[b[i]]);
		for(int j=1;j<=K;j++)
			pos2[j]=pos[trans[j]];
		for(int j=1;j<=K;j++) trans[j]=pos2[j];
		
		for(int j=1;j<=K;j++) 
		{
			sn[i] |= s[trans[j]]<<(j-1);
			tn[i] |= t[trans[j]]<<(j-1);
		}
	}
	
	int al=1<<K;
	for(int i=0;i<=K;i++) for(int s=0;s<al;s++)
	{
		f[i][s]=n+1;
		g[i][s]=0;
	}
	
	for(int i=0;i<=n;i++)
	{
		down(f[__builtin_popcount(sn[i])][sn[i]],i);
		up(g[__builtin_popcount(tn[i])][tn[i]],i);
	}
	for(int i=0;i<=K;i++)
	{
		for(int j=1;j<=K;j++) for(int s=0;s<al;s++) if(!(s>>(j-1)&1))
		{
			down(f[i][s],f[i][s+(1<<(j-1))]);
			up(g[i][s],g[i][s+(1<<(j-1))]);
		}
	}
	
	int ans=0,ansl=0,ansr=n;
	for(int s=0;s<al;s++) for(int i=0;i<=K;i++) for(int j=0;j<=K;j++)
	{
		int l=f[i][s],r=g[j][s];
		if(r-l>=m)
		{
			int k=K-(i+j-2*__builtin_popcount(s));
			if(ans<k) ans=k,ansl=l,ansr=r;
		}
	}
	printf("%d\n",ans);
	printf("%d %d\n",ansl+1,ansr);
	
	return 0;
}