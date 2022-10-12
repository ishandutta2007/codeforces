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

#define MOD 1000000007

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,k,t,ans;
	static int dyn[1001][1001];
	static int dist[1001][1001];
	static int dyn2[1001][1001],sum2[1001][1001];
	static int fact[1001];
	dyn[0][0]=1;
		Fox1(i,1000)
			Fox1(j,1000)
			{
				dyn[i][j]=dyn[i-1][j-1];
					if (i-j>=0)
					{
						dyn[i][j]+=dyn[i-j][j];
							if (dyn[i][j]>=MOD)
								dyn[i][j]-=MOD;
					}
			}
		Fox(i,1001)
			Fox(j,1001)
			{
					if (!i)
					{
						if (!j)
							dyn2[i][j]=1;
					}
					else
						dyn2[i][j]=sum2[i-1][j];
				sum2[i][j]=dyn2[i][j];
					if (j-1>=0)
					{
						sum2[i][j]+=sum2[i][j-1];
							if (sum2[i][j]>=MOD)
								sum2[i][j]-=MOD;
					}
			}
		Fox(i,1001)
			Fox(j,1001)
			{
				k=i-j*(j-1)/2;
					if (k>=0)
						dist[i][j]=dyn[k][j];
			}
	fact[0]=1;
		Fox1(i,1000)
			fact[i]=(LL)fact[i-1]*i%MOD;
	Read(t);
		while (t--)
		{
			Read(i),Read(j);
			ans=0;
			k=j*(j-1)/2;
			i-=j;
				FoxI(k,k,i)
					ans=(ans+(LL)dist[k+j][j]*dyn2[j+1][i-k])%MOD;
			ans=(LL)ans*fact[j]%MOD;
			printf("%d\n",ans);
		}
	return(0);
}