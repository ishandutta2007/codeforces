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
	int T,N,P;
	int deg[24];
	bool con[24][24];
	PR nxt[24];
	int i,j,e;
	Read(T);
		while (T--)
		{
			Read(N),Read(P);
			Fill(con,0);
			Fill(deg,0);
			e=2*N+P;
				while (e--)
				{
						Fox(i,N)
							nxt[i]=mp(deg[i],i);
					sort(nxt,nxt+N);
						Fox(i,N)
							Fox(j,i)
								if (!con[nxt[i].y][nxt[j].y])
								{
									i=nxt[i].y;
									j=nxt[j].y;
									deg[i]++;
									deg[j]++;
									con[i][j]=con[j][i]=1;
									printf("%d %d\n",i+1,j+1);
									goto Done;
								}
Done:;
				}
			/*int b;
				Fox(b,(1<<N))
				{
					int c=0,j,k=0;
						Fox(i,N)
							if (b&(1<<i))
							{
								k++;
									Fox(j,i)
										if (b&(1<<j))
											if (con[i][j])
												c++;
							}
						if (c>2*k+P)
							printf("BAD\n");
				}*/
		}
	/*int N;
	int i,j,k,p;
	bool mat[20][20],tmp[20][20];
	Fill(mat,0);
	N=4;
	mat[0][0]=1;
	mat[1][0]=mat[1][1]=mat[1][2]=mat[1][3]=1;
	mat[2][0]=mat[2][1]=mat[2][2]=mat[2][3]=1;
	mat[3][0]=mat[3][1]=mat[3][2]=mat[3][3]=1;
		Fox(p,20)
		{
			Fill(tmp,0);
				Fox(i,N)
					Fox(j,N)
						Fox(k,N)
							tmp[i][j]|=mat[i][k]&mat[k][j];
			memcpy(mat,tmp,sizeof(mat));
		}
		Fox(i,N)
		{
				Fox(j,N)
					printf("%d ",mat[i][j]);
			printf("\n");
		}*/
	return(0);
}