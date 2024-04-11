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
	int N,M,Q;
	int i,j,y,x,i2,j2,d,d2,y2,x2,m;
	int a1,a2,a3,a4;
	char s[45];
	int G[41][41],sum[41][41]={0},sum2[41][41]={0};
	static int dyn[41][41][41][41];
	Read(N),Read(M),Read(Q);
		Fox1(i,N)
		{
			scanf("%s",&s);
				Fox1(j,M)
				{
					G[i][j]=s[j-1]-'0';
					sum[i][j]=sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + G[i][j];
				}
		}
		Fox(d2,N)
			Fox1(i,N)
			{
				i2=i+d2;
					if (i2>N)
						break;
					Fox(d,M)
						Fox1(j,M)
						{
							j2=j+d;
								if (j2>M)
									break;
								if ((i==4) && (i2==4) && (j==5) && (j2==5))
									i=i;
							dyn[i][j][i2][j2]+=(sum[i2][j2]-sum[i2][j-1]-sum[i-1][j2]+sum[i-1][j-1]==0 ? 1 : 0);
								Fox(a1,2)
									Fox(a2,2)
										Fox(a3,2)
											Fox(a4,2)
											{
													if (a1+a2+a3+a4==0)
														continue;
												y=i+a1;
												y2=i2-a2;
												x=j+a3;
												x2=j2-a4;
													if ((y2<y) || (x2<x))
														continue;
													if (a1+a2+a3+a4==1)
														m=1;
													if (a1+a2+a3+a4==2)
														m=-1;
													if (a1+a2+a3+a4==3)
														m=1;
													if (a1+a2+a3+a4==4)
														m=-1;
													if ((i==1) && (j==1) && (i2==2) && (j2==2))
														i=i;
												dyn[i][j][i2][j2]+=m*dyn[y][x][y2][x2];
											}
								/*if ((d) && (d2))
								{
									dyn[i][j][i2][j2]+=dyn[i][j][i2][j2-1];
									dyn[i][j][i2][j2]+=dyn[i][j+1][i2][j2];
									dyn[i][j][i2][j2]-=dyn[i][j+1][i2][j2-1];
									dyn[i][j][i2][j2]+=dyn[i][j][i2-1][j2];
									dyn[i][j][i2][j2]+=dyn[i+1][j][i2][j2];
									dyn[i][j][i2][j2]-=dyn[i+1][j][i2-1][j2];
								}
								else
								if (d)
								{
									dyn[i][j][i2][j2]+=dyn[i][j][i2][j2-1];
									dyn[i][j][i2][j2]+=dyn[i][j+1][i2][j2];
									dyn[i][j][i2][j2]-=dyn[i][j+1][i2][j2-1];
								}
								else
								if (d2)
								{
									dyn[i][j][i2][j2]+=dyn[i][j][i2-1][j2];
									dyn[i][j][i2][j2]+=dyn[i+1][j][i2][j2];
									dyn[i][j][i2][j2]-=dyn[i+1][j][i2-1][j2];
								}*/
						}
			}
		/*Fox1(i,N)
			FoxI(i2,i,N)
				Fox1(j,M)
					FoxI(j2,j,M)
						sum2[i2][j2]+=(sum[i2][j2]-sum[i2][j-1]-sum[i-1][j2]+sum[i-1][j-1]==0 ? 1 : 0);
		Fox1(i,N)
			Fox1(j,M)
				sum2[i][j]+=sum2[i-1][j] + sum2[i][j-1] - sum2[i-1][j-1];*/
		while (Q--)
		{
			Read(i),Read(j),Read(y),Read(x);
			printf("%d\n",dyn[i][j][y][x]);
			//printf("%d\n",sum2[y][x]-sum2[i-1][x]-sum2[y][j-1]+sum2[i-1][j-1]);
		}
	return(0);
}