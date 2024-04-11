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

#define LIM 100005

int N,M,QQ;
vector<int> lst;
int par[LIM][20];
int vv[LIM][20][10];
int sz[LIM][20];
vector<int> con[LIM];
int dep[LIM];

void Add(int i,int j)
{
	int k;
		Fox(k,sz[i][j])
			lst.pb(vv[i][j][k]);
}

int Go(int i,int d)
{
	int j=0;
		while (d)
		{
				if (d&1)
				{
					Add(i,j);
					i=par[i][j];
				}
			d>>=1,j++;
		}
	return(i);
}

void Solve(int i,int j,int m)
{
	lst.clear();
	int d1=dep[i];
	int d2=dep[j];
		if (d1>d2)
			i=Go(i,d1-d2);
		else
		if (d2>d1)
			j=Go(j,d2-d1);
	int k;
		FoxR(k,19)
			if (par[i][k]<0)
				continue;
			else
			if (par[i][k]!=par[j][k])
			{
				Add(i,k);
				Add(j,k);
				i=par[i][k];
				j=par[j][k];
			}
		if (i!=j)
		{
			Add(i,0);
			Add(j,0);
			i=par[i][0];
			j=par[j][0];
		}
		/*if (i!=j)
			printf("BAD\n");*/
	Add(i,0);
	sort(All(lst));
	Min(m,Sz(lst));
	printf("%d",m);
		Fox(i,m)
			printf(" %d",lst[i]);
	printf("\n");
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,k,a,x,y,z,X,Y;
	queue<int> Q;
	static vector<int> init[LIM];
	Read(N),Read(M),Read(QQ);
		Fox(i,N-1)
		{
			Read(j),Read(k);
			con[j].pb(k);
			con[k].pb(j);
		}
		Fox1(i,M)
		{
			Read(j);
			init[j].pb(i);
		}
		Fox1(i,N)
		{
			sort(All(init[i]));
			k=min(10,Sz(init[i]));
			sz[i][0]=k;
				Fox(j,k)
					vv[i][0][j]=init[i][j];
		}
	Fill(dep,-1);
	Fill(par,-1);
	Q.push(1),dep[1]=0;
		while (!Q.empty())
		{
			i=Q.front(),Q.pop();
				Fox(j,Sz(con[i]))
				{
					k=con[i][j];
						if (dep[k]<0)
							Q.push(k),dep[k]=dep[i]+1,par[k][0]=i;
				}
				Fox(j,19)
					if (par[i][j]<0)
						break;
					else
					{
						k=par[i][j];
							if (par[k][j]<0)
								break;
						par[i][j+1]=par[k][j];
						x=y=z=0;
						X=sz[i][j];
						Y=sz[k][j];
							while ((x<X) && (y<Y) && (z<10))
								if (vv[i][j][x]<vv[k][j][y])
									vv[i][j+1][z++]=vv[i][j][x++];
								else
									vv[i][j+1][z++]=vv[k][j][y++];
							while ((x<X) && (z<10))
								vv[i][j+1][z++]=vv[i][j][x++];
							while ((y<Y) && (z<10))
								vv[i][j+1][z++]=vv[k][j][y++];
						sz[i][j+1]=z;
					}
		}
		while (QQ--)
		{
			Read(i),Read(j),Read(k);
			Solve(i,j,k);
		}
	return(0);
}