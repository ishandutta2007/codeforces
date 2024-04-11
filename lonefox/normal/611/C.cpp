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
	int N,M,Q;
	int i,j,a,b;
	int y1,x1,y2,x2;
	static char G[505][505];
	static int vert[505][505],hor[505][505];
	Read(N),Read(M);
		Fox(i,N)
			scanf("%s",&G[i]);
		Fox1(i,N)
			Fox1(j,M)
			{
				a=i-1;
				b=j-1;
					if ((a) && (G[a][b]=='.') && (G[a-1][b]=='.'))
						vert[i][j]=1;
					if ((b) && (G[a][b]=='.') && (G[a][b-1]=='.'))
						hor[i][j]=1;
				vert[i][j]+=vert[i-1][j] + vert[i][j-1] - vert[i-1][j-1];
				hor[i][j]+=hor[i-1][j] + hor[i][j-1] - hor[i-1][j-1];
			}
	Read(Q);
		while (Q--)
		{
			Read(y1),Read(x1),Read(y2),Read(x2);
			int v=0;
			v+=vert[y2][x2] - vert[y2][x1-1] - vert[y1][x2] + vert[y1][x1-1];
			v+=hor[y2][x2] - hor[y1-1][x2] - hor[y2][x1] + hor[y1-1][x1];
			printf("%d\n",v);
		}
	return(0);
}