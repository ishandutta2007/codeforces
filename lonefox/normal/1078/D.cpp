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

#define MOD 998244353
#define LIM 1100005

int V[LIM];
int sz,tree[19][LIM][2];
int q1,q2;

void Update(int t,int i,int v1,int v2)
{
	i+=sz;
		while (i)
		{
			Min(tree[t][i][0],v1);
			Max(tree[t][i][1],v2);
			i>>=1;
		}
}

void Query(int t,int i,int r1,int r2,int a,int b)
{
		if (a<=r1 && r2<=b)
		{
			Min(q1,tree[t][i][0]);
			Max(q2,tree[t][i][1]);
			return;
		}
	i<<=1;
	int m=(r1+r2)>>1;
		if (a<=m)
			Query(t,i,r1,m,a,b);
		if (b>m)
			Query(t,i+1,m+1,r2,a,b);
}

void Query2(int t,int a,int b)
{
	q1=INF;
	q2=-INF;
	Query(t,1,0,sz-1,a,b);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,k2,x,y,z,a,b,c,w,t;
	Read(N);
	//N=100000;
		if (N==1)
		{
			printf("0\n");
			return(0);
		}
	M=N*3;
		for(sz=1;sz<M;sz<<=1);
		Fox(t,19)
			Fox(i,(sz<<1))
			{
				tree[t][i][0]=INF;
				tree[t][i][1]=-INF;
			}
		Fox(i,N)
		{
			int v;
			Read(v);
			//v=1;
				Fox(j,3)
				{
					k=N*j+i;
					Update(0,k,max(0,k-v),min(M-1,k+v));
				}
		}
		Fox(t,18)
			Fox(i,M)
			{
				Query2(t,i,i);
				a=q1,b=q2;
				Query2(t,a,b);
				Update(t+1,i,q1,q2);
			}
		Fox(i,N)
		{
			a=b=N+i;
			int ans=0;
				FoxR(t,19)
				{
					Query2(t,a,b);
						if (q2-q1<N-1)
						{
							a=q1;
							b=q2;
							ans+=(1<<t);
						}
				}
			printf("%d ",ans+1);
		}
	printf("\n");
	return(0);
}