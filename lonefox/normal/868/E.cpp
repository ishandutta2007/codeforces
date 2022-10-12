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

int S,K;
int cc,O[50],cnt[50],req[50];
vector<int> con[50];
int dist[50][50],ind[50],dyn[51][51],dyn2[51][51];

void rec(int i,int p)
{
	cc+=cnt[i];
		if (ind[i]==1)
			O[K++]=i;
	int j,k;
		Fox(j,Sz(con[i]))
			if ((k=con[i][j])!=p)
				rec(k,i);
		if (p==S)
			req[K]=cc;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	int i,j,k;
	int a,b,c,r;
	Fill(dist,60);
	Read(N);
		Fox(i,N-1)
		{
			Read(a),Read(b),Read(c);
			a--,b--;
			con[a].pb(b);
			con[b].pb(a);
			ind[a]++;
			ind[b]++;
			dist[a][b]=dist[b][a]=c;
		}
	Read(S),Read(M),S--;
		Fox(i,M)
			Read(j),j--,cnt[j]++;
		Fox(i,N)
			dist[i][i]=0;
		Fox(i,N)
			Fox(j,N)
				Fox(k,N)
					Min(dist[j][k],dist[j][i]+dist[i][k]);
	Fill(req,-1);
	rec(S,-1);
	Fill(dyn[0],0);
		Fox1(a,M-1)
			Fox(b,K)
			{
				r=O[b];
				Fill(dyn2,0);
				dyn2[0][0]=INF;
					Fox(i,K)
						Fox(j,a+1)
						{
							Max(dyn2[i+1][j],dyn2[i][j]);
								if (O[i]!=r)
									FoxI(k,j+1,a)
										Max(dyn2[i+1][k],min(dyn2[i][j],dist[r][O[i]]+dyn[a-(k-j)][i]));
						}
				dyn[a][b]=dyn2[K][a];
			}
	a=M;
	r=S;
	Fill(dyn2,0);
	dyn2[0][0]=INF;
		Fox(i,K)
		{
			if (req[i]>=0)
				Fox(j,a+1)
					if (j!=req[i])
						dyn2[i][j]=0;
			Fox(j,a+1)
			{
				Max(dyn2[i+1][j],dyn2[i][j]);
					if (O[i]!=r)
						FoxI(k,j+1,a)
							Max(dyn2[i+1][k],min(dyn2[i][j],dist[r][O[i]]+dyn[a-(k-j)][i]));
			}
		}
	printf("%d\n",dyn2[K][a]);
	return(0);
}