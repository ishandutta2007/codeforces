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

int gcd(int a,int b)
{
	return(b ? gcd(b,a%b) : a);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int a,b,x1,y1,x2,y2,a2,b2,v,g;
	int X1,Y1,X2,Y2;
	Read(a),Read(b);
	a2=Sqr(a),b2=Sqr(b);
		Fox1(x1,a)
		{
			v=a2-Sqr(x1);
			y1=sqrt((LD)v)+EPS;
				if ((Sqr(y1)==v) && (y1>0))
				{
					Fox1(x2,b)
					{
						v=b2-Sqr(x2);
						y2=sqrt((LD)v)+EPS;
							if ((Sqr(y2)==v) && (y2>0))
							{
								g=gcd(x1,y1);
								X1=x1/g;
								Y1=y1/g;
								g=gcd(x2,y2);
								X2=x2/g;
								Y2=y2/g;
									if ((X1==X2) && (Y1==Y2))
									{
											if ((x1==-y2) || (y1==x2))
												continue;
										printf("YES\n");
										printf("0 0\n");
										printf("%d %d\n",x1,y1);
										printf("%d %d\n",-y2,x2);
										return(0);
									}
							}
					}
				}
		}
	printf("NO\n");
	return(0);
}