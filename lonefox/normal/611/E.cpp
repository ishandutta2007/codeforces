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

int A,B,C;
int Y[5];

int buck(int v)
{
		if (v<=A)
			return(0);
		if (v<=B)
			return(1);
		if (v<=C)
			return(2);
		if (v<=A+C)
			return(3);
	return(4);
}

int Z[3],H[3];

int calc()
{
	int tot=0,c;
	int r1,r2,m;
	int i,j;
	//use B+C
	c=Y[4];
	tot+=c;
	m=min(Y[0],c);
	Y[0]-=m;
	//use A+C
	c=Y[3];
	tot+=c;
	m=min(Y[1],c);
	Y[1]-=m;
	c-=m;
	m=min(Y[0],c); //leftover to A
	Y[0]-=m;
	//use individual
	r1=Y[2],r2=max(Y[0],max(Y[1],Y[2]));
		while (r2>r1)
		{
			m=(r1+r2)>>1;
				Fox(i,3)
					Z[i]=Y[i];
				Fox(i,3)
					H[i]=m;
				Fox(i,3)
					FoxI(j,i,2)
					{
						c=min(Z[i],H[j]);
						Z[i]-=c;
						H[j]-=c;
					}
				if (max(Z[0],max(Z[1],Z[2]))>0)
					r1=m+1;
				else
					r2=m;
		}
	return(tot+r1);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N;
	int i,v;
	int ex=0,ans,turns,cur;
	int X[5]={0};
	set<PR> S;
	set<PR>::iterator I;
	Read(N);
	Read(A),Read(B),Read(C);
		if (A>B)
			swap(A,B);
		if (B>C)
			swap(B,C);
		if (A>B)
			swap(A,B);
		while (N--)
		{
			Read(v);
				if (v>A+B+C)
				{
					printf("-1\n");
					return(0);
				}
				if (v>B+C)
					ex++;
				else
				{
					S.insert(mp(v,N));
					X[buck(v)]++;
				}
		}
	ans=INF;
	turns=0;
		for(;;)
		{
			//try it
			memcpy(Y,X,sizeof(X));
			cur=turns+calc();
			Min(ans,cur);
			//use A+B and C
			turns++;
			bool neither=1;
			I=S.lower_bound(mp(A+B,INF));
				if (I!=S.begin())
				{
					neither=0;
					I--;
					X[buck(I->x)]--;
					S.erase(I);
				}
			I=S.lower_bound(mp(C,INF));
				if (I!=S.begin())
				{
					neither=0;
					I--;
					X[buck(I->x)]--;
					S.erase(I);
				}
				if (neither)
					break;
		}
	printf("%d\n",ans+ex);
	return(0);
}