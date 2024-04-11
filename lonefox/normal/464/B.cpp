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

bool done;
int ord[8];
int V[8][3],cur[8][3],ans[8][3];

LL dist(LL x,LL y,LL z)
{
	return(Sqr(x)+Sqr(y)+Sqr(z));
}

bool test()
{
	int i,j;
	int c1,c2,c3;
	LL m;
	LL d[8][8];
	m=(LL)INF*INF;
		Fox(i,8)
			Fox(j,i)
			{
				d[i][j]=d[j][i]=dist(cur[i][0]-cur[j][0],cur[i][1]-cur[j][1],cur[i][2]-cur[j][2]);
				Min(m,d[i][j]);
			}
		if (!m)
			return(0);
		Fox(i,8)
		{
			c1=c2=c3=0;
				Fox(j,8)
					if (i!=j)
						if (d[i][j]==m)
							c1++;
						else
						if (d[i][j]==m*2)
							c2++;
						else
						if (d[i][j]==m*3)
							c3++;
						else
							return(0);
				if ((c1!=3) || (c2!=3) || (c3!=1))
					return(0);
		}
	return(1);
}

void rec(int i)
{
	int j;
		if (i==8)
		{
				Fox(j,8)
				{
					if (ord[j]==0)
					{
						cur[j][0]=V[j][0];
						cur[j][1]=V[j][1];
						cur[j][2]=V[j][2];
					}
					if (ord[j]==1)
					{
						cur[j][0]=V[j][0];
						cur[j][1]=V[j][2];
						cur[j][2]=V[j][1];
					}
					if (ord[j]==2)
					{
						cur[j][0]=V[j][1];
						cur[j][1]=V[j][0];
						cur[j][2]=V[j][2];
					}
					if (ord[j]==3)
					{
						cur[j][0]=V[j][1];
						cur[j][1]=V[j][2];
						cur[j][2]=V[j][0];
					}
					if (ord[j]==4)
					{
						cur[j][0]=V[j][2];
						cur[j][1]=V[j][0];
						cur[j][2]=V[j][1];
					}
					if (ord[j]==5)
					{
						cur[j][0]=V[j][2];
						cur[j][1]=V[j][1];
						cur[j][2]=V[j][0];
					}
				}
				if (test())
				{
					done=1;
					memcpy(ans,cur,sizeof(cur));
				}
			return;
		}
		Fox(j,6)
		{
			ord[i]=j;
			rec(i+1);
				if (done)
					break;
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j;
		Fox(i,8)
			Fox(j,3)
				Read(V[i][j]);
	rec(1);
		if (!done)
			printf("NO\n");
		else
		{
			printf("YES\n");
				Fox(i,8)
					Fox(j,3)
						printf("%d%c",ans[i][j],j==2 ? '\n' : ' ');
		}
	return(0);
}