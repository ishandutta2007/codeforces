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

int gcd(int a,int b)
{
	return(b ? gcd(b,a%b) : a);
}

LL lcm(int a,int b)
{
	return((LL)a*b/gcd(a,b));
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	LL N1,N2,lc,mult,ans=0;
	int M1,M2;
	int i,j,g,g1,g2,s;
	int cnt1[26],cnt2[26];
	static bool vis1[1000000],vis2[1000000];
	static char S1[1000005],S2[1000005];
	cin >> N1 >> N2;
	scanf("\n%s\n%s",&S1,&S2);
	M1=strlen(S1);
	M2=strlen(S2);
	lc=lcm(M1,M2);
	mult=N1*M1/lc;
	/*g1=lc/M1;
	g2=lc/M2;
	g=gcd(M1,M2);*/
		Fox(i,M1)
		{
			Fill(cnt1,0);
			Fill(cnt2,0);
			j=i;
				while (!vis1[j])
				{
					vis1[j]=1;
					cnt1[S1[j]-'a']++;
					j=(j+M2)%M1;
				}
			j=i;
				while (!vis2[j])
				{
					vis2[j]=1;
					cnt2[S2[j]-'a']++;
					j=(j+M1)%M2;
				}
			s=0;
				Fox(j,26)
					s+=cnt2[j];
				Fox(j,26)
					ans+=(LL)cnt1[j]*(s-cnt2[j]);
		}
	cout << ans*mult << endl;
	return(0);
}