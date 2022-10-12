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

int N,K;
int V[25][3];
int cur[3];
PR p;
map<PR,PR> M;

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j;
	int p3,b,v;
	int ans1=-1,ans2=-1,ansv=-INF;
	Read(N);
	K=N/2;
		Fox(i,N)
			Fox(j,3)
				Read(V[i][j]);
		if (N==1)
		{
				if ((!V[0][0]) && (!V[0][1]))
				{
					printf("LM\n");
					return(0);
				}
				if ((!V[0][0]) && (!V[0][2]))
				{
					printf("LW\n");
					return(0);
				}
				if ((!V[0][2]) && (!V[0][1]))
				{
					printf("MW\n");
					return(0);
				}
			goto Imp;
		}
	p3=1;
		Fox(i,K)
			p3*=3;
		Fox(b,p3)
		{
			Fill(cur,0);
			v=b;
				Fox(i,K)
				{
						Fox(j,3)
							if (j!=v%3)
								cur[j]+=V[i][j];
					v/=3;
				}
			p=mp(cur[1]-cur[0],cur[2]-cur[0]);
				if (!M.count(p))
					M[p]=mp(cur[0],b);
				else
				if (M[p].x<cur[0])
					M[p]=mp(cur[0],b);
		}
	p3=1;
		Fox(i,N-K)
			p3*=3;
		Fox(b,p3)
		{
			Fill(cur,0);
			v=b;
				FoxI(i,K,N-1)
				{
						Fox(j,3)
							if (j!=v%3)
								cur[j]+=V[i][j];
					v/=3;
				}
			p=mp(cur[0]-cur[1],cur[0]-cur[2]);
				if (!M.count(p))
					continue;
			v=M[p].x+cur[0];
				if ((ans1<0) || (v>ansv))
				{
					ans1=M[p].y;
					ans2=b;
					ansv=v;
				}
		}
		if (ans1<0)
			goto Imp;
	Fill(cur,0);
	v=ans1;
		Fox(i,K)
		{
				if (v%3==0)
					printf("MW\n");
				if (v%3==1)
					printf("LW\n");
				if (v%3==2)
					printf("LM\n");
				Fox(j,3)
					if (j!=v%3)
						cur[j]+=V[i][j];
			v/=3;
		}
	v=ans2;
		FoxI(i,K,N-1)
		{
				if (v%3==0)
					printf("MW\n");
				if (v%3==1)
					printf("LW\n");
				if (v%3==2)
					printf("LM\n");
				Fox(j,3)
					if (j!=v%3)
						cur[j]+=V[i][j];
			v/=3;
		}
	/*printf("%d\n",ansv);
		Fox(i,3)
			printf("%d\n",cur[i]);*/
	return(0);
Imp:;
	printf("Impossible\n");
	return(0);
}