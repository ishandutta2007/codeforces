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
	int i,j,tot=0,ans=0;
	int c[5]={0};
	Read(i);
		while (i--)
		{
			Read(j);
			tot+=j;
				if (j)
					c[j]++;
		}
		if ((tot==1) || (tot==2) || (tot==5))
		{
			printf("-1\n");
			return(0);
		}
	//combine 1s and 2s
	i=min(c[1],c[2]);
	ans+=i;
	c[1]-=i;
	c[2]-=i;
	c[3]+=i;
	//only 1s left?
		if (c[1])
		{
			//add to 3s and 4s
			/*i=c[4]+c[3]*2;
				if (i>=c[1])
					ans+=c[1];
				else
				{
					ans+=i;
					c[1]-=i;*/
					//combine 1s in triples
					i=c[1]/3;
					ans+=i*2;
					c[1]-=i*3;
					c[3]+=i;
					//take care of the leftover 1s, if any
						if (c[1]==1)
						{
							if (c[3]>=1)
								ans++;
							else
								ans+=2;
						}
						else
						if (c[1]==2)
						{
							ans+=2;
							/*if (c[4]>=1)
								ans++;
							else
								ans+=2;*/
						}
				//}
		}
		else //only 2s left
		{
			//combine 2s in triples
			i=c[2]/3;
			ans+=i*2;
			c[2]-=i*3;
			//take care of the leftover 2s, if any
				if (c[2]==1)
				{
					if (c[4]>=1)
						ans++;
					else
						ans+=2;
				}
				else
				if (c[2]==2)
				{
					ans+=2;
				}
		}
	printf("%d\n",ans);
	return(0);
}