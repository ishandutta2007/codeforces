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

#define MOD 1000000007

#define LIM 100005

int V[LIM];
vector<int> ch[LIM];
int dyn[LIM][2];

PR gcd(int a,int b)
{
		if (!b)
			return(mp(1,0));
	PR p=gcd(b,a%b);
	return(mp(p.y,p.x-p.y*(a/b)));
}

int divv(int a,int b)
{
	int inv=gcd(b,MOD).x;
		if (inv<0)
			inv+=MOD;
	return((LL)a*inv%MOD);
}

void rec(int i)
{
	int j,k,v,v2;
		if (V[i]==0)
		{
			v=1;
				Fox(j,Sz(ch[i]))
				{
					k=ch[i][j];
					rec(k);
					v=(LL)v*(dyn[k][0]+dyn[k][1])%MOD;
				}
			dyn[i][0]=v;
				Fox(j,Sz(ch[i]))
				{
					k=ch[i][j];
						if (dyn[k][1])
						{
							v2=divv(v,(dyn[k][0]+dyn[k][1])%MOD);
							dyn[i][1]=(dyn[i][1]+(LL)v2*dyn[k][1])%MOD;
						}
				}
		}
		else
		{
			v=1;
				Fox(j,Sz(ch[i]))
				{
					k=ch[i][j];
					rec(k);
					v=(LL)v*(dyn[k][0]+dyn[k][1])%MOD;
				}
			dyn[i][1]=v;
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,i,j;
	Read(N);
		Fox1(i,N-1)
		{
			Read(j);
			ch[j].pb(i);
		}
	j=0;
		Fox(i,N)
			Read(V[i]),j+=V[i];
	rec(0);
	printf("%d\n",dyn[0][1]);
	return(0);
}