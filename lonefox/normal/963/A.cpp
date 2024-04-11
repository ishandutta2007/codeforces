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

#define MOD 1000000009
#define LIM 200005

pair<LL,LL> gcd(LL a,LL b)
{
		if (!b)
			return(mp(1,0));
	pair<LL,LL> p=gcd(b,a%b);
	return(mp(p.y,p.x-(a/b)));
}

int Exp(int a,int b)
{
	int p=a,v=1;
		while (b)
		{
				if (b&1)
					v=(LL)v*p%MOD;
			p=(LL)p*p%MOD;
			b>>=1;
		}
	return(v);
}

int Inv(int a)
{
	/*LL p=gcd(a,MOD).x;
	return((p%MOD+MOD)%MOD);*/
	return(Exp(a,MOD-2));
}

int Div(int a,int b)
{
	return((LL)a*Inv(b)%MOD);
}

int Geom(int a,int r,int n)
{
		if (r==1)
			return((LL)a*n%MOD);
	int num=(1-Exp(r,n)+MOD)%MOD;
	int den=(1-r+MOD)%MOD;
	return((LL)a*Div(num,den)%MOD);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K,A,B;
	int i,j,k,a,b,c,x,y,z;
	static char S[LIM];
	Read(N),Read(A),Read(B),Read(K);
	scanf("%s",&S);
	M=(N+1)/K;
	int r=Div(Exp(B,K),Exp(A,K));
	int ans=0;
		Fox(i,K)
		{
			a=(LL)Exp(A,N-i)*Exp(B,i)%MOD;
			int cur=Geom(a,r,M);
				if (S[i]=='+')
					ans=(ans+cur)%MOD;
				else
					ans=(ans-cur+MOD)%MOD;
		}
	printf("%d\n",ans);
	return(0);
}