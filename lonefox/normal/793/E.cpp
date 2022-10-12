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
int K[2][2];
int par[5000],sz[5000];
vector<int> ch[5000];

void rec(int i)
{
	int j;
		if (!Sz(ch[i]))
			sz[i]=1;
		Fox(j,Sz(ch[i]))
		{
			int c=ch[i][j];
			rec(c);
			sz[i]+=sz[c];
		}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,c,z,k,p,a;
	int sz2[2][2];
	bool keyR[5000];
	bitset<5001> B[2],BB;
	Read(N);
		Fox(i,2)
			Fox(j,2)
				Read(K[i][j]),K[i][j]--;
		Fox1(i,N-1)
		{
			Read(j),j--;
			par[i]=j;
			ch[j].pb(i);
		}
	rec(0);
	int req=sz[0];
		if (req%2)
		{
No:;
			printf("NO\n");
			return(0);
		}
	req/=2;
	req++;
	Fill(keyR,0);
		Fox(z,2)
			Fox(k,2)
			{
				i=K[z][k];
					while (par[i])
						i=par[i];
				sz2[z][k]=sz[i];
				keyR[i]=1;
			}
		Fox(z,2)
		{
			B[0]=B[1]=0;
			B[0][1]=B[1][1]=1;
				Fox(k,2)
				{
					i=K[z][k];
						while (par[i])
						{
							p=i;
							i=par[i];
								Fox(j,Sz(ch[i]))
								{
									c=ch[i][j];
										if (c!=p)
											B[k]|=(B[k]<<sz[c]);
								}
						}
				}
			BB=B[0];
				Fox(i,Sz(ch[0]))
				{
					j=ch[0][i];
						if (!keyR[j])
							BB|=(BB<<sz[j]);
				}
				Fox1(i,req)
					Fox(a,2)
					{
						j=req-i-sz2[1-z][a];
							if (j<1)
								continue;
							if ((B[1][i]) && (BB[j]))
							{
								i=i;
								goto Good;
							}
					}
			goto No;
Good:;
		}
	printf("YES\n");
	return(0);
}