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

double C,T;
PR P[100];
double dyn[101][1001];
double pw[101];

vector<double> sol;

void Solve(double a,double b,double c)
{
	sol.clear();
		if (b*b-4*a*c<-EPS)
			return;
	double s=sqrt(b*b-4*a*c);
	sol.pb((-b-s)/(2*a));
	sol.pb((-b+s)/(2*a));
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z,v,t;
	double d;
		Fox(i,101)
			pw[i]=pow((double)1/0.9,i+1);
	Read(t);
		while (t--)
		{
			Read(N);
			cin >> C >> T;
			M=0;
				Fox(i,N)
					Read(P[i].x),Read(P[i].y),M+=P[i].y;
			sort(P,P+N);
			reverse(P,P+N);
				Fox(i,N+1)
					Fox(j,M+1)
						dyn[i][j]=1e15;
			dyn[0][0]=0;
			M=1;
				Fox(i,N)
				{
					a=P[i].x;
					b=P[i].y;
						FoxR(j,i+1)
							Fox(k,M)
								if ((d=dyn[j][k])<1e14)
									Min(dyn[j+1][k+b],d+10+a*pw[j]);
					M+=b;
				}
			M--;
			int ans=0;
				FoxR1(k,M)
					Fox1(j,N)
						if ((d=dyn[j][k])<1e14)
						{
							d=dyn[j][k];
								if (d<T+EPS)
								{
									ans=k;
									goto Done;
								}
							d-=j*10;
							double t2=T-j*10;
							Solve(-C,C*t2-1,t2-d);
								Fox(a,Sz(sol))
								{
									double r=sol[a];
										if (r>EPS && d/(1+C*r)+j*10<T+EPS)
										{
											ans=k;
											goto Done;
										}
								}
						}
Done:;
			printf("%d\n",ans);
		}
	return(0);
}