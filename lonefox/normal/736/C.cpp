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

#define MOD 1000000007

int N,K;
vector<int> con[100];
int dynE[100][22],dynR[100][22];

void Add(int &a,int b)
{
	a=(a+b)%MOD;
}

void Mult(int &a,int b)
{
	a=(LL)a*b%MOD;
}

void rec(int i,int p)
{
	int j,k,a,b,v,v2,V,V2,s,s2;
	vector<int> ch;
		Fox(j,Sz(con[i]))
			if ((k=con[i][j])!=p)
			{
				rec(k,i);
				ch.pb(k);
			}
	//paint here
	v=1;
		Fox(j,Sz(ch))
		{
			k=ch[j];
			v2=0;
				Fox(a,K+1)
					Add(v2,dynE[k][a]);
				Fox(a,K)
					Add(v2,dynR[k][a]);
			Mult(v,v2);
		}
	dynE[i][K]=v;
	//no children
		if (!Sz(ch))
		{
			dynR[i][0]=1;
			return;
		}
	//extra
		Fox(a,K)
		{
			v=1,v2=0;
				Fox(j,Sz(ch))
				{
					k=ch[j];
					//satisfy here
					s2=dynE[k][a+1];
					//don't satisfy
					s=0;
						Fox(b,a+1)
							Add(s,dynE[k][b]);
						Fox(b,a)
							Add(s,dynR[k][b]);
					V=(LL)v*s%MOD;
					V2=((LL)(v+v2)*s2%MOD + (LL)v2*s%MOD)%MOD;
					v=V;
					v2=V2;
				}
			dynE[i][a]=v2;
		}
	//required
		Fox(a,K)
		{
			v=1,v2=0;
				Fox(j,Sz(ch))
				{
					k=ch[j];
					//satisfy here
					s2=a ? dynR[k][a-1] : dynE[k][0];
					//don't satisfy
					s=0;
						Fox(b,a-1)
							Add(s,dynR[k][b]);
						if (a)
							Fox(b,a+1)
								Add(s,dynE[k][b]);
					V=(LL)v*s%MOD;
					V2=((LL)(v+v2)*s2%MOD + (LL)v2*s%MOD)%MOD;
					v=V;
					v2=V2;
				}
			dynR[i][a]=v2;
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,k,ans;
	Read(N),Read(K);
		Fox(i,N-1)
		{
			Read(j),Read(k),j--,k--;
			con[j].pb(k);
			con[k].pb(j);
		}
	rec(0,0);
	ans=0;
		Fox(i,K+1)
			Add(ans,dynE[0][i]);
	printf("%d\n",ans);
	return(0);
}