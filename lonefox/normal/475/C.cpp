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
#define FoxR(i,n) for (i=n-1; i>=0; i--)
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

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

//#if DEBUG
#define GETCHAR getchar
/*#else
#define GETCHAR getchar_unlocked
#endif*/

void Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if (c=='-')
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
}

int N,M;
char G[1005][1005],tmp[1005][1005];

int Try(int sy,int sx,int w,int h)
{
	int i,j,k;
	Fill(tmp,0);
		Fox(i,h)
			Fox(j,w)
				tmp[sy+i][sx+j]=1;
	i=sy,j=sx;
Rep:;
		if (G[i][j+w]=='X')
		{
				Fox(k,h)
					tmp[i+k][j+w]=1;
			j++;
			goto Rep;
		}
		if (G[i+h][j]=='X')
		{
				Fox(k,w)
					tmp[i+h][j+k]=1;
			i++;
			goto Rep;
		}
		Fox(i,N)
			Fox(j,M)
				if (bool(G[i][j]=='X')!=bool(tmp[i][j]))
					return(INF);
	return(w*h);
}

int TryW(int sy,int sx,int w,int h)
{
	int i,j;
	i=sy;
	j=sx+w;
		while ((i<sy+h) && (G[i][j]!='X'))
			i++;
		if (i==sy+h)
			return(Try(sy,sx,w,1));
	return(Try(sy,sx,w,sy+h-i));
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,h,w,v,z,ans=INF;
	Read(N),Read(M);
		Fox(i,N)
			scanf("%s",&G[i]);
		Fox(z,2)
		{
				if (z)
				{
					swap(N,M);
						Fox(i,N)
							Fox(j,M)
								tmp[i][j]=G[j][i];
					memcpy(G,tmp,sizeof(G));
				}
				Fox(i,N)
					Fox(j,M)
						if (G[i][j]=='X')
							goto Out;
Out:;
			w=1;
				while (G[i][j+w]=='X')
					w++;
			h=1;
				while (G[i+h][j]=='X')
					h++;
			v=TryW(i,j,w,h);
			Min(ans,v);
		}
		if (ans>=INF)
			ans=-1;
	printf("%d\n",ans);
	return(0);
}