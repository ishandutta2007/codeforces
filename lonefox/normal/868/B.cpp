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

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int h,m,s,t1,t2;
	Read(h),Read(m),Read(s),Read(t1),Read(t2);
	h%=12;
	t1%=12;
	t2%=12;
	h*=2;
	t1*=2;
	t2*=2;
		if (m%5==0)
			m/=5,m*=2;
		else
			m/=5,m*=2,m++;
		if (s%5==0)
			s/=5,s*=2;
		else
			s/=5,s*=2,s++;
		if ((s) && (m%2==0))
			m++;
		if ((m) && (h%2==0))
			h++;
		if (t1>t2)
			swap(t1,t2);
	int i;
		FoxI(i,t1,t2)
			if ((i==h) || (i==m) || (i==s))
				goto Bad1;
	goto Yes;
Bad1:;
		FoxI(i,0,t1)
			if ((i==h) || (i==m) || (i==s))
				goto Bad2;
		FoxI(i,t2,23)
			if ((i==h) || (i==m) || (i==s))
				goto Bad2;
	goto Yes;
Bad2:;
	printf("NO\n");
	return(0);
Yes:;
	printf("YES\n");
	return(0);
}