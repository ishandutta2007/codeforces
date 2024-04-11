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
#define LIM 530005

int N,R,K;
int dep[LIM],A[LIM],B[LIM];
vector<int> con[LIM];
set<PR> S;
int sz;
int treeM[LIM],treeC[LIM],lazy[LIM];
int skip[LIM][20];

void Prop(int i)
{
	int v=lazy[i];
	lazy[i]=0;
	treeM[i]+=v;
		if (i<sz)
		{
			i<<=1;
			lazy[i]+=v;
			lazy[i+1]+=v;
		}
}

int Query(int i,int r1,int r2,int a,int b)
{
	Prop(i);
		if (a<=r1 && r2<=b)
			return(treeM[i] ? 0 : treeC[i]);
	int c=i<<1;
	int m=(r1+r2)>>1;
	int ret=0;
		if (a<=m)
			ret+=Query(c,r1,m,a,b);
		if (b>m)
			ret+=Query(c+1,m+1,r2,a,b);
	return(ret);
}

void Update(int i,int r1,int r2,int a,int b,int d)
{
	Prop(i);
		if (a<=r1 && r2<=b)
		{
			lazy[i]+=d;
			Prop(i);
			return;
		}
	int c=i<<1;
	int m=(r1+r2)>>1;
		if (a<=m)
			Update(c,r1,m,a,b,d);
		if (b>m)
			Update(c+1,m+1,r2,a,b,d);
	Prop(c),Prop(c+1);
	treeM[i]=min(treeM[c],treeM[c+1]);
	treeC[i]=0;
	int j;
		FoxI(j,c,c+1)
			if (treeM[j]==treeM[i])
				treeC[i]+=treeC[j];
}

void UpdateW(int a,int b,int d)
{
		if (a<=b)
			Update(1,0,sz-1,a,b,d);
}

void rec(int i,int p,int d)
{
	int j,c;
	skip[i][0]=p;
		Fox(j,19)
		{
			c=skip[i][j];
				if (c<0)
					break;
			c=skip[c][j];
				if (c<0)
					break;
			skip[i][j+1]=c;
		}
	dep[i]=d;
	A[i]=K++;
		Fox(j,Sz(con[i]))
			if ((c=con[i][j])!=p)
				rec(c,i,d+1);
	B[i]=K-1;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int Q;
	int i,j,k,m,d,p;
	Fill(skip,-1);
	Read(N),Read(Q);
		Fox(i,N-1)
		{
			Read(j),Read(k),j--,k--;
			con[j].pb(k);
			con[k].pb(j);
		}
		Fox(i,N)
			if (Sz(con[i])>1)
				break;
	R=i;
	rec(R,-1,0);
		for(sz=1;sz<K;sz<<=1);
		Fox(i,sz)
			treeC[sz+i]=1;
		FoxR1(i,sz-1)
		{
			j=i<<1;
			treeC[i]=treeC[j]+treeC[j+1];
		}
		while (Q--)
		{
			Read(i),Read(j),i--,j--;
				if (i>j)
					swap(i,j);
				if (S.count(mp(i,j)))
					S.erase(mp(i,j)),m=-1;
				else
					S.insert(mp(i,j)),m=1;
				if (dep[i]>dep[j])
					swap(i,j);
				if (A[i]<=A[j] && B[j]<=B[i])
				{
					UpdateW(A[j],B[j],-m);
					d=dep[i]+1;
						FoxR(k,20)
						{
							p=skip[j][k];
								if ((p>=0) && (dep[p]>=d))
									j=p;
						}
					UpdateW(A[j],B[j],m);
				}
				else
				{
						if (A[i]>A[j])
							swap(i,j);
					UpdateW(0,A[i]-1,m);
					UpdateW(B[i]+1,A[j]-1,m);
					UpdateW(B[j]+1,K-1,m);
				}
			printf("%d\n",Query(1,0,sz-1,0,K-1));
		}
	return(0);
}