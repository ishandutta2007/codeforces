#define DEBUG 0

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const double EPS = 1e-6;
const LD PI = acos(-1.0);

//#if DEBUG
#define GETCHAR getchar
/*#else
#define GETCHAR getchar_unlocked
#endif*/

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}


int L;
char S[300008];
char S1[300008];
int sz,P[20][300008];
pair<PR,int> M[300008];

void BuildSuffixArray()
{
	int i,s;
		if (L==1)
		{
			sz=1;
			P[0][0]=0;
			return;
		}
		Fox(i,L)
			P[0][i]=S[i];
		for (sz=s=1; s<L; sz++,s<<=1)
		{
				Fox(i,L)
					M[i]=mp(mp(P[sz-1][i],(i+s<L ? P[sz-1][i+s] : -1)),i);
			sort(M,M+L);
				Fox(i,L)
					if ((i) && (M[i].x==M[i-1].x))
						P[sz][M[i].y]=P[sz][M[i-1].y];
					else
						P[sz][M[i].y]=i;
		}
}

int GetLCP(int i,int j)
{
	int k,lcp=0;
		for (k=sz-1; (k>=0) && (i<L) && (j<L); k--)
			if (P[k][i]==P[k][j])
			{
				i+=1<<k;
				j+=1<<k;
				lcp+=1<<k;
			}
	return(lcp);
}

#define MOD 1000000007

int par[300008],cnt[300008][3],rank[300008];

void Make(int i,int j)
{
	par[i]=i;
	cnt[i][j]=1;
}

int Find(int i)
{
		if (par[i]!=i)
			par[i]=Find(par[i]);
	return(par[i]);
}

void Merge(int i,int j)
{
	int k;
	i=Find(i);
	j=Find(j);
		if (i==j)
			return;
		if (rank[i]<rank[j])
		{
			par[i]=j;
				Fox(k,3)
				{
					cnt[j][k]+=cnt[i][k];
						if (cnt[j][k]>=MOD)
							cnt[j][k]-=MOD;
				}
		}
		else
		{
				if (rank[i]==rank[j])
					rank[i]++;
			par[j]=i;
				Fox(k,3)
				{
					cnt[i][k]+=cnt[j][k];
						if (cnt[i][k]>=MOD)
							cnt[i][k]-=MOD;
				}
		}
}

int val;

void sub(int i)
{
	i=Find(i);
		if ((cnt[i][0]) && (cnt[i][1]) && (cnt[i][2]))
		{
			int v=(LL)cnt[i][0]*cnt[i][1]%MOD*cnt[i][2]%MOD;
			val-=v;
				if (val<0)
					val+=MOD;
		}
}

void add(int i)
{
	i=Find(i);
		if ((cnt[i][0]) && (cnt[i][1]) && (cnt[i][2]))
		{
			int v=(LL)cnt[i][0]*cnt[i][1]%MOD*cnt[i][2]%MOD;
			val+=v;
				if (val>=MOD)
					val-=MOD;
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,k,len,mn=INF;
	int end[3];
	int nE;
	static PR E[300008];
	static int ord[300008],ans[300008];
	//string SS[3];
		Fox(i,3)
		{
			scanf("%s",&S1);
			//SS[i]=S1;
			len=strlen(S1);
			Min(mn,len);
				Fox(j,len)
					S[L++]=S1[j];
			end[i]=L;
			S[L++]=i+1;
		}
	BuildSuffixArray();
		Fox(i,L)
			ord[P[sz-1][i]]=i;
		Fox(i,L)
		{
			j=ord[i];
				if (j<end[0])
					k=0;
				else
				if (j<end[1])
					k=1;
				else
					k=2;
			Make(i,k);
		}
	nE=0;
		Fox(i,L-1)
		{
			j=GetLCP(ord[i],ord[i+1]);
				if (j)
					E[nE++]=mp(j,i);
		}
	sort(E,E+nE);
		FoxR(i,nE)
		{
			sub(E[i].y);
			sub(E[i].y+1);
			Merge(E[i].y,E[i].y+1);
			add(E[i].y);
				if ((!i) || (E[i].x!=E[i-1].x))
				{
						if (!i)
							j=1;
						else
							j=E[i-1].x+1;
						while (j<=E[i].x)
							ans[j++]=val;
				}
		}
		/*FoxR1(i,mn-1)
		{
			ans[i]+=ans[i+1];
				if (ans[i]>=MOD)
					ans[i]-=MOD;
		}*/
		Fox1(i,mn)
			printf("%d%c",ans[i],i==mn ? '\n' : ' ');
		/*Fox1(i,mn)
		{
			int a,b,c,d=0;
			string s1,s2,s3;
				Fox(a,Sz(SS[0])-i+1)
					Fox(b,Sz(SS[1])-i+1)
						Fox(c,Sz(SS[2])-i+1)
						{
							s1=SS[0].substr(a,i);
							s2=SS[1].substr(b,i);
							s3=SS[2].substr(c,i);
								if ((s1==s2) && (s2==s3))
									d++;
						}
				if (d!=ans[i])
					printf("BAD\n");
		}*/
	return(0);
}