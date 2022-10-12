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
#define LIM 4000

bool C[LIM];
int np,pr[LIM];
int V[LIM];
map<int,int> M,M2,M3;
map<int,int>::iterator I;

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,K;
	int i,j,k,x,y,z,a,b,c,v,m,s,p;
		FoxI(i,2,LIM-1)
			if (!C[i])
			{
				pr[np++]=i;
					for (j=i*i; j<LIM; j+=i)
						C[j]=1;
			}
	Read(N);
		Fox(k,N)
		{
			Read(v);
				Fox(i,np)
				{
					p=pr[i];
						if (p*p>v)
							break;
						if (v%p==0)
						{
							c=1;
							v/=p;
								while (v%p==0)
								{
									v/=p;
									c++;
								}
								if (!M[p])
									M[p]=INF;
								if (c<M[p])
									M[p]=c,M3[p]=1;
								else
								if (c==M[p])
									M3[p]++;
							M2[p]++;
						}
				}
				if (v>1)
				{
					c=1;
					p=v;
						if (!M[p])
									M[p]=INF;
								if (c<M[p])
									M[p]=c,M3[p]=1;
								else
								if (c==M[p])
									M3[p]++;
							M2[p]++;
				}
		}
	int ans=INF;
		Foxen(I,M)
		{
			m=M3[I->x];
				if (M2[I->x]<N)
					m=N-M2[I->x];
			Min(ans,m);
		}
		if (ans>=N)
			ans=-1;
	printf("%d\n",ans);
	return(0);
}