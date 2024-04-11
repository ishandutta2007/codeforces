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

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,R,C;
	int i,j,y,x;
	int y1,x1,y2,x2;
	int ns,nn;
	int oy,ox;
	int tot;
	static char S[500005];
	static int X[500005],Y[500005];
	static int Y1[500005],X1[500005],Y2[500005],X2[500005];
	static int seq[500005],nxt[500005];
	Read(N),Read(R),Read(C);
	scanf("%s",&S);
	y=x=y1=x1=y2=x2=0;
		Fox(i,N)
		{
				if (S[i]=='U')
					y--;
				if (S[i]=='D')
					y++;
				if (S[i]=='L')
					x--;
				if (S[i]=='R')
					x++;
			X[i+1]=x;
			Y[i+1]=y;
			Y1[i+1]=min(Y1[i],y);
			X1[i+1]=min(X1[i],x);
			Y2[i+1]=max(Y2[i],y);
			X2[i+1]=max(X2[i],x);
		}
	int dy=Y2[N]-Y1[N];
	int dx=X2[N]-X1[N];
	int fx=x;
	int fy=y;
		if ((y==0) && (x==0) && (dy<R) && (dx<C))
		{
			printf("-1\n");
			return(0);
		}
	int ans=0;
	ns=0;
		Fox1(i,N)
			seq[ns++]=i;
	oy=ox=0;
	tot=0;
Rep:;
	nn=0;
		Fox(i,ns)
		{
			j=seq[i];
			y=Y[j]+oy;
			x=X[j]+ox;
				if ((y<y1) || (y>y2))
				{
					Min(y1,y);
					Max(y2,y);
					ans=(ans+(LL)(tot+j)*C)%MOD;
					R--;
						if (!R)
							goto Done;
					nxt[nn++]=j;
				}
				else
				if ((x<x1) || (x>x2))
				{
					Min(x1,x);
					Max(x2,x);
					ans=(ans+(LL)(tot+j)*R)%MOD;
					C--;
						if (!C)
							goto Done;
					nxt[nn++]=j;
				}
		}
	ns=nn;
	memcpy(seq,nxt,sizeof(int)*ns);
	oy+=fy;
	ox+=fx;
	tot=(tot+(LL)N)%MOD;
	goto Rep;
Done:;
	printf("%d\n",ans);
	return(0);
}