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

int gcd(int a,int b)
{
	return(b ? gcd(b,a%b) : a);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N;
	int i,j,k,v,a;
	map<int,LL> M;
	static int V[100005],G[100005][20];
	Read(N);
		Fox(i,N)
		{
			Read(V[i]);
			G[i][0]=V[i];
		}
		FoxR(i,N)
		{
			j=0;
				while ((i+(1<<j)<N) && (G[i+(1<<j)][j]))
				{
					G[i][j+1]=gcd(G[i][j],G[i+(1<<j)][j]);
					j++;
				}
		}
		Fox(i,N)
		{
			j=i;
			v=V[i];
				while (j<N)
				{
						if (i!=j)
							v=gcd(v,V[j]);
					a=j+1;
						FoxR(k,20)
							if ((G[a][k]) && (G[a][k]%v==0))
								a+=1<<k;
					M[v]+=a-j;
					j=a;
				}
		}
	Read(N);
		while (N--)
		{
			Read(i);
			cout << M[i] << endl;
		}
	return(0);
}