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
const double EPS = 1e-9;
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

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,K;
	int i,j,k,jj,c;
	LL d,p;
	int X,Y;
	static int dyn[2][502][502];
	int pw[502];
	pw[0]=1;
		Fox1(i,501)
		{
			pw[i]=pw[i-1]<<1;
				if (pw[i]>=MOD)
					pw[i]-=MOD;
		}
	Read(N),Read(K);
	X=0,Y=1;
	dyn[Y][0][1]=1;
		Fox1(i,N)
		{
			swap(X,Y);
			Fill(dyn[Y],0);
			jj=min(i,K+1);
				Fox(j,jj)
					Fox1(k,i)
						if (d=dyn[X][j][k])
						{
							//printf("%d %d %d\t%d\n",i,j,k,dyn[X][j][k]);
							//don't increase
							c=i-k;
							dyn[Y][j][k+1]=(dyn[Y][j][k+1]+d*pw[c])%MOD;
							//increase
								if (j<K)
								{
									p=(LL)pw[c]*(pw[k]-1)%MOD;
									dyn[Y][j+1][1]=(dyn[Y][j+1][1]+d*p)%MOD;
								}
						}
		}
	int ans=0;
		Fox1(k,N+1)
		{
			//printf("%d %d %d\t%d\n",N+1,K,k,dyn[Y][K][k]);
			ans+=dyn[Y][K][k];
				if (ans>=MOD)
					ans-=MOD;
		}
	printf("%d\n",ans);
	return(0);
}