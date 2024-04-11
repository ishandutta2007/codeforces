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

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,i,j;
	char c;
	int v,cur,ans,b1,b2;
	int v1[100],v2[100];
	Read(N);
		Fox(i,N)
		{
			cin >> c;
				if (c=='R')
					v=0;
				if (c=='G')
					v=1;
				if (c=='B')
					v=2;
				if (c=='Y')
					v=3;
				if (c=='W')
					v=4;
			v1[i]=v;
			Read(v),v--;
			v2[i]=v;
		}
	ans=INF;
		Fox(b1,1<<5)
			Fox(b2,1<<5)
			{
				cur=0;
					Fox(i,5)
					{
						if (b1&(1<<i))
							cur++;
						if (b2&(1<<i))
							cur++;
					}
					Fox(i,N)
						Fox(j,i)
							if (v1[i]==v1[j])
							{
								if (v2[i]==v2[j])
									continue;
								if ((b2&(1<<v2[i])) || (b2&(1<<v2[j])))
									continue;
								goto Bad;
							}
							else
							{
								if ((b1&(1<<v1[i])) || (b1&(1<<v1[j])))
									continue;
								if (v2[i]==v2[j])
									goto Bad;
								if ((b2&(1<<v2[i])) || (b2&(1<<v2[j])))
									continue;
								goto Bad;
							}
				Min(ans,cur);
Bad:;
			}
	printf("%d\n",ans);
	return(0);
}