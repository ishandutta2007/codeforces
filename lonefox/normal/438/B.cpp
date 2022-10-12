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
const double EPS = 1e-9;
const LD PI = acos(-1.0);

#define MOD 1000000007

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

LL cross(LL x1,LL y1,LL x2,LL y2)
{
	return(x1*y2 - x2*y1);
}

#define LIM 100005

int par[LIM],rank[LIM],siz[LIM];

void Make(int i)
{
	rank[i]=0;
	siz[i]=1;
}

int Find(int i)
{
		if (par[i]!=i)
			par[i]=Find(par[i]);
	return(par[i]);
}

void Merge(int i,int j)
{
	i=Find(i);
	j=Find(j);
		if (rank[i]<rank[j])
		{
			par[i]=j;
			siz[j]+=siz[i];
		}
		else
		{
				if (rank[i]==rank[j])
					rank[i]++;
			par[j]=i;
			siz[i]+=siz[j];
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	int i,j,k,a,s,v;
	LD ans=0;
	static int c,cur[LIM];
	static PR V[LIM];
	static vector<int> con[LIM];
	Fill(par,-1);
	Read(N),Read(M);
		Fox(i,N)
		{
			Read(V[i].x);
			V[i].y=i;
			Make(i);
		}
		while (M--)
		{
			Read(i),Read(j),i--,j--;
			con[i].pb(j);
			con[j].pb(i);
		}
	sort(V,V+N);
		FoxR(i,N)
		{
			v=V[i].x;
			j=V[i].y;
			c=0;
			par[j]=j;
				Fox(k,Sz(con[j]))
				{
					a=con[j][k];
						if (par[a]>=0)
							cur[c++]=Find(a);
				}
			sort(cur,cur+c);
			c=unique(cur,cur+c)-cur;
			s=0;
				Fox(k,c)
					s+=siz[cur[k]];
			ans+=(LD)v*s*2;
				Fox(a,c)
				{
					k=cur[a];
					ans+=(LD)v*siz[k]*(s-siz[k]);
					Merge(j,k);
				}
		}
	cout << fixed << setprecision(8) << ans/(LD)N/(LD)(N-1) << endl;
	return(0);
}