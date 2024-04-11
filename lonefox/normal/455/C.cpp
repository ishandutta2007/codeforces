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

#define LIM 300005

int root[LIM],diam[LIM];

int Find(int i)
{
		if (root[i]!=i)
			root[i]=Find(root[i]);
	return(root[i]);
}

void Merge(int i,int j)
{
	i=Find(i);
	j=Find(j);
		if (i==j)
			return;
		if (rand()&1)
			swap(i,j);
	root[j]=i;
	int ci=(diam[i]+1)/2;
	int cj=(diam[j]+1)/2;
	diam[i]=max(diam[i],max(diam[j],ci+cj+1));
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a;
	int d,b,cur,ans;
	static vector <int> con[LIM];
	static bool vis[LIM]={0};
	static int dist1[LIM],dist2[LIM];
	queue<int> Q;
	Read(N),Read(M),Read(K);
		while (M--)
		{
			Read(i),Read(j);
			i--,j--;
			con[i].pb(j);
			con[j].pb(i);
		}
	Fill(dist1,-1);
	Fill(dist2,-1);
		Fox(i,N)
			if (!vis[i])
			{
				//dijkstra's 1 to find furthest node from i
				Q.push(i),dist1[i]=0;
					while (!Q.empty())
					{
						j=Q.front();
						Q.pop();
						vis[j]=1;
						root[j]=i;
						d=dist1[j];
							FoxR(k,Sz(con[j]))
							{
								a=con[j][k];
									if (dist1[a]<0)
										Q.push(a),dist1[a]=d+1;
							}
						k=j;
					}
				//dijkstra's 2 to find distances from that node
				Q.push(k),dist2[k]=0;
					while (!Q.empty())
					{
						j=Q.front();
						Q.pop();
						d=dist2[j];
							FoxR(k,Sz(con[j]))
							{
								a=con[j][k];
									if (dist2[a]<0)
										Q.push(a),dist2[a]=d+1;
							}
						k=j;
					}
				diam[i]=d;
			}
		while (K--)
		{
			Read(i);
				if (i==1)
				{
					Read(i),i--;
					printf("%d\n",diam[Find(i)]);
				}
				else
				{
					Read(i),Read(j);
					i--,j--;
					Merge(i,j);
				}
		}
	return(0);
}