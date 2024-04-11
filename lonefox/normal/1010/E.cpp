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

#define MOD 1000000007
#define LIM 200005

int X1,Y1,Z1,X2,Y2,Z2;
pair<int,PR> P[LIM];
pair<PR,PR> Q[LIM];
pair<PR,PR> E[LIM];
set<PR> S;
set<PR>::iterator I,J,K;
int ans[LIM]; // -1/0/1/2 = unfilled/open/closed/unknown

void Flip(int &v)
{
	v=-v;
}

void Insert(int x,int y)
{
	Max(x,Y2);
	Max(y,Z2);
	I=S.lower_bound(mp(x+1,-INF)),I--;
		if (y>=(I->y))
			return;
		if (x!=I->x)
			I++;
		while (y<=(I->y))
		{
			J=I,I++;
			S.erase(J);
		}
	S.insert(mp(x,y));
}

void Handle(int i,int x,int y)
{
	Max(x,Y2);
	Max(y,Z2);
		if (i<0)
		{
			Insert(x,y);
			return;
		}
		if (ans[i]>=0)
			return;
	I=S.lower_bound(mp(x+1,-INF)),I--;
		if (y<(I->y))
			ans[i]=2;
		else
			ans[i]=1;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K,NE;
	int i,j,k,x,y,z,a,b,c;
	int mx,my,mz;
	Read(i),Read(i),Read(i);
	Read(N),Read(M),Read(K);
	X1=Y1=Z1=INF;
	X2=Y2=Z2=-INF;
		while (N--)
		{
			Read(x),Read(y),Read(z);
			Min(X1,x);
			Min(Y1,y);
			Min(Z1,z);
			Max(X2,x);
			Max(Y2,y);
			Max(Z2,z);
		}
		Fox(i,M)
		{
			Read(x),Read(y),Read(z);
				if ((X1<=x) && (x<=X2) && (Y1<=y) && (y<=Y2) && (Z1<=z) && (z<=Z2))
				{
					printf("INCORRECT\n");
					return(0);
				}
			P[i]=mp(x,mp(y,z));
		}
	Fill(ans,-1);
		Fox(i,K)
		{
			Read(x),Read(y),Read(z);
				if ((X1<=x) && (x<=X2) && (Y1<=y) && (y<=Y2) && (Z1<=z) && (z<=Z2))
					ans[i]=0;
			Q[i]=mp(mp(x,i),mp(y,z));
		}
		Fox(mx,2)
		{
			Flip(X1),Flip(X2);
			swap(X1,X2);
				Fox(i,M)
					Flip(P[i].x);
				Fox(i,K)
					Flip(Q[i].x.x);
				Fox(my,2)
				{
					Flip(Y1),Flip(Y2);
					swap(Y1,Y2);
						Fox(i,M)
							Flip(P[i].y.x);
						Fox(i,K)
							Flip(Q[i].y.x);
					Fox(mz,2)
					{
						Flip(Z1),Flip(Z2);
						swap(Z1,Z2);
							Fox(i,M)
								Flip(P[i].y.y);
							Fox(i,K)
								Flip(Q[i].y.y);
						// form set of points within X1..X2 range
						NE=0;
						S.clear();
						S.insert(mp(-INF,INF));
						S.insert(mp(INF,-INF));
							Fox(i,M)
								if (P[i].x>=X1 && P[i].y.x>=Y1 && P[i].y.y>=Z1)
									if (P[i].x<=X2)
										Insert(P[i].y.x,P[i].y.y);
									else
										E[NE++]=mp(mp(P[i].x,-1),P[i].y);
						// include queries
							Fox(i,K)
								if (Q[i].x.x>=X1 && Q[i].y.x>=Y1 && Q[i].y.y>=Z1)
									E[NE++]=Q[i];
						// line sweep over X2+
						sort(E,E+NE);
							Fox(i,NE)
								Handle(E[i].x.y,E[i].y.x,E[i].y.y);
					}
				}
		}
	printf("CORRECT\n");
		Fox(i,K)
			if (ans[i]==0)
				printf("OPEN\n");
			else
			if (ans[i]==1)
				printf("CLOSED\n");
			else
				printf("UNKNOWN\n");
	return(0);
}