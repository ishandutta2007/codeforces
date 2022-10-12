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
	int T;
	int i,j,k,a,b,c;
	LL ans[6];
	char s[19];
	int dig[19];
	bool dyn[20][10];
	int prevA[20][10],prevB[20][10],prevC[20][10],prevJ[20][10];
	Read(T);
		while (T--)
		{
			scanf("%s",&s);
			Fill(dig,0);
			j=strlen(s);
				Fox(i,j)
					dig[i]=s[j-i-1]-'0';
			Fill(dyn,0);
			dyn[0][0]=1;
				Fox(i,19)
					Fox(j,10)
						if (dyn[i][j])
							Fox(a,7)
								Fox(b,7-a)
								{
									c=6-a-b;
									k=j + b*4 + c*7;
										if (k%10!=dig[i])
											continue;
									k/=10;
										if (!dyn[i+1][k])
										{
											dyn[i+1][k]=1;
											prevA[i+1][k]=a;
											prevB[i+1][k]=b;
											prevC[i+1][k]=c;
											prevJ[i+1][k]=j;
										}
								}
				if (!dyn[19][0])
					printf("-1\n");
				else
				{
					Fill(ans,0);
					j=0;
						FoxR1(i,19)
						{
							a=prevA[i][j];
							b=prevB[i][j];
							c=prevC[i][j];
								Fox(k,a)
									ans[k]=ans[k]*10;
								FoxI(k,a,a+b-1)
									ans[k]=ans[k]*10 + 4;
								FoxI(k,a+b,5)
									ans[k]=ans[k]*10 + 7;
							j=prevJ[i][j];
						}
						Fox(i,6)
						{
							cout << ans[i];
								if (i==5)
									printf("\n");
								else
									printf(" ");
						}
				}
		}
	return(0);
}