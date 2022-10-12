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
const double EPS = 1e-9;
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

#define SZ 31

int N,d,x;
int A[100005],B[100005],pos[100005],ans[100005];

int getNextX() {
    x = ((LL)x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
	int i;
    for(i = 0; i < N; i = i + 1){
        A[i] = i + 1;
    }
    for(i = 0; i < N; i = i + 1){
        swap(A[i], A[getNextX() % (i + 1)]);
    }
	Fox(i,N)
		pos[A[i]-1]=i;
    for(i = 0; i < N; i = i + 1){
        if (i < d)
            B[i] = 1;
        else
            B[i] = 0;
    }
    for(i = 0; i < N; i = i + 1){
        swap(B[i], B[getNextX() % (i + 1)]);
    }
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,M,a,b,k,p,p2;
	LL v;
	LL rem[5000],mask[5000];
	Read(N),Read(d),Read(x);
	M=0;
	initAB();
		Fox(i,N)
		{
			a=i/SZ;
			Max(M,a+1);
			b=i%SZ;
			rem[a]|=1<<b;
				if (B[i])
					mask[a]|=1<<b;
		}
		FoxR(i,N)
		{
			j=pos[i];
			a=j/SZ;
			b=j%SZ;
				FoxI(k,a,M-1)
				{
					v=rem[k]&(mask[k-a]<<(LL)b);
						while (v)
						{
							p=__builtin_ctz(v);
							p2=k*SZ+p;
							ans[p2]=i+1;
							rem[k]^=1LL<<(LL)p;
							v^=1LL<<(LL)p;
						}
						if ((b) && (k-a-1>=0))
						{
							v=rem[k]&(mask[k-a-1]>>(LL)(SZ-b));
								while (v)
								{
									p=__builtin_ctz(v);
									p2=k*SZ+p;
									ans[p2]=i+1;
									rem[k]^=1LL<<(LL)p;
									v^=1LL<<(LL)p;
								}
						}
				}
		}
		Fox(i,N)
			printf("%d\n",ans[i]);
	return(0);
}