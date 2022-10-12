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
#define LIM 50005
#define LIM2 8000005

int N,M,Q,C;
int t;
int F[LIM],Sz[LIM],in[LIM],rin[LIM],nxt[LIM],out[LIM],cst[LIM];
int parI[LIM];
vector <int> ch[LIM];

int cc;
int RT[LIM2],C1[LIM2],C2[LIM2],L[LIM2],R[LIM2];
LL tree1[LIM2],tree2[LIM2];
int tLazy[LIM2];

int GetLeft(int i)
{
		if (C1[i])
			return(C1[i]);
	int c=cc++;
	C1[i]=c;
	L[c]=L[i];
	R[c]=(L[i]+R[i])/2;
	return(c);
}

int GetRight(int i)
{
		if (C2[i])
			return(C2[i]);
	int c=cc++;
	C2[i]=c;
	L[c]=(L[i]+R[i])/2+1;
	R[c]=R[i];
	return(c);
}

void Prop(int i)
{
	LL v=tLazy[i];
		if (!v)
			return;
	tLazy[i]=0;
	LL c=R[i]-L[i]+1;
	tree2[i]+=c*v*v + 2*v*tree1[i];
	tree1[i]+=v*c;
		if (L[i]<R[i])
		{
			tLazy[GetLeft(i)]+=v;
			tLazy[GetRight(i)]+=v;
		}
}

void Comb(int i)
{
	int c1=GetLeft(i);
	int c2=GetRight(i);
	Prop(i);
	Prop(c1);
	Prop(c2);
	tree1[i]=tree1[c1]+tree1[c2];
	tree2[i]=tree2[c1]+tree2[c2];
}

void Update(int i,int a,int b,int v)
{
	Prop(i);
		if (a<=L[i] && R[i]<=b)
		{
			tLazy[i]=v;
			Prop(i);
			return;
		}
	int c1=GetLeft(i);
	int c2=GetRight(i);
		if (a<=R[c1])
			Update(c1,a,b,v);
		if (b>=L[c2])
			Update(c2,a,b,v);
	Comb(i);
}

void dfs_sz(int v = 0)
{
	int j,u;
    Sz[v] = 1;
	Fox(j,Sz(ch[v]))
    {
		u=ch[v][j];
        dfs_sz(u);
        Sz[v] += Sz[u];
        if(Sz[u] > Sz[ch[v][0]])
            swap(ch[v][j], ch[v][0]);
    }
}

void dfs_hld(int v = 0)
{
	int j,u;
	in[v] = t++;
    rin[in[v]] = v;
    Fox(j,Sz(ch[v]))
    {
		u=ch[v][j];
        nxt[u] = (u == ch[v][0] ? nxt[v] : u);
        dfs_hld(u);
    }
    out[v] = t;
}

void Upd(int f,int i,int d)
{
	int r=RT[f];
	d*=cst[f];
	int j;
		while (i>=0)
		{
			j=nxt[i];
				if (in[j]>in[i])
					exit(1);
			Update(r,in[j],in[i],d);
			i=parI[j];
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,k,d,r;
	Read(N),Read(M),Read(Q),Read(C);
		Fox(i,N)
			Read(F[i]),F[i]--;
		Fox1(i,N-1)
		{
			Read(j),j--;
			parI[i]=j;
			ch[j].pb(i);
		}
	parI[0]=-1;
		Fox(i,M)
		{
			Read(cst[i]);
			r=RT[i]=cc++;
			L[r]=0;
			R[r]=N-1;
		}
	dfs_sz();
	dfs_hld();
		Fox(i,N)
			Upd(F[i],i,1);
		while (Q--)
		{
			Read(t);
				if (t==1)
				{
					Read(i),Read(k),i--,k--;
					Upd(F[i],i,-1);
					F[i]=k;
					Upd(F[i],i,1);
				}
				else
				{
					Read(k),k--;
					r=RT[k];
					Prop(r);
					LL sum=tree1[r];
					LL sq=tree2[r];
					LL tot=sq + (LL)C*C*N - 2*sum*C;
					cout << fixed << setprecision(9) << (LD)tot/N << endl;
				}
		}
	return(0);
}