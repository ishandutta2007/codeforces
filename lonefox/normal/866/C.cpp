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

LD dyn[51][5001];
int F[50],S[50];
LD P[50];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,R;
	int i,j;
	LD v,d;
	LD ansV=0,ansD=(LD)INF*INF;
	LD r1,r2,m;
	Read(N),Read(R);
		Fox(i,N)
		{
			Read(F[i]),Read(S[i]);
			Read(j);
			P[i]=(LD)j/100;
		}
		Fox(i,N+1)
			Fox(j,R+1)
				dyn[i][j]=i==N ? 0 : (LD)INF*INF;
	r1=0,r2=(LD)INF*INF;
		while (ansD>EPS)
		{
			m=(r1+r2)/2;
				FoxR(i,N)
					FoxR(j,R)
						if (j+F[i]<=R)
						{
							dyn[i][j]=P[i]*(dyn[i+1][j+F[i]]+F[i]);
							v=m;
								if (j+S[i]<=R)
									Min(v,dyn[i+1][j+S[i]]);
							dyn[i][j]+=(1-P[i])*(S[i]+v);
						}
			d=dyn[0][0]-m;
				if (d<ansD)
				{
					ansD=Abs(d);
					ansV=m;
				}
				if (d>0)
					r1=m;
				else
					r2=m;
		}
	cout << fixed << setprecision(9) << ansV << endl;
	return(0);
}