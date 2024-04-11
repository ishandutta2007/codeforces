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

int K;
int ans=1;
int dyn[64][10001][64];
int add[64];

pair<LL,LL> GCD(LL a,LL b)
{
		if (!b)
			return(mp(1,0));
	pair<LL,LL> p=GCD(b,a%b);
	return(mp(p.y,p.x-p.y*(a/b)));
}

LL Div(LL a,LL b)
{
	LL g=GCD(b,MOD).x;
		if (g<0)
			g+=MOD;
	return(a*g%MOD);
}

LL Mult(LL a,LL b)
{
	return(a*b%MOD);
}

void Go(LL p,int c)
{
	int i,j,k;
	int d,s;
		if (!dyn[c][0][c])
		{
			dyn[c][0][c]=1;
				Fox(i,K)
				{
					Fill(add,0);
						Fox(j,c+1)
						{
							d=Div(dyn[c][i][j],j+1);
							add[0]=(add[0]+d)%MOD;
							add[j+1]=(add[j+1]+MOD-d)%MOD;
						}
					s=0;
						Fox(j,c+1)
						{
							s=(s+add[j])%MOD;
							dyn[c][i+1][j]=s;
						}
				}
		}
	int v=1;
	s=0;
		Fox(i,c+1)
		{
			s=(s+Mult(v,dyn[c][K][i]))%MOD;
			v=Mult(v,p);
		}
	ans=Mult(ans,s);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	LL V;
	int i,j,k,a,b,c,x,y,z;
	ReadLL(V),Read(K);
	LL p;
		for (p=2; p*p<=V; p++)
			if (V%p==0)
			{
				c=1,V/=p;
					while (V%p==0)
						c++,V/=p;
				Go(p,c);
			}
		if (V>1)
			Go(V,1);
	cout << ans << endl;
	return(0);
}