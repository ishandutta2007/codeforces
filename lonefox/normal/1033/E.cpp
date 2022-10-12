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

#define MOD 998244353
#define LIM 606

int col[LIM],prv[LIM];
vector<int> con[LIM];
vector<int> S[2];
bool done[LIM];
bool vis[LIM];

int Query(vector<int> v)
{
	int j;
	printf("? %d\n",Sz(v));
		Fox(j,Sz(v))
			printf("%d%c",v[j],j==Sz(v)-1?'\n':' ');
	cout.flush();
	Read(j);
		if (j<0)
			for(;;);
	return(j);
}

int QueryFrom(int i,vector<int> v)
{
	int q1=Query(v);
	vector<int> v2=v;
	v2.pb(i);
	int q2=Query(v2);
	return(q2-q1);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int T,N,K;
	int i,j,k,a,b,c,x,y,z,s,p;
	int r1,r2,m;
	vector<int> v,v2,cyc;
	queue<int> Q;
	Read(N);
	Fill(col,-1);
	col[1]=0;
	S[0].pb(1);
		while (Sz(S[0])+Sz(S[1])<N)
		{
			// find node to look from
				Fox1(i,N)
					if ((col[i]>=0) && (!done[i]))
						break;
			// find potential new nodes
			v.clear();
				Fox1(j,N)
					if (col[j]<0)
						v.pb(j);
			// not connected to any?
			//printf("  search from %d\n",i);
				if (!QueryFrom(i,v))
				{
					done[i]=1;
					continue;
				}
			// BS for one connected
			r1=0,r2=Sz(v)-1;
				while (r2>r1)
				{
					m=(r1+r2)>>1;
					v2.clear();
						FoxI(j,r1,m)
							v2.pb(v[j]);
						if (QueryFrom(i,v2))
							r2=m;
						else
							r1=m+1;
				}
			//printf("   found %d %d\n",i,v[r1]);
			// add it
			j=v[r1];
			col[j]=c=1-col[i];
			S[c].pb(j);
			con[i].pb(j);
			con[j].pb(i);
			// check it
				if (Sz(S[c])>1)
					if (Query(S[c]))
					{
						// bad, find existing connected
							Fox(a,Sz(S[c])-1)
							{
								v.clear();
								v.pb(i=S[c][a]);
									if (QueryFrom(j,v))
										goto Found;
							}
							for(;;);
Found:;
						// find cycle
						Q.push(i),vis[i]=1;
							while (!Q.empty())
							{
								a=Q.front(),Q.pop();
									if (a==j)
										break;
									Fox(b,Sz(con[a]))
										if (!vis[c=con[a][b]])
											Q.push(c),vis[c]=1,prv[c]=a;
							}
						cyc.clear();
							while (j!=i)
							{
								cyc.pb(j);
								j=prv[j];
							}
						cyc.pb(i);
							if (Sz(cyc)%2==0)
								for(;;);
						printf("N %d\n",Sz(cyc));
							Fox(i,Sz(cyc))
								printf("%d%c",cyc[i],i==Sz(cyc)-1?'\n':' ');
						cout.flush();
						return(0);
					}
		}
	// output
	printf("Y %d\n",Sz(S[0]));
		Fox(i,Sz(S[0]))
			printf("%d%c",S[0][i],i==Sz(S[0])-1?'\n':' ');
	cout.flush();
	return(0);
}