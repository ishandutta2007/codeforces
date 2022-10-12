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
#define LIM 1000005

pair<PR,LL> P[LIM];
LL X[LIM];
LL dyn[LIM];
int Qs,Qe,Q[LIM];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	int i,j,k,b,c,z,p;
	LL x,y,a;
	Read(N);
	//N=1000;
		Fox(i,N)
			Read(P[i].x.x),Read(P[i].x.y),ReadLL(P[i].y);
			//P[i].x.x=i*100+rand()%10, P[i].x.y=(1000-i)*100+rand()%10, P[i].y = rand()%(P[i].x.x*P[i].x.y);
	sort(P,P+N);
	LL ans=0;
		Fox(i,N)
		{
			X[i]=x=P[i].x.x;
			y=P[i].x.y;
			a=P[i].y;
				/*Fox(j,i)
					Max(dyn[i],dyn[j]-X[j]*y);
			dyn[i]+=x*y-a;
			Max(ans,dyn[i]);*/
				while (Qs+1<Qe)
				{
					LL v1=dyn[Q[Qs]]-X[Q[Qs]]*y;
					LL v2=dyn[Q[Qs+1]]-X[Q[Qs+1]]*y;
						if (v2>=v1)
							Qs++;
						else
							break;
				}
				if (Qs<Qe)
					Max(dyn[i],dyn[Q[Qs]]-X[Q[Qs]]*y);
			dyn[i]+=x*y-a;
			Max(ans,dyn[i]);
				if (Qs<Qe && dyn[i]<=dyn[Q[Qe-1]])
				{
					//printf("SKIP\n");
					goto Skip;
				}
				while (Qs+1<Qe)
				{
					int p2=Q[Qe-2];
					int p1=Q[Qe-1];
					LD y1=(LD)(dyn[p2]-dyn[p1])/(X[p2]-X[p1]);
					LD y2=(LD)(dyn[p1]-dyn[i])/(X[p1]-X[i]);
						if (y2>y1-EPS)
							Qe--;
						else
							break;
						/*if ((dyn[i]-dyn[p1])*(X[p1]-X[p2]) >= (dyn[p1]-dyn[p2])*(X[i]-X[p1]))
							Qe--;
						else
							break;*/
				}
			Q[Qe++]=i;
Skip:;
				if (DEBUG)
				{
					LL cor=0;
						Fox(j,i)
							Max(cor,dyn[j]-X[j]*y);
					cor+=x*y-a;
						if (cor!=dyn[i])
							printf("WRONG\n");
				}
		}
	cout << ans << endl;
	return(0);
}

// dyn[i] = dyn[p] + (X[i] - X[p]) * Y[i] - A[i]
// dyn[i] = (dyn[p] - X[p] * Y[i]) + (X[i] * Y[i] - A[i])