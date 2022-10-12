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
const LD EPS = 1e-12;
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

bool ReadLL(LL &x)
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

#define MOD 1000000007
#define LIM 200005

int N;
char V[LIM];
int V2[LIM];
set<int> S[3];
set<int>::iterator I,J,K;

int BLT[3][LIM];

int Ch(char c)
{
		if (c=='R')
			return(0);
		else
		if (c=='P')
			return(1);
	return(2);
}

bool Beat(int a,int b)
{
	return(a==(b+1)%3);
}

void Update(int b,int i,int v)
{
		if (v<0)
			S[b].erase(i);
		else
			S[b].insert(i);
		for(i++;i<=N;i+=(i&-i))
			BLT[b][i]+=v;
}

int Query(int b,int i)
{
	int v=0;
		for(i++;i>0;i-=(i&-i))
			v+=BLT[b][i];
	return(v);
}

int Cnt(int c,int a,int b)
{
	return(Query(c,b)-Query(c,a-1));
}

int Ans()
{
	int ans=0;
	int c,bad,good;
		Fox(c,3)
		{
			bad=(c+1)%3;
			good=(c+2)%3;
				if (!Sz(S[bad]))
				{
					ans+=Sz(S[c]);
					continue;
				}
				if (!Sz(S[good]))
					continue;
			int bad1,bad2,good1,good2;
			I=S[bad].begin();
			bad1=*I;
			I=S[bad].end(),I--;
			bad2=*I;
			I=S[good].begin();
			good1=*I;
			I=S[good].end(),I--;
			good2=*I;
				if (good2<bad1)
				{
					ans+=Cnt(c,0,good2) + Cnt(c,bad2,N-1);
					continue;
				}
				if (good1>bad2)
				{
					ans+=Cnt(c,good1,N-1) + Cnt(c,0,bad1);
					continue;
				}
				if (good1<bad1 && good2>bad2)
				{
					ans+=Sz(S[c]);
					continue;
				}
				if (bad1<good1 && good2<bad2)
				{
					ans+=Cnt(c,0,bad1) + Cnt(c,good1,good2) + Cnt(c,bad2,N-1);
					continue;
				}
				if (good2<bad2)
				{
					ans+=Cnt(c,0,good2) + Cnt(c,bad2,N-1);
					continue;
				}
				if (good1>bad1)
				{
					ans+=Cnt(c,good1,N-1) + Cnt(c,0,bad1);
					continue;
				}
		}
	return(ans);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int M,Q;
	int i,j,k,a,b,c,x,y,z,c1,c2,vc;
	char v;
	Read(N),Read(Q);
	scanf("%s",&V);
		Fox(i,N)
			Update(V2[i]=Ch(V[i]),i,1);
	printf("%d\n",Ans());
		while (Q--)
		{
			scanf("%d %c",&i,&v);
			i--;
			c1=V2[i];
			c2=Ch(v);
			Update(c1,i,-1);
			Update(c2,i,1);
			V2[i]=c2;
			printf("%d\n",Ans());
		}
	return(0);
}