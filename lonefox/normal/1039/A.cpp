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

LL A[LIM],X[LIM],B[LIM];
int C[LIM];
int ord[LIM],cor[LIM];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	LL K;
	int i,j,k,a,b,c,x,y,z,m;
	LL v;
	//N=4,K=2;
	/*for(;;)
	{
	bool ex=1,cr=0;*/
	Read(N),ReadLL(K);
	//N=8,K=10;
		Fox(i,N)
			ReadLL(A[i]);
			//A[i]=i ? A[i-1]+rand()%4+1 : rand()%4+1;
		Fill(C,0);
		Fox(i,N)
		{
			ReadLL(X[i]),X[i]--;
			//X[i]=i/2*2+1;
			//X[i]=rand()%N;
			//X[i]=i ? X[i-1]+rand()%(N-X[i-1]) : rand()%N;
			C[X[i]]++;
		}
		Fox(i,N)
			if (i && X[i]<X[i-1])
				goto Imp;
		if (X[N-1]!=N-1)
			goto Imp;
	j=k=0;
		Fox(i,N)
		{
			k+=C[i];
				if (k>i+1)
					goto Imp;
				if (k==i+1)
				{
						FoxI(a,j,i)
							if (X[a]!=i)
								goto Imp;
						if (j && B[j-1] >= A[j]+K)
							goto Imp;
					//v=A[j]+K;
					/*v=j==i ? A[j]+K : A[j+1]+K;
						FoxI(a,j,i)
							B[a]=v++;*/
						FoxI(a,j,i-1)
							B[a]=A[a+1]+K;
						if (i==j)
							B[i]=A[i]+K;
						else
							B[i]=B[i-1]+1;
					j=i+1;
				}
		}
//Imp:;
		if (DEBUG)
		{
				/*if (0)
				{
Imp:;
					ex=0;
				}*/
				/*FoxI(B[0],1,21)
					FoxI(B[1],B[0]+1,21)
						FoxI(B[2],B[1]+1,21)
						FoxI(B[3],B[2]+1,21)
				{*/
			Fill(cor,-1);
				Fox(i,N)
					ord[i]=i;
				do
				{
						Fox(i,N)
							if (B[ord[i]]<A[i]+K)
								goto Bad;
						Fox(i,N)
							Max(cor[i],ord[i]);
Bad:;
				}
				while (next_permutation(ord,ord+N));
				Fox(i,N)
					if (X[i]!=cor[i])
						break;
				if (i==N)
				{
					//printf("SOLVED\n");
					//cr=1;
					//goto Out;
				}
				else
				{
					printf("WRONG\n");
				}
				}
		/*}
/*Out:;
		if (ex!=cr)
		{
			printf("WRONG\n");
				Fox(i,N)
					printf("%d%c",A[i],i==N-1?'\n':' ');
				Fox(i,N)
					printf("%d%c",X[i],i==N-1?'\n':' ');
			exit(0);
		}*/
	//printf("%d\n",ex);
	//return(0);
	//continue;
	printf("Yes\n");
		Fox(i,N)
		{
				if (i)
					printf(" ");
			cout << B[i];
		}
	printf("\n");
	return(0);
Imp:;
	printf("No\n");
	//}
	return(0);
}