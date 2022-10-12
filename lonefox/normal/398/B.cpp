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
	int i,j,rc=0,cc=0;
	LD ans=0,p1,p2,p3,p4,q1,q2;
	static bool row[2000],col[2000];
	static LD dyn[2002][2002];
	Read(N),Read(M);
		while (M--)
		{
			Read(i),Read(j);
			i--,j--;
			row[i]=1;
			col[j]=1;
		}
		Fox(i,N)
		{
			if (row[i])
				rc++;
			if (col[i])
				cc++;
		}
		FoxRI(i,rc,N)
			FoxRI(j,cc,N)
			{
					if ((i==N) && (j==N))
						continue;
				q1=(LD)(N-i)/N;
				q2=(LD)(N-j)/N;
				p1=q1*(1-q2);
				p2=q2*(1-q1);
				p3=q1*q2;
				p4=(1-q1)*(1-q2);
				dyn[i][j]=(1 + dyn[i+1][j]*p1 + dyn[i][j+1]*p2 + dyn[i+1][j+1]*p3) / (1 - p4);
			}
	cout << fixed << setprecision(4) << dyn[rc][cc] << endl;
	return(0);
}