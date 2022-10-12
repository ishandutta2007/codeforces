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

int N;
char V[1001][1005];
int L[1001];
int C[10];

char getC(int i,int j)
{
		if (j>=L[i])
			return('0');
	return(V[i][L[i]-j-1]);
}

int getD(int i,int j)
{
	return(getC(i,j)-'0');
}

int cor,corA;

void rec(int i,int art)
{
	int d1,d2,d,j,v,s;
		if (i==L[N])
		{
			s=0;
				Fox(i,N)
				{
					v=0;
						Fox(j,L[i])
							v=v*10+V[i][j]-'0';
					v+=art;
						while (v)
						{
							s+=C[v%10];
							v/=10;
						}
				}
				if (s>cor)
					cor=s,corA=art;
			return;
		}
		if (V[N][i]=='?')
		{
			d1=0,d2=9;
				if (!i)
					d1=1;
		}
		else
			d1=d2=V[N][i]-'0';
		FoxI(d,d1,d2)
			rec(i+1,art*10+d);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int M;
	int i,d,j,k,c,v,d1,d2,nc,s;
	char tmp[1005];
	static int ord[1005][1000],ind[1005][1000];
	static int dyn[1005][1001];
	int dig[1000];
	int cur[1000],car[1000];
	scanf("%s",&tmp);
	Read(N);
	strcpy(V[N],tmp);
	M=L[N]=strlen(V[N]);
		Fox(i,N)
		{
			scanf("%s",&V[i]);
			L[i]=strlen(V[i]);
			Max(M,L[i]);
		}
		Fox(i,10)
			Read(C[i]);
	M++;
		Fox(i,N)
		{
			ord[0][i]=i;
			ind[0][i]=i;
		}
	Fill(dyn,-1);
	dyn[0][0]=0;
		Fox(i,M)
		{
			//get new ord
			c=0;
				FoxR(d,10)
					Fox(k,N)
					{
						j=ord[i][k];
							if (getD(j,i)==d)
							{
								ord[i+1][c]=j;
								ind[i+1][j]=c++;
							}
					}
			//consider every valid next digit
				if (getC(N,i)=='?')
				{
					d1=0,d2=9;
						if (i==L[N]-1)
							d1=1;
				}
				else
					d1=d2=getD(N,i);
				FoxI(d,d1,d2)
				{
					//assume no carries
					nc=s=0;
						Fox(j,N)
						{
							k=getD(j,i)+d;
								if (k>=10)
									nc++,k-=10;
								if ((k) || (i<max(L[N],L[j])))
									s+=C[k];
							dig[j]=k;
						}
					//consider every carry suffix
						Fox(j,N+1)
						{
							//update DP
							if ((v=dyn[i][j])>=0)
								Max(dyn[i+1][nc],v+s);
							//apply carry
							if (j<N)
							{
								k=ord[i][j];
								int dd=dig[k];
								//revert
									if ((dd) || (i<max(L[N],L[k])))
										s-=C[dd];
								//inc
								dd++;
								//re-apply
									if (dd>=10)
										nc++,dd-=10;
									if ((dd) || (i<max(L[N],L[k])))
										s+=C[dd];
							}
						}
				}
		}
	v=0;
		Fox(i,N+1)
			Max(v,dyn[M][i]);
	printf("%d\n",v);
		if (DEBUG)
		{
			rec(0,0);
				if (v!=cor)
					printf("SHOULD BE %d (%d)\n",cor,corA);
		}
	return(0);
}