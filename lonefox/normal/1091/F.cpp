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

LL L[LIM];
char S[LIM];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z;
	Read(N);
		Fox(i,N)
			ReadLL(L[i]);
	scanf("%s",&S);
	LL ans=0;
	LL sg1=0,sg2=0,sw=0;
	bool w=0;
		Fox(i,N)
		{
			LL d=L[i],m;
				if (S[i]=='W')
				{
					w=1;
					ans+=d*3;
					sw+=d;
				}
				else
				if (S[i]=='G')
				{
					ans+=d*5;
					m=min(sw-sg2,d);
					sg2+=m, d-=m;
					sg1+=d;
				}
				else
				{
					if (sg1+sg2+sw>=d)
					{
						ans+=d;
						m=min(sw,d);
						sw-=m, d-=m;
						m=min(sg1,d);
						sg1-=m, d-=m;
						sg2-=d;
							if (sg2>sw)
							{
								m=sg2-sw;
								sg2-=m;
								sg1+=m;
							}
					}
					else
					{
						LL ex=d-(sg1+sg2+sw);
						ans+=d + ex*(w ? 3 : 5);
						sg1=sg2=sw=0;
					}
				}
		}
	ans-=sg1*2 + sg2*3 + sw;
	cout << ans << endl;
	return(0);
}