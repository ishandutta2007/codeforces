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

#define LIM 2005

int nn,nc;
int ind[LIM],low[LIM],comp[LIM],val[LIM];
vector <pair<int,bool> > con[LIM];
vector <int> con2[LIM];

int Find_Bridges(int i,int p) //return the edge index from this node to its parent
{
	int j,k,r,e=0;
	//set this node's DFS index
	ind[i]=low[i]=nn++;
	//iterate over all neighbours
		Fox(j,Sz(con[i]))
			if ((k=con[i][j].x)==p)
				e=j;
			else
			if (ind[k]<0)
			{
				r=Find_Bridges(k,i);
				Min(low[i],low[k]);
					if (low[k]==ind[k]) //check if the edge to this child is a bridge
					{
						con[i][j].y=1;
						con[k][r].y=1;
					}
			}
			else
				Min(low[i],ind[k]);
	return(e);
}

void Make_Component(int i)
{
	int j,k;
	//set this node's component index
	comp[i]=nc;
	val[nc]++;
	//recurse to all neighbours in the same component
		Fox(j,Sz(con[i]))
			if ((!con[i][j].y) && (comp[k=con[i][j].x]<0))
				Make_Component(k);
}

PR rec(int i,int p)
{
	int j,k,v=0,s=val[i];
	PR r;
		Fox(j,Sz(con2[i]))
		{
			k=con2[i][j];
				if (k==p)
					continue;
			r=rec(k,i);
			s+=r.y;
			v+=r.x;
			v+=val[i]*r.y;
		}
	return(mp(v,s));
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	int i,j,k,s,ans,c,cur,cur2;
	PR p;
	int cnt[LIM];
	bool dyn[LIM];
	Fill(ind,-1);
	Fill(comp,-1);
	Read(N),Read(M);
		while (M--)
		{
			Read(i),Read(j),i--,j--;
			con[i].pb(mp(j,0));
			con[j].pb(mp(i,0));
		}
	Find_Bridges(0,-1);
		Fox(i,N)
			if (comp[i]<0)
			{
				Make_Component(i);
				nc++;
			}
		Fox(i,N)
			Fox(j,Sz(con[i]))
				if (comp[i]!=(k=comp[con[i][j].x]))
					con2[comp[i]].pb(k);
	ans=0;
		Fox(i,nc)
		{
			c=cur=s=0;
				Fox(j,Sz(con2[i]))
				{
					p=rec(con2[i][j],i);
					cur+=p.x;
					cnt[c++]=p.y;
					s+=p.y;
				}
			Fill(dyn,0);
			dyn[0]=1;
				Fox(j,c)
					FoxR(k,N)
						if (dyn[k])
							dyn[k+cnt[j]]=1;
			cur2=0;
				Fox(j,N+1)
					if (dyn[j])
						Max(cur2,j*(s-j));
			cur2+=val[i]*s;
			Max(ans,cur+cur2);
		}
		Fox(i,nc)
			ans+=Sqr(val[i]);
	printf("%d\n",ans);
	return(0);
}