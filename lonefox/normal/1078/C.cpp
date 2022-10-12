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
#define LIM 300003

vector<int> con[LIM];
LL dyn[LIM][3];

void rec(int i,int p)
{
	int j,c;
	LL mat=0,unmat=1,disc=1;
	LL mat2,unmat2,disc2;
		Fox(j,Sz(con[i]))
			if ((c=con[i][j])!=p)
			{
				rec(c,i);
				mat2=(mat*(dyn[c][0]*2 + dyn[c][2]) + unmat*(dyn[c][1] + dyn[c][2]))%MOD;
				unmat2=unmat*(dyn[c][0]*2 + dyn[c][2])%MOD;
				disc2=disc*(dyn[c][0] + dyn[c][2])%MOD;
				mat=mat2;
				unmat=unmat2;
				disc=disc2;
			}
	dyn[i][0]=mat;
	dyn[i][1]=(unmat-disc+MOD)%MOD;
	dyn[i][2]=disc;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,k2,x,y,z,a,b,c,w;
	Read(N);
	//N=300000;
		Fox(i,N-1)
		{
			Read(j),Read(k),j--,k--;
			//j=i,k=i+1;
			con[j].pb(k);
			con[k].pb(j);
		}
	rec(0,-1);
	int ans=(dyn[0][0]+dyn[0][2])%MOD;
	cout << ans << endl;
	return(0);
}