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

int gcd(int a,int b)
{
	return b ? gcd(b,a%b) : a;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N;
	int i,j,a,b;
	int V[2000],A[2000],B[2000];
	int c=0;
	Read(N);
		Fox(i,N)
		{
			Read(V[i]);
				if (V[i]==1)
					c++;
		}
		if (c)
		{
			printf("%d\n",N-c);
			return(0);
		}
		if (N==1)
		{
			printf("-1\n");
			return(0);
		}
	a=V[0];
		Fox(i,N)
		{
			a=gcd(a,V[i]);
				if (a==1)
					break;
		}
		if (a>1)
		{
			printf("-1\n");
			return(0);
		}
	int ans=INF;
		Fox(i,N-1)
		{
			a=b=0;
			A[a++]=V[i];
				FoxR(j,i)
					A[a++]=gcd(A[a-1],V[j]);
			B[b++]=V[i+1];
				FoxI(j,i+1,N-1)
					B[b++]=gcd(B[b-1],V[j]);
			b-=2;
				Fox(j,a)
				{
					while ((b) && (gcd(A[j],B[b])==1))
						b--;
					if (gcd(A[j],B[b+1])==1)
						Min(ans,j+b+N);
				}
		}
		if (ans==INF)
			ans=-1;
	printf("%d\n",ans);
	return(0);
}