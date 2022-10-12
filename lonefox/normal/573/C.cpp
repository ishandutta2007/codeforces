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

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N;
	int i,j,k,p,pp;
	static int deg[100000],deg2[100000];
	static bool vis[100000];
	static vector<int> con[100000];
	Read(N);
		if (N==1)
			goto Yes;
		Fox(i,N-1)
		{
			Read(j),Read(k);
			j--,k--;
			deg[j]++;
			deg[k]++;
			con[j].pb(k);
			con[k].pb(j);
		}
		Fox(i,N)
			if (deg[i]==1)
			{
				vis[i]=1;
				p=i;
				j=con[i][0];
					while (deg[j]<3)
					{
						pp=j;
						vis[j]=1;
							if (deg[j]==1)
								goto Yes;
							if (con[j][0]==p)
								j=con[j][1];
							else
								j=con[j][0];
						p=pp;
					}
				deg2[j]++;
			}
		Fox(i,N)
			if ((deg2[i]==2) && (deg[i]==3))
				vis[i]=1;
		Fox(i,N)
			if (!vis[i])
			{
				k=0;
					Fox(j,Sz(con[i]))
						if (!vis[con[i][j]])
							k++;
					if (k>2)
						goto No;
			}
Yes:;
	printf("Yes\n");
	return(0);
No:;
	printf("No\n");
	return(0);
}