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

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	int i,j,v,m,np=0;
	int V[5000];
	int A[5000],B[5000],C[5000],D[5000],good[5000]={0};
	Read(N),Read(M);
		Fox(i,M)
		{
			Read(A[i]),Read(B[i]),Read(C[i]),Read(D[i]);
				if (A[i]==1)
					good[i]=1;
		}
		Fox1(i,N)
		{
			v=0;
			m=INF;
				Fox(j,M)
					if (A[j]==1)
					{
						if ((B[j]<=i) && (i<=C[j]))
							v-=D[j];
					}
					else
						if ((B[j]<=i) && (i<=C[j]))
							Min(m,v+D[j]);
			V[i-1]=v=m;
				Fox(j,M)
					if (A[j]==1)
					{
						if ((B[j]<=i) && (i<=C[j]))
							v+=D[j];
					}
					else
						if ((B[j]<=i) && (i<=C[j]))
							if (v==D[j])
								good[j]=1;
		}
		Fox(j,M)
			if (!good[j])
				goto No;
	printf("YES\n");
		Fox(i,N)
			printf("%d%c",V[i],i==N-1 ? '\n' : ' ');
	return(0);
No:;
	printf("NO\n");
	return(0);
}