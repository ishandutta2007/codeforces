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
#define MOD 1000000007

PR gcd(int a,int b)
{
		if (!b)
			return(mp(1,0));
	PR p=gcd(b,a%b);
	return(mp(p.y,p.x-p.y*(a/b)));
}

static int fact[LIM],ifact[LIM],pw[LIM];

int ch(int n,int k)
{
		if ((k<0) || (k>n))
			return(0);
	return((LL)fact[n]*ifact[k]%MOD * ifact[n-k]%MOD);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,K;
	int i,d,p,m,ans=0;
	static char S[LIM];
	Read(N),Read(K);
	scanf("%s",&S);
		Fox(i,N+1)
		{
				if (i)
					fact[i]=(LL)fact[i-1]*i%MOD;
				else
					fact[i]=1;
			ifact[i]=gcd(fact[i],MOD).x;
				if (ifact[i]<0)
					ifact[i]+=MOD;
		}
	pw[0]=1;
		Fox1(i,N)
			pw[i]=(LL)pw[i-1]*10%MOD;
		/*Fox(i,N)
		{
			d=S[N-i-1]-'0';
				Fox1(p,i+1)
				{
						if (p==i+1)
							m=ch(N-p,K);
						else
							m=ch(N-p-1,K-1);
					ans=(ans + (LL)m*d%MOD * pw[p-1]%MOD)%MOD;
				}
		}
	int ans2=ans;
	ans=0;*/
		Fox(i,N)
		{
			d=S[N-i-1]-'0';
			p=i+1;
			m=ch(N-p,K);
			ans=(ans + (LL)m*d%MOD * pw[p-1]%MOD)%MOD;
		}
	d=0;
		FoxR1(p,N-1)
		{
			d+=S[N-p-1]-'0';
			d%=MOD;
			m=ch(N-p-1,K-1);
			ans=(ans + (LL)m*d%MOD * pw[p-1]%MOD)%MOD;
		}
		/*if (ans!=ans2)
			printf("BAD!\n");*/
	printf("%d\n",ans);
	return(0);
}