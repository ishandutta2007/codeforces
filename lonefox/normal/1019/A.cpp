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
#define LIM 3003

vector<int> V[LIM];
vector<int> rem;

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,p,c,x,y,z,m,s;
	Read(N),Read(M);
		if (M==1)
		{
			printf("0\n");
			return(0);
		}
	K=z=0;
		Fox(i,N)
		{
			Read(p),Read(c);
				if (p==1)
					z++;
				else
					V[p].pb(c);
		}
		FoxI(i,2,M)
			sort(All(V[i]));
	LL ans=(LL)INF*INF;
		FoxI(m,max(z,1),N)
		{
			LL cur=0;
			rem.clear();
			int need=m-z;
				FoxI(i,2,M)
				{
					int d=Sz(V[i])-(m-1);
					Max(d,0);
						Fox(j,d)
							cur+=V[i][j],need--;
						FoxI(j,d,Sz(V[i])-1)
							rem.pb(V[i][j]);
				}
			int d=max(0,need);
				if (Sz(rem)<d)
					continue;
			sort(All(rem));
				Fox(j,d)
					cur+=rem[j];
			Min(ans,cur);
		}
	cout << ans << endl;
	return(0);
}