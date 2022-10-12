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
const LD EPS = 1e-9;
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

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,K,M;
	int i,j,k,a,b,e,c,z,d;
	static int dyn[80][80][81][2];
	vector<PR> con[80];
	Read(N),Read(K),Read(M);
		while (M--)
		{
			Read(i),Read(j),Read(k);
			i--,j--;
			con[i].pb(mp(j,k));
		}
	Fill(dyn,60);
		Fox(i,N)
			FoxI(j,i,N-1)
				Fox(e,2)
					dyn[i][j][1][e]=0;
		FoxI(k,2,K)
			Fox(i,N)
				FoxI(j,i,N-1)
					Fox(e,2)
					{
						c=e ? j : i;
							Fox(z,Sz(con[c]))
							{
								a=con[c][z].x;
								d=con[c][z].y;
								// outside valid range?
									if ((a<i) || (a>j))
										continue;
								// continue in that dir
									if (!e)
										Min(dyn[i][j][k][e],dyn[a][j][k-1][e]+d);
									else
										Min(dyn[i][j][k][e],dyn[i][a][k-1][e]+d);
								// reverse dir
									if (!e)
										Min(dyn[i][j][k][e],dyn[i+1][a][k-1][1-e]+d);
									else
										Min(dyn[i][j][k][e],dyn[a][j-1][k-1][1-e]+d);
							}
					}
	int ans=INF;
		Fox(i,N)
			FoxI(j,i,N-1)
				Fox(e,2)
					Min(ans,dyn[i][j][K][e]);
		if (ans==INF)
			printf("-1\n");
		else
			printf("%d\n",ans);
	return(0);
}