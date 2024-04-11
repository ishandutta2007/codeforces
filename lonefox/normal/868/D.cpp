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

int K,V[105];
bitset<1024> X[205][11];

void Go(int z)
{
	int k,i,j,b;
		Fox1(k,10)
			Fox(i,K-k+1)
			{
				b=0;
					Fox(j,k)
						b=(b<<1)+V[i+j];
				X[z][k][b]=1;
			}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	int i,j,k,a,b;
	char s[105];
	static int L[205],A[205][10],B[205][10];
	Read(N);
		Fox(i,N)
		{
			scanf("%s",&s);
			L[i]=strlen(s);
				Fox(j,min(L[i],10))
				{
					A[i][j]=s[j]-'0';
					B[i][j]=s[L[i]-j-1]-'0';
				}
			K=L[i];
				Fox(j,K)
					V[j]=s[j]-'0';
			Go(i);
		}
	Read(M);
		while (M--)
		{
			Read(i),Read(j),i--,j--;
			//basic
			L[N]=min(100,L[i]+L[j]);
				Fox1(k,10)
					X[N][k]=X[i][k]|X[j][k];
			//pre
			memcpy(A[N],A[i],sizeof(A[i]));
				FoxI(a,L[i],min(9,L[N]-1))
					A[N][a]=A[j][a-L[i]];
			K=min(10,L[N]);
			memcpy(V,A[N],sizeof(V));
			Go(N);
			//suff
			memcpy(B[N],B[j],sizeof(B[j]));
				FoxI(b,L[j],min(9,L[N]-1))
					B[N][b]=B[i][b-L[j]];
			K=min(10,L[N]);
				Fox(b,K)
					V[b]=B[N][K-b-1];
			Go(N);
			//crossover
			K=0;
				FoxR(a,min(10,L[i]))
					V[K++]=B[i][a];
				Fox(a,min(10,L[j]))
					V[K++]=A[j][a];
			Go(N);
			//ans
				Fox1(k,10)
					if (X[N][k].count()<(1<<k))
						break;
			printf("%d\n",k-1);
			N++;
		}
	return(0);
}