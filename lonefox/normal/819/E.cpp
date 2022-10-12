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

#define LIM 90000

int N,M;
int C[300][300];
int cycL[LIM],cyc1[LIM],cyc2[LIM],cyc3[LIM],cyc4[LIM];
bool done;

void rec()
{
	//done?
	int i,j;
		Fox(j,N)
			Fox(i,j)
				if (C[i][j]!=2)
					goto Bad;
	done=1;
	return;
Bad:;
	//3
	int a,b,c,d;
		Fox(c,N)
			Fox(b,c)
				if (C[b][c]<2)
					Fox(a,b)
						if ((C[a][b]<2) && (C[a][c]<2))
						{
							cycL[M]=3;
							cyc1[M]=a;
							cyc2[M]=b;
							cyc3[M++]=c;
							C[a][b]++;
							C[a][c]++;
							C[b][c]++;
							rec();
								if (done)
									return;
							C[a][b]--;
							C[a][c]--;
							C[b][c]--;
							M--;
						}
	//4
		Fox(d,N)
			Fox(c,d)
				if (C[c][d]<2)
					Fox(b,c)
						if (C[b][c]<2)
							Fox(a,b)
								if ((C[a][b]<2) && (C[a][d]<2))
								{
									cycL[M]=4;
									cyc1[M]=a;
									cyc2[M]=b;
									cyc3[M]=c;
									cyc4[M++]=d;
									C[a][b]++;
									C[a][d]++;
									C[b][c]++;
									C[c][d]++;
									rec();
										if (done)
											return;
									C[a][b]--;
									C[a][d]--;
									C[b][c]--;
									C[c][d]--;
									M--;
								}
}

void Comb()
{
	int i,j,k;
	/*
	3 1 2 3
	3 1 2 4
	3 1 3 4
	3 2 3 4*/
	cycL[M]=3;
	cyc1[M]=N;
	cyc2[M]=N+1;
	cyc3[M++]=N+2;
	cycL[M]=3;
	cyc1[M]=N;
	cyc2[M]=N+1;
	cyc3[M++]=N+3;
	cycL[M]=3;
	cyc1[M]=N;
	cyc2[M]=N+2;
	cyc3[M++]=N+3;
	cycL[M]=3;
	cyc1[M]=N+1;
	cyc2[M]=N+2;
	cyc3[M++]=N+3;
	//comb
		if (N%2==0)
		{
				for (j=N; j<=N+2; j+=2)
					for (i=0; i<N; i+=2)
						Fox(k,2)
						{
							cycL[M]=4;
							cyc1[M]=j;
							cyc2[M]=i;
							cyc3[M]=j+1;
							cyc4[M++]=i+1;
						}
			return;
		}
		for (j=N; j<=N+2; j+=2)
		{
				for (i=0; i<N-3; i+=2)
					Fox(k,2)
					{
						cycL[M]=4;
						cyc1[M]=j;
						cyc2[M]=i;
						cyc3[M]=j+1;
						cyc4[M++]=i+1;
					}
			cycL[M]=4;
			cyc1[M]=j;
			cyc2[M]=N-3;
			cyc3[M]=j+1;
			cyc4[M++]=N-2;
			cycL[M]=4;
			cyc1[M]=j;
			cyc2[M]=N-3;
			cyc3[M]=j+1;
			cyc4[M++]=N-1;
			cycL[M]=4;
			cyc1[M]=j;
			cyc2[M]=N-2;
			cyc3[M]=j+1;
			cyc4[M++]=N-1;
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int O,A;
	int i;
	Read(N);
	O=N;
		while (N>7)
			N-=4;
	rec();
	N=O;
		while (N>7)
		{
			N-=4;
			Comb();
		}
	printf("%d\n",M);
		Fox(i,M)
		{
			printf("%d %d %d %d",cycL[i],cyc1[i]+1,cyc2[i]+1,cyc3[i]+1);
				if (cycL[i]==4)
					printf(" %d",cyc4[i]+1);
			printf("\n");
		}
	return(0);
}