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

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,z,a,b,c,m,p;
	static int x1[LIM],y1[LIM],x2[LIM],y2[LIM];
	static int X1[LIM],Y1[LIM],X2[LIM],Y2[LIM];
	static int XX1[LIM],YY1[LIM],XX2[LIM],YY2[LIM];
	int xx1,yy1,xx2,yy2;
	Read(N);
	X1[0]=Y1[0]=XX1[N+1]=YY1[N+1]=-INF;
	X2[0]=Y2[0]=XX2[N+1]=YY2[N+1]=INF;
		Fox1(i,N)
		{
			Read(x1[i]),Read(y1[i]),Read(x2[i]),Read(y2[i]);
			X1[i]=max(X1[i-1],x1[i]);
			Y1[i]=max(Y1[i-1],y1[i]);
			X2[i]=min(X2[i-1],x2[i]);
			Y2[i]=min(Y2[i-1],y2[i]);
		}
		FoxR1(i,N)
		{
			XX1[i]=max(XX1[i+1],x1[i]);
			YY1[i]=max(YY1[i+1],y1[i]);
			XX2[i]=min(XX2[i+1],x2[i]);
			YY2[i]=min(YY2[i+1],y2[i]);
		}
		Fox1(i,N)
		{
			xx1=max(X1[i-1],XX1[i+1]);
			yy1=max(Y1[i-1],YY1[i+1]);
			xx2=min(X2[i-1],XX2[i+1]);
			yy2=min(Y2[i-1],YY2[i+1]);
				if ((xx1<=xx2) && (yy1<=yy2))
				{
					printf("%d %d\n",xx1,yy1);
					return(0);
				}
		}
	return(0);
}