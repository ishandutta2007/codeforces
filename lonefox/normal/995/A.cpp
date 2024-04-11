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

int N,K;
int nans;
int ans1[LIM],ans2[LIM],ans3[LIM];
int G[4][50];
vector<PR> lst;

void Go(int i1,int j1,int i2,int j2)
{
	ans1[nans]=G[i1][j1];
	ans2[nans]=i2+1;
	ans3[nans++]=j2+1;
		if (G[i2][j2])
			G[i1][j1]=G[i2][j2]=0;
		else
			swap(G[i1][j1],G[i2][j2]);
}

void Rot()
{
	int i,j,i1,j1,i2,j2;
	lst.clear();
		Fox(i,N)
			lst.pb(mp(1,i));
		FoxR(i,N)
			lst.pb(mp(2,i));
		Fox(i,Sz(lst))
		{
			i1=lst[i].x;
			j1=lst[i].y;
			i2=lst[(i+1)%Sz(lst)].x;
			j2=lst[(i+1)%Sz(lst)].y;
				if (G[i1][j1] && !G[i2][j2])
					break;
		}
		Fox(j,Sz(lst)-1)
		{
			i1=lst[i].x;
			j1=lst[i].y;
			i2=lst[(i+1)%Sz(lst)].x;
			j2=lst[(i+1)%Sz(lst)].y;
				if (G[i1][j1] && !G[i2][j2])
					Go(i1,j1,i2,j2);
			i=(i+Sz(lst)-1)%Sz(lst);
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,k,c;
	Read(N),Read(K);
		Fox(i,4)
			Fox(j,N)
				Read(G[i][j]);
		if (K==2*N)
		{
				Fox1(i,2)
				{
					k=i==1 ? 0 : 3;
						Fox(j,N)
							if (G[i][j]==G[k][j])
							{
								Go(i,j,k,j);
								goto Good;
							}
				}
			printf("-1\n");
			return(0);
Good:;
		}
	bool f=1;
		for(;;)
		{
				Fox(i,4)
					Fox(j,N)
						if (G[i][j])
							goto Cont;
			break;
Cont:;
				if (f)
					f=0;
				else
					Rot();
				for (i=0; i<=3; i+=3)
					Fox(j,N)
						if (c=G[i][j])
						{
							k=i==0 ? 1 : 2;
								if (G[k][j]==c)
									Go(k,j,i,j);
						}
		}
	printf("%d\n",nans);
		Fox(i,nans)
			printf("%d %d %d\n",ans1[i],ans2[i],ans3[i]);
	return(0);
}