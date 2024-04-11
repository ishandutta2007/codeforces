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

#define MOD 1000000007
#define LIM 200005
#define LIM2 600000

int P[LIM],nxt[LIM],V[LIM],pos[LIM],S[LIM][20];
int E[LIM2];
int sz,tree[LIM2];

int Query(int i,int r1,int r2,int a,int b)
{
		if (a<=r1 && r2<=b)
			return(tree[i]);
	i<<=1;
	int m=(r1+r2)>>1;
	int ret=INF;
		if (a<=m)
			Min(ret,Query(i,r1,m,a,b));
		if (b>m)
			Min(ret,Query(i+1,m+1,r2,a,b));
	return(ret);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K,Q;
	int i,j,k,a,b,c,x,y,z;
	Read(N),Read(M),Read(Q);
		Fox(i,N)
			Read(P[i]),P[i]--;
		Fox(i,N)
			nxt[P[i]]=P[(i+1)%N];
		Fox(i,M)
			Read(V[i]),V[i]--;
	Fill(pos,-1);
	Fill(S,-1);
	Fill(E,60);
		FoxR(i,M)
		{
			S[i][0]=pos[nxt[V[i]]];
			pos[V[i]]=i;
				Fox(k,19)
				{
					a=S[i][k];
						if (a<0)
							break;
					b=S[a][k];
						if (b<0)
							break;
					S[i][k+1]=b;
				}
			j=i,b=N-1;
				Fox(k,20)
				{
						if (b&1)
						{
							j=S[j][k];
								if (j<0)
									break;
						}
					b>>=1;
				}
				if (j>=0)
					E[i]=j;
		}
		for(sz=1;sz<M;sz<<=1);
		Fox(i,sz)
			tree[sz+i]=E[i];
		FoxR1(i,sz-1)
			tree[i]=min(tree[i<<1],tree[(i<<1)+1]);
		while (Q--)
		{
			Read(a),Read(b),a--,b--;
				if (Query(1,0,sz-1,a,b)<=b)
					printf("1");
				else
					printf("0");
		}
	printf("\n");
	return(0);
}