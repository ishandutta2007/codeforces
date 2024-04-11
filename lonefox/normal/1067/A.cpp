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

#define MOD 998244353
#define LIM 100005

int V[LIM];
PR P[LIM];
int dyn[LIM][203][2],nxt[LIM][203],sm[LIM][203];

void Add(int &a,int b){
	a+=b;
	if(a>=MOD)a-=MOD;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,d,x,y,z,v;
	Read(N);
	K=0;
		Fox(i,N)
		{
			Read(v);
				if (!i)
				{
						if (v<0)
						{
							Fox1(j,200)
								dyn[i][j][0]=1;
						}
						else
							dyn[i][v][0]=1;
					continue;
				}
				Fox1(j,200)
					Fox(k,2)
						if (d=dyn[i-1][j][k])
						{
							// smaller
								if (k)
									Add(sm[i][j-1],d);
							// equal
							Add(dyn[i][j][1],d);
							// greater
							Add(nxt[i][j+1],d);
						}
			k=0;
				Fox1(j,200)
				{
					Add(k,nxt[i][j]);
					Add(dyn[i][j][0],k);
				}
			k=0;
				FoxR1(j,200)
				{
					Add(k,sm[i][j]);
					Add(dyn[i][j][1],k);
				}
				if (v>0)
					Fox1(j,200)
						if (j!=v)
							Fox(k,2)
								dyn[i][j][k]=0;
		}
	int ans=0;
		Fox1(i,200)
			Add(ans,dyn[N-1][i][1]);
	printf("%d\n",ans);
	return(0);
}