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

int N;
LL dataMul[200000],dataAdd[200000];

void internalUpdate(int at, LL mul, LL add) {
    while (at < N) {
        dataMul[at] += mul;
        dataAdd[at] += add;
        at |= (at + 1);
    }
}

void update(int left, int right, LL by) {
    internalUpdate(left, by, -by * (left - 1));
    internalUpdate(right, -by, by * right);
}

LL query(int at) {
    LL mul = 0;
    LL add = 0;
    int start = at;
    while (at >= 0) {
        mul += dataMul[at];
        add += dataAdd[at];
        at = (at & (at + 1)) - 1;
    }
    return mul * start + add;
}

int query2(int i)
{
	return(query(i)-query(i-1));
}

int nxt;
int ind1[200000],ind2[200000],dep[200000];
vector <int> con[200000];

void rec(int i,int p,int d)
{
	ind1[i]=nxt++;
	dep[i]=d;
	int j,k;
		Fox(j,Sz(con[i]))
		{
			k=con[i][j];
				if (k!=p)
					rec(k,i,1-d);
		}
	ind2[i]=nxt-1;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int M;
	int i,j,k;
	static int V[200000];
	Read(N),Read(M);
		Fox(i,N)
			Read(V[i]);
		Fox(i,N-1)
		{
			Read(j),Read(k);
			j--,k--;
			con[j].pb(k);
			con[k].pb(j);
		}
	rec(0,-1,0);
		Fox(i,N)
			update(ind1[i],ind1[i],dep[i] ? -V[i] : V[i]);
		while (M--)
		{
			Read(i);
				if (i==1)
				{
					Read(i),Read(j),i--;
						if (dep[i])
							j=-j;
					update(ind1[i],ind2[i],j);
				}
				else
				{
					Read(i),i--;
					printf("%d\n",query2(ind1[i])*(dep[i] ? -1 : 1));
				}
		}
	return(0);
}