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

int P[LIM],F[LIM],out[LIM];
LL C[LIM];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,O;
	LL K;
	int i,j,k,a,b,c,d,x,y,z;
	int r1,r2,m;
	Read(N),ReadLL(K);
	O=N;
	LL sum=(LL)N*(N+1)/2;
		if (sum==K)
		{
				Fox1(d,N)
					C[d]=1;
			goto Good;
		}
	r1=1,r2=N;
		while (r2>r1)
		{
			m=(r1+r2)>>1;
			LL p=1,s=0,n=N;
				Fox1(d,INF)
				{
					LL t=min(n,p);
					s+=d*t;
						if (s>K)
							break;
					n-=t;
						if (!n)
							break;
					p*=m;
				}
				if (s<=K)
					r2=m;
				else
					r1=m+1;
		}
		if (r1==1 || r1==N)
			goto No;
	LL B=r1;
	C[1]=1, K--, N--;
		FoxI(d,2,INF)
		{
				if (!N)
				{
						if (K)
							goto No;
					goto Good;
				}
			LL ch=min((LL)N,C[d-1]*B);
				while (ch>=1)
				{
					LL rem=N-ch;
					LL maxS=d*ch;
					maxS+=(d+1 + d+rem)*rem/2;
						if (maxS>=K)
							break;
					ch--;
				}
				if (!ch)
					goto No;
			C[d]=ch;
			N-=ch;
			K-=d*ch;
		}
	//make
Good:;
	i=1;
	F[1]=i++;
		FoxI(d,2,INF)
			if (!C[d])
				break;
			else
			{
				F[d]=i;
					Fox(k,C[d])
					{
						P[i++]=F[d-1];
							if ((++out[F[d-1]])==B)
								F[d-1]++;
					}
			}
	printf("Yes\n");
		FoxI(i,2,O)
			printf("%d ",P[i]);
	printf("\n");
	return(0);
No:;
	printf("No\n");
	return(0);
}