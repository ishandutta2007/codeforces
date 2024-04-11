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

#define LIM 100000

int X[LIM],Y[LIM];
bool V[LIM];
PR A[LIM],B[LIM],C[LIM],D[LIM];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,K;
	int a,b,c,d,bb,cc,dd;
	int i,x,y,xx,yy;
	LL ans=(LL)INF*INF;
	vector<int> vb,vc,vd;
	Read(N),Read(K);
		Fox(i,N)
		{
			Read(x),Read(y),Read(xx),Read(yy);
			X[i]=x+xx;
			Y[i]=y+yy;
			A[i]=mp(Y[i],i);
			B[i]=mp(-Y[i],i);
			C[i]=mp(X[i],i);
			D[i]=mp(-X[i],i);
		}
	sort(A,A+N);
	sort(B,B+N);
	sort(C,C+N);
	sort(D,D+N);
		Fox(a,K+1)
		{
			bb=0;
			vb.clear();
				if (a)
					V[A[a-1].y]=1;
				Fox(b,K-a+1)
				{
					cc=0;
					vc.clear();
						if (b)
						{
								while (V[B[bb].y])
									bb++;
							vb.pb(B[bb].y);
							V[B[bb++].y]=1;
						}
						Fox(c,K-a-b+1)
						{
							dd=0;
							vd.clear();
								if (c)
								{
										while (V[C[cc].y])
											cc++;
									vc.pb(C[cc].y);
									V[C[cc++].y]=1;
								}
								Fox(d,K-a-b-c)
								{
										while (V[D[dd].y])
											dd++;
									vd.pb(D[dd].y);
									V[D[dd++].y]=1;
								}
								Fox(i,N)
									if (!V[A[i].y])
									{
										y=A[i].x;
										break;
									}
								Fox(i,N)
									if (!V[B[i].y])
									{
										yy=-B[i].x;
										break;
									}
								Fox(i,N)
									if (!V[C[i].y])
									{
										x=C[i].x;
										break;
									}
								Fox(i,N)
									if (!V[D[i].y])
									{
										xx=-D[i].x;
										break;
									}
							x=(xx-x+1)>>1;
							y=(yy-y+1)>>1;
							Max(x,1);
							Max(y,1);
							Min(ans,(LL)x*y);
								Fox(i,Sz(vd))
									V[vd[i]]=0;
						}
						Fox(i,Sz(vc))
							V[vc[i]]=0;
				}
				Fox(i,Sz(vb))
					V[vb[i]]=0;
		}
	cout << ans << endl;
	return(0);
}