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
	int N,M,K,T;
	int i,j,k,x,y,z,d,v;
	static char G[3][305];
	static bool dyn[105][3];
	Read(T);
		while (T--)
		{
			Read(N),Read(i);
				Fox(i,3)
					scanf("%s",&G[i]);
				Fox(i,3)
					FoxI(j,N,300)
						G[i][j]='.';
				Fox(i,3)
					if (G[i][0]=='s')
						break;
			G[i][0]='.';
			Fill(dyn,0);
			dyn[0][i]=1;
				Fox(i,N)
					Fox(j,3)
						if (dyn[i][j])
							Fox(k,3)
								if (abs(j-k)<2)
								{
									if (G[j][i+1 + i*2]!='.')
										continue;
									if (G[k][i+1 + i*2]!='.')
										continue;
									if (G[k][i+1 + i*2+1]!='.')
										continue;
									if (G[k][i+1 + i*2+2]!='.')
										continue;
									dyn[i+1][k]=1;
								}
				Fox(i,3)
					if (dyn[N-1][i])
					{
						printf("YES\n");
						goto Done;
					}
			printf("NO\n");
Done:;
		}
	return(0);
}