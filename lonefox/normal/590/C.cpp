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

#define LIM 100005

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	int i,j,y,x,z,d,v;
	int ans;
	static char G[1000][1002];
	static bool vis[1000][1000];
	static int dist[3][1000][1000];
	deque<PR> Q;
	int my[4]={-1,1,0,0};
	int mx[4]={0,0,-1,1};
	Read(N),Read(M);
		Fox(i,N)
			scanf("%s",&G[i]);
	Fill(dist,60);
		Fox(z,3)
		{
			Fox(i,N)
				Fox(j,M)
					if (G[i][j]=='1'+z)
						Q.push_front(mp(i,j)),dist[z][i][j]=0;
			Fill(vis,0);
			while (!Q.empty())
			{
				i=Q.front().x;
				j=Q.front().y;
				Q.pop_front();
					if (vis[i][j])
						continue;
				vis[i][j]=1;
				d=dist[z][i][j];
					Fox(v,4)
					{
						y=i+my[v];
						x=j+mx[v];
							if ((y<0) || (y==N) || (x<0) || (x==M) || (vis[y][x]) || (G[y][x]=='#'))
								continue;
							if (G[y][x]=='.')
							{
								if (dist[z][y][x]>d+1)
									Q.push_back(mp(y,x)),dist[z][y][x]=d+1;
							}
							else
							{
								if (dist[z][y][x]>d)
									Q.push_front(mp(y,x)),dist[z][y][x]=d;
							}
					}
			}
		}
	ans=INF;
		Fox(i,N)
			Fox(j,M)
			{
				d=0;
					Fox(z,3)
					{
							if (dist[z][i][j]>INF)
								goto Bad;
						d+=dist[z][i][j];
					}
					if (G[i][j]=='.')
						d-=2;
				Min(ans,d);
Bad:;
			}
	printf("%d\n",ans==INF ? -1 : ans);
	return(0);
}