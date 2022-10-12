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

#define LIM 1000000

int V[LIM];
int M[12]={31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,K;
	int i,j,k,a,b,x,y,z;
	char s1[100],s2[100];
	Read(x);
	scanf("%s %s",&s1,s2);
	b=0;
		if (s2[0]=='w')
			b=1;
	int d=1;
	int w=5;
	int c=0;
	int m=0;
		for(;;)
		{
			if (b)
			{
				if (w==x)
					c++;
			}
			else
			{
				if (d==x)
					c++;
			}
			w++;
				if (w==8)
					w=1;
			d++;
				if (d>M[m])
				{
					m++;
						if (m==12)
							break;
					d=1;
				}
		}
	printf("%d\n",c);
	return(0);
}