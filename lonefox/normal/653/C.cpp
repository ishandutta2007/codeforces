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

#define MOD 1000000007

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,a,b,c,v,nb=0;
	int ans=0;
	static int V[150005],bad[150005],orig[150005],nxt[150005];
	vector<int> B;
	set<PR> S;
	set<int> cur;
	Read(N);
		Fox(i,N)
			Read(V[i]);
		Fox(i,N-1)
			if ((i%2==0) && (V[i]>=V[i+1]) || (i%2==1) && (V[i]<=V[i+1]))
				bad[i]=bad[i+1]=orig[i]=1,nb++;
		Fox(i,N)
			if (bad[i])
				B.pb(i);
		if (Sz(B)>8)
			goto Done;
		Fox(j,Sz(B))
		{
			a=B[j];
				Fox(b,N)
				{
						if (a==b)
							continue;
						if (S.count(mp(a,b)))
							continue;
						/*if ((a<b) && (V[a]>=V[b]) || (a>b) && (V[a]<=V[b]))
							continue;*/
					swap(V[a],V[b]);
					cur.clear();
					c=nb;
						FoxI(i,a-2,a+2)
							if ((i>=0) && (i<N-1))
								nxt[i]=0;
						FoxI(i,b-2,b+2)
							if ((i>=0) && (i<N-1))
								nxt[i]=0;
						FoxI(i,a-2,a+2)
							if ((i>=0) && (i<N-1))
								if ((i%2==0) && (V[i]>=V[i+1]) || (i%2==1) && (V[i]<=V[i+1]))
									nxt[i]=1;
						FoxI(i,b-2,b+2)
							if ((i>=0) && (i<N-1))
								if ((i%2==0) && (V[i]>=V[i+1]) || (i%2==1) && (V[i]<=V[i+1]))
									nxt[i]=1;
						FoxI(i,a-2,a+2)
							if ((i>=0) && (i<N-1))
							{
									/*if (cur.count(i))
										continue;*/
								cur.insert(i);
								c+=nxt[i]-orig[i];
							}
						FoxI(i,b-2,b+2)
							if ((i>=0) && (i<N-1))
							{
									if (cur.count(i))
										continue;
								//cur.insert(i);
								c+=nxt[i]-orig[i];
							}
						if (!c)
							ans++;
Bad:;
					swap(V[a],V[b]);
					S.insert(mp(a,b));
					S.insert(mp(b,a));
				}
		}
Done:;
	printf("%d\n",ans);
	return(0);
}