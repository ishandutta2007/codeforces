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

#define LIM 100000

LL cross(LL x1,LL y1,LL x2,LL y2,LL x3,LL y3)
{
	LL X1=x2-x1;
	LL Y1=y2-y1;
	LL X2=x3-x1;
	LL Y2=y3-y1;
	return(X1*Y2 - X2*Y1);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	int i,j,k,b,h;
	bool f=1;
	static int H[LIM];
	static LL X[LIM],Y[LIM];
	static int dep[LIM],par[LIM];
	static int P[LIM][21];
	Fill(P,-1);
	Read(N);
		Fox(i,N)
			ReadLL(X[i]),ReadLL(Y[i]);
	dep[N-1]=0;
	h=0;
	H[h++]=N-1;
		FoxR(i,N-1)
		{
				while ((h>1) && (cross(X[i],Y[i],X[H[h-1]],Y[H[h-1]],X[H[h-2]],Y[H[h-2]])>0))
					h--;
			par[i]=H[h-1];
			dep[i]=dep[par[i]]+1;
			H[h++]=i;
			P[i][0]=par[i];
				Fox(j,20)
					if (P[P[i][j]][j]<0)
						break;
					else
						P[i][j+1]=P[P[i][j]][j];
		}
	Read(M);
		while (M--)
		{
				if (f)
					f=0;
				else
					printf(" ");
			Read(i),Read(j),i--,j--;
				if (dep[i]<dep[j])
				{
					k=dep[j]-dep[i];
					b=0;
						while (k)
						{
								if (k&1)
									j=P[j][b];
							b++,k>>=1;
						}
				}
				else
				if (dep[j]<dep[i])
				{
					k=dep[i]-dep[j];
					b=0;
						while (k)
						{
								if (k&1)
									i=P[i][b];
							b++,k>>=1;
						}
				}
			b=20;
				while (i!=j)
				{
						while ((b) && (P[i][b]==P[j][b]))
							b--;
					i=P[i][b];
					j=P[j][b];
				}
			printf("%d",i+1);
		}
	printf("\n");
	return(0);
}