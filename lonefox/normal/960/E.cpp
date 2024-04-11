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

int ans;
int V[LIM];
int P[LIM];
vector<int> con[LIM];
int dyn[LIM][2],up[LIM][2];

void rec(int i,int p)
{
	int j,c,k;
	P[i]=p;
	dyn[i][0]=1;
		Fox(j,Sz(con[i]))
			if ((c=con[i][j])!=p)
			{
				rec(c,i);
					Fox(k,2)
						dyn[i][k]+=dyn[c][1-k];
			}
}

void rec2(int i,int p)
{
	int j,c,k;
		Fox(j,Sz(con[i]))
			if ((c=con[i][j])!=p)
			{
					Fox(k,2)
						up[c][k]=up[i][1-k] + dyn[i][k] - dyn[c][1-k];
				rec2(c,i);
			}
}

void Add(LL v)
{
	v%=MOD;
	ans=(ans+v+MOD)%MOD;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z;
	Read(N);
		Fox(i,N)
			Read(V[i]);
		Fox(i,N-1)
		{
			Read(a),Read(b),a--,b--;
			con[a].pb(b);
			con[b].pb(a);
		}
	rec(0,-1);
	rec2(0,-1);
		Fox(i,N)
		{
			LL v=V[i];
			Add(v*N);
			int p=P[i];
			int rem=N-(up[i][0]+up[i][1]);
				Fox(k,2)
					Add(v*rem*up[i][k]*(k?1:-1));
				Fox(j,Sz(con[i]))
					if ((c=con[i][j])!=p)
					{
						rem=N-(dyn[c][0]+dyn[c][1]);
							Fox(k,2)
								Add(v*rem*dyn[c][k]*(k?1:-1));
					}
		}
	printf("%d\n",ans);
	return(0);
}