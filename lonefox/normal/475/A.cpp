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
#define FoxR(i,n) for (i=n-1; i>=0; i--)
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

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

//#if DEBUG
#define GETCHAR getchar
/*#else
#define GETCHAR getchar_unlocked
#endif*/

void Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if (c=='-')
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
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z;
	static int V[100005];
	int col[11][4]={0};
	Read(N);
	printf("+------------------------+\n");
		Fox(i,4)
			if (N)
			{
				col[0][i]=1;
				N--;
			}
		Fox1(i,10)
			Fox(j,4)
				if (j!=2)
					if (N)
					{
						col[i][j]=1;
						N--;
					}
	printf("|");
		Fox(i,11)
			printf("%c.",col[i][0]?'O':'#');
	printf("|D|)\n");
	printf("|");
		Fox(i,11)
			printf("%c.",col[i][1]?'O':'#');
	printf("|.|\n");
	printf("|");
		Fox(i,11)
			if (i>0)
				printf("..");
			else
				printf("%c.",col[i][2]?'O':'#');
	printf("..|\n");
	printf("|");
		Fox(i,11)
			printf("%c.",col[i][3]?'O':'#');
	printf("|.|)\n");
	printf("+------------------------+\n");
	return(0);
}