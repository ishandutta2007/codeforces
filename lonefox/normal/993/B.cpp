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

int A1[20],A2[20],B1[20],B2[20];

int Com(int i,int j)
{
	int a1=A1[i],a2=A2[i];
	int b1=B1[j],b2=B2[j];
		if (a1==b1 && a2==b2 || a1==b2 && a2==b1)
			return(0);
		if (a1==b1 || a1==b2)
			return(a1);
		if (a2==b1 || a2==b2)
			return(a2);
	return(0);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z;
	set<int> S;
	Read(N),Read(M);
		Fox(i,N)
			Read(A1[i]),Read(A2[i]);
		Fox(i,M)
			Read(B1[i]),Read(B2[i]);
		Fox(i,N)
		{
			int c=-1;
				Fox(j,M)
				{
					k=Com(i,j);
						if (k)
							if (c<0)
								c=k;
							else
							if (c!=k)
								c=0;
				}
				if (c<0)
					continue;
				if (!c)
					goto None;
			S.insert(c);
		}
		Fox(j,M)
		{
			int c=-1;
				Fox(i,N)
				{
					k=Com(i,j);
						if (k)
							if (c<0)
								c=k;
							else
							if (c!=k)
								c=0;
				}
				if (c<0)
					continue;
				if (!c)
					goto None;
			S.insert(c);
		}
		if (Sz(S)==1)
			printf("%d\n",*S.begin());
		else
			printf("0\n");
	return(0);
None:;
	printf("-1\n");
	return(0);
}