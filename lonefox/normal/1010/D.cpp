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
#define LIM 1000001

char C[LIM];
int A[LIM],B[LIM],V[LIM];
int dyn1[LIM],dynS[LIM],dynD[LIM];

int rec1(int i)
{
	int d;
		if (C[i]=='I')
			d=V[i];
		else
		if (C[i]=='N')
			d=1-rec1(A[i]);
		else
		if (C[i]=='A')
			d=rec1(A[i])*rec1(B[i]);
		else
		if (C[i]=='X')
			d=Abs(rec1(A[i])-rec1(B[i]));
		else
			d=min(1,rec1(A[i])+rec1(B[i]));
	return(dyn1[i]=d);
}

void rec2(int i)
{
	int v;
		if (C[i]=='I')
			return;
		if (C[i]=='N')
		{
			//a
			dynS[A[i]]=dynS[i];
			v=1-(1-dyn1[A[i]]);
			dynD[A[i]]=(v==dyn1[i] ? dynS[i] : dynD[i]);
			//r
			rec2(A[i]);
		}
		else
		if (C[i]=='A')
		{
			//a
			dynS[A[i]]=dynS[i];
			v=(1-dyn1[A[i]])*dyn1[B[i]];
			dynD[A[i]]=(v==dyn1[i] ? dynS[i] : dynD[i]);
			//b
			dynS[B[i]]=dynS[i];
			v=dyn1[A[i]]*(1-dyn1[B[i]]);
			dynD[B[i]]=(v==dyn1[i] ? dynS[i] : dynD[i]);
			//r
			rec2(A[i]);
			rec2(B[i]);
		}
		else
		if (C[i]=='X')
		{
			//a
			dynS[A[i]]=dynS[i];
			v=Abs((1-dyn1[A[i]])-dyn1[B[i]]);
			dynD[A[i]]=(v==dyn1[i] ? dynS[i] : dynD[i]);
			//b
			dynS[B[i]]=dynS[i];
			v=Abs(dyn1[A[i]]-(1-dyn1[B[i]]));
			dynD[B[i]]=(v==dyn1[i] ? dynS[i] : dynD[i]);
			//r
			rec2(A[i]);
			rec2(B[i]);
		}
		else
		{
			//a
			dynS[A[i]]=dynS[i];
			v=min(1,(1-dyn1[A[i]])+dyn1[B[i]]);
			dynD[A[i]]=(v==dyn1[i] ? dynS[i] : dynD[i]);
			//b
			dynS[B[i]]=dynS[i];
			v=min(1,dyn1[A[i]]+(1-dyn1[B[i]]));
			dynD[B[i]]=(v==dyn1[i] ? dynS[i] : dynD[i]);
			//r
			rec2(A[i]);
			rec2(B[i]);
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,x,y,z,a,b,c;
	char s[10];
	Read(N);
		Fox1(i,N)
		{
			scanf("%s",&s);
			C[i]=s[0];
				if (s[0]=='I')
					Read(V[i]);
				else
				if (s[0]=='N')
					Read(A[i]);
				else
					Read(A[i]),Read(B[i]);
		}
	rec1(1);
	dynS[1]=dyn1[1];
	dynD[1]=1-dyn1[1];
	rec2(1);
		Fox1(i,N)
			if (C[i]=='I')
				printf("%d",dynD[i]);
	printf("\n");
	return(0);
}