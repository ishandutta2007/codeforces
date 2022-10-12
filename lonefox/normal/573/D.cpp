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

#define LIM 30010
#define SZ 180

int N,M;
PR A[LIM],B[LIM];
int H[LIM];
int ind[LIM];
int s1[SZ],s2[SZ];
LL dyn[SZ][3][3];
LL dyn2[LIM];
int sec[LIM];
LL dyn3[SZ][3];

void calc(int s)
{
	int a=s1[s];
	int b=s2[s];
	int c=min(N,b+3);
	int z;
	int i;
	LL d;
		FoxI(z,a,a+2)
		{
				FoxI(i,z,c)
					dyn2[i]=-1;
			dyn2[z]=0;
				FoxI(i,z,c-1)
					if ((d=dyn2[i])>=0)
					{
						//0
						if (H[A[i].y]!=B[i].y)
							Max(dyn2[i+1],d + (LL)A[i].x*B[i].x);
						//1 0
						if (i+1>=N)
							continue;
						if (H[A[i+1].y]!=B[i].y && H[A[i].y]!=B[i+1].y)
							Max(dyn2[i+2],d + (LL)A[i+1].x*B[i].x + (LL)A[i].x*B[i+1].x);
						//1 2 0
						if (i+2>=N)
							continue;
						if (H[A[i+1].y]!=B[i].y && H[A[i+2].y]!=B[i+1].y && H[A[i].y]!=B[i+2].y)
							Max(dyn2[i+3],d + (LL)A[i+1].x*B[i].x + (LL)A[i+2].x*B[i+1].x + (LL)A[i].x*B[i+2].x);
						//2 0 1
						if (H[A[i+2].y]!=B[i].y && H[A[i].y]!=B[i+1].y && H[A[i+1].y]!=B[i+2].y)
							Max(dyn2[i+3],d + (LL)A[i+2].x*B[i].x + (LL)A[i].x*B[i+1].x + (LL)A[i+1].x*B[i+2].x);
					}
				Fox(i,3)
					if (b+1+i<=c)
						dyn[s][z-a][i]=dyn2[b+1+i];
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int Q;
	int i,j,k;
	LL ans;
	Read(N),Read(Q);
		Fox(i,N)
			Read(A[i].x),A[i].y=i;
		Fox(i,N)
			Read(B[i].x),B[i].y=i;
		if (N==2)
		{
			i=1;
				while (Q--)
				{
					i=1-i;
					ans=(LL)A[0].x * B[i].x;
					ans+=(LL)A[1].x * B[1-i].x;
					cout << ans << endl;
				}
			return(0);
		}
	sort(A,A+N);
	sort(B,B+N);
		Fox(i,N)
			ind[A[i].y]=i;
		Fox(i,N)
			H[i]=i;
	i=0;
	M=0;
		while (i<N)
		{
			j=min(N-1,i+SZ-1);
				if ((N-1)-(j+1)+1 <= 2)
					j=N-1;
			s1[M]=i;
			s2[M]=j;
				FoxI(k,i,j)
					sec[k]=M;
			calc(M);
			M++;
			i=j+1;
		}
		while (Q--)
		{
			Read(i),Read(j);
			i--,j--;
			swap(H[i],H[j]);
			i=sec[ind[i]];
			j=sec[ind[j]];
			calc(i);
				if (i)
					calc(i-1);
				if (i!=j)
				{
					calc(j);
						if (j)
							calc(j-1);
				}
			Fill(dyn3,-1);
			dyn3[0][0]=0;
				Fox(i,M)
					Fox(j,3)
						if (dyn3[i][j]>=0)
							Fox(k,3)
								if (dyn[i][j][k]>=0)
									Max(dyn3[i+1][k],dyn3[i][j] + dyn[i][j][k]);
			cout << dyn3[M][0] << endl;
		}
	return(0);
}