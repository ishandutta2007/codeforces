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

int V[LIM];
vector<int> con[LIM];
LL ans;

LL dyn[LIM][2];
bool val[LIM];
bool mem[LIM][2];

void rec(int i,int p)
{
	int j,c;
	bool lf=1;
	LL sum0=0;
	LL maxD1=0;
		Fox(j,Sz(con[i]))
			if ((c=con[i][j])!=p)
			{
				lf=0;
				rec(c,i);
				sum0+=dyn[c][0];
				LL d1=dyn[c][0]-dyn[c][1];
				Max(maxD1,d1);
			}
		if (lf)
		{
			dyn[i][0]=V[i];
			dyn[i][1]=0;
			return;
		}
	dyn[i][0]=min(sum0, sum0-maxD1+V[i]);
	dyn[i][1]=sum0-maxD1;
}

void rec2(int i,int p,int z)
{
		if (mem[i][z])
			return;
	mem[i][z]=1;
	int j,c;
	bool lf=1;
	LL req=dyn[i][z];
	LL sum0=0;
	LL maxD1=0;
	int cntMaxD1=0;
		Fox(j,Sz(con[i]))
			if ((c=con[i][j])!=p)
			{
				lf=0;
				sum0+=dyn[c][0];
				LL d1=dyn[c][0]-dyn[c][1];
					if (d1>maxD1)
						maxD1=d1,cntMaxD1=1;
					else
					if (d1==maxD1)
						cntMaxD1++;
			}
		if (lf)
		{
				if (!z)
					val[i]=1;
			return;
		}
		if (!z)
			if (sum0-maxD1+V[i]==req)
				val[i]=1;
		if (!z && sum0==req)
		{
			Fox(j,Sz(con[i]))
				if ((c=con[i][j])!=p)
					rec2(c,i,0);
		}
		if (!z && sum0-maxD1+V[i]==req || z)
		{
			Fox(j,Sz(con[i]))
				if ((c=con[i][j])!=p)
				{
					LL d1=dyn[c][0]-dyn[c][1];
						if (d1==maxD1)
						{
							rec2(c,i,1);
								if (cntMaxD1>1)
									rec2(c,i,0);
						}
						else
							rec2(c,i,0);
				}
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z;
	Read(N);
		Fox(i,N)
		{
			Read(V[i]);
				if (!V[i])
					val[i]=1;
		}
		Fox(i,N-1)
		{
			Read(j),Read(k),j--,k--;
			con[j].pb(k);
			con[k].pb(j);
		}
	rec(0,-1);
	rec2(0,-1,0);
	ans=dyn[0][0];
	cout << ans;
	j=0;
		Fox(i,N)
			if (val[i])
				j++;
	printf(" %d\n",j);
		Fox(i,N)
			if (val[i])
				printf("%d ",i+1);
	printf("\n");
	return(0);
}