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

#define LIM 999999

int N;
char A[200005],B[200005];
map<pair<PR,int>,bool> M;

bool rec(int a,int b,int x,int y)
{
	int sz=b-a+1;
		if (sz>LIM)
			if (M.count(mp(mp(a,x),sz)))
				return(M[mp(mp(a,x),sz)]);
	
		if (sz&1)
		{
	int i;
		Fox(i,sz)
			if (A[a+i]!=B[x+i])
				goto Bad;
		if (sz>LIM)
			M[mp(mp(a,x),sz)]=1;
	return(1);
Bad:;
	if (sz>LIM)
					M[mp(mp(a,x),sz)]=0;
			return(0);
		}
	int sz2=sz;
	sz>>=1;
	bool ret=(
		rec(a,a+sz-1,x,x+sz-1) && rec(a+sz,b,x+sz,y) ||
		rec(a,a+sz-1,x+sz,y) && rec(a+sz,b,x,x+sz-1)
	);
	if (sz>LIM)
					M[mp(mp(a,x),sz)]=ret;
			return(ret);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	scanf("%s%s",&A,&B);
	N=strlen(A);
	/*N=131072;
	int i;
		Fox(i,N)
		{
			/*A[i]=rand()%1+'a';
			B[i]=rand()%1+'a';
			A[i]='a'+i%3;
			B[i]='c'-i%3;
		}*/
	printf("%s\n",rec(0,N-1,0,N-1) ? "YES" : "NO");
	return(0);
}