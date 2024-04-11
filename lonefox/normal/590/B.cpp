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

#define MOD 1000000007

#define LIM 1000

int X1,Y1,X2,Y2,dx,dy,M,T;

LD Calc(LD a)
{
	int i;
	LD DX=dx-X1*T;
	LD DY=dy-Y1*T;
	DX-=cos(a)*M*T;
	DY-=sin(a)*M*T;
	LD r1,r2,m;
	r1=0,r2=(LD)INF*INF;
		Fox(i,LIM)
		{
			m=(r1+r2)/2;
			LD dx2=DX-X2*m;
			LD dy2=DY-Y2*m;
			LD d=sqrt(Sqr(dx2)+Sqr(dy2));
				if (d<m*M)
					r2=m;
				else
					r1=m;
		}
	return(r1+T);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i;
	LD r1,r2,m,m1,m2,t1,t2;
	Read(X1),Read(Y1),Read(X2),Read(Y2);
	dx=X2-X1;
	dy=Y2-Y1;
	Read(M),Read(T);
	Read(X1),Read(Y1),Read(X2),Read(Y2);
		if (dx<0)
		{
			dx=-dx;
			X1=-X1;
			X2=-X2;
		}
		if (dy<0)
		{
			dy=-dy;
			Y1=-Y1;
			Y2=-Y2;
		}
	//1
	r1=0,r2=T+EPS;
		Fox(i,LIM)
		{
			m=(r1+r2)/2;
			LD dx2=dx-X1*m;
			LD dy2=dy-Y1*m;
			LD d=sqrt(Sqr(dx2)+Sqr(dy2));
				if (d<m*M)
					r2=m;
				else
					r1=m;
		}
		if (r1<T-EPS)
		{
			t1=r1;
			goto Done;
		}
	//2
	/*LD x;
		for (x=-PI/2; x<PI; x+=0.1)
		{
			printf("%.3Lf %.3Lf\n",x,Calc(x));
		}*/
	r1=-PI/2,r2=PI;
		Fox(i,LIM)
		{
			m1=(r1+r1+r2)/3;
			m2=(r1+r2+r2)/3;
			t1=Calc(m1);
			t2=Calc(m2);
				if (t1<t2)
					r2=m2;
				else
					r1=m1;
		}
Done:;
	cout << fixed << setprecision(9) << t1 << endl;
	return(0);
}