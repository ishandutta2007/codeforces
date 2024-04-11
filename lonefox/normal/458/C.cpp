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
const double EPS = 1e-6;
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

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z,r;
	pair<int,PR> p;
	int ans=2*INF,cur,tot=0;
	static vector<int> V[LIM+1];
	static PR P[LIM+1];
	static int ind[LIM+1];
	set<pair<int,PR> > S;
	set<pair<int,PR> >::iterator I;
	Read(N);
		Fox(k,N)
		{
			Read(i),Read(j);
			V[i].pb(j);
		}
		Fox1(i,LIM)
		{
			sort(All(V[i]));
			P[i-1]=mp(Sz(V[i]),i);
				Fox(j,Sz(V[i]))
				{
					S.insert(mp(V[i][j],mp(i,j)));
					tot+=V[i][j];
				}
		}
	c=Sz(V[0]);
	sort(P,P+LIM);
	reverse(P,P+LIM);
	i=0;
	cur=0;
	k=Sz(S);
	I=S.end();
		FoxRI(z,c,N)
		{
				while ((i<LIM) && (P[i].x>=z))
					i++;
				Fox(j,i)
				{
					a=P[j].y;
					p=mp(V[a][ind[a]],mp(a,ind[a]));
						if ((I==S.end()) || (p<*I))
						{
							tot-=p.x;
							k--;
							S.erase(p);
						}
					cur+=V[a][ind[a]++];
					c++;
				}
			r=max(z-c,0);
				while (k>r)
				{
					I--;
					tot-=I->x;
					k--;
				}
			Min(ans,cur+tot);
		}
	printf("%d\n",ans);
	return(0);
}