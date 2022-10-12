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
#define LIM 300005

int ans,cur;
char S[LIM];
vector<int> G[LIM],C[LIM],A[LIM];
vector<int> L,L2;

char Ch(int v)
{
		if (v==0)
			return('A');
		if (v==1)
			return('C');
		if (v==2)
			return('G');
	return('T');
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z;
	int O[4];
	Read(N),Read(M);
		Fox(i,N)
		{
			scanf("%s",&S);
				Fox(j,M)
					if (S[j]=='A')
						G[i].pb(0);
					else
					if (S[j]=='C')
						G[i].pb(1);
					else
					if (S[j]=='G')
						G[i].pb(2);
					else
						G[i].pb(3);
		}
	L2.resize(M);
	ans=INF;
	//rows
		Fox(i,4)
			O[i]=i;
		do
		{
			cur=0;
				Fox(i,N)
				{
					int a=(i%2)*2;
					int m=INF;
						Fox(z,2)
						{
							int s=0;
								Fox(j,M)
								{
									b=a+((j+z)%2);
									int e=O[b];
									L2[j]=e;
										if (G[i][j]!=e)
											s++;
								}
								if (s<m)
									m=s,L=L2;
						}
					cur+=m;
					C[i]=L;
				}
				if (cur<ans)
				{
					ans=cur;
						Fox(i,N)
							A[i]=C[i];
				}
		}
		while (next_permutation(O,O+4));
	//cols
	L2.clear();
	L2.resize(N);
		Fox(i,4)
			O[i]=i;
		do
		{
			cur=0;
				Fox(i,M)
				{
					int a=(i%2)*2;
					int m=INF;
						Fox(z,2)
						{
							int s=0;
								Fox(j,N)
								{
									b=a+((j+z)%2);
									int e=O[b];
									L2[j]=e;
										if (G[j][i]!=e)
											s++;
								}
								if (s<m)
									m=s,L=L2;
						}
					cur+=m;
					C[i]=L;
				}
				if (cur<ans)
				{
					ans=cur;
						Fox(i,N)
						{
							A[i].resize(M);
								Fox(j,M)
									A[i][j]=C[j][i];
						}
				}
		}
		while (next_permutation(O,O+4));
	//out
		Fox(i,N)
		{
				Fox(j,M)
					printf("%c",Ch(A[i][j]));
			printf("\n");
		}
	return(0);
}