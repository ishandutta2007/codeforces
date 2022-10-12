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

bool ReadLL(LL &x)
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
#define LIM 100000

vector<int> dv[LIM+1];
int cnt1[130],cnt2[130];
int lst[390];
int lstD[390];
int dyn1[390][8],dyn2[390][8];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int T,N,M,K;
	int i,j,k,a,b,c,d,x,y,z,v,p;
	int poss[8][8]={0};
	int b1,b2;
		Fox(b1,8)
			Fox(b2,8)
				Fox(a,3)
					if (b1&(1<<a))
						Fox(b,3)
						if (a!=b)
							if (b2&(1<<b))
								Fox(c,3)
									if ((a!=c) && (b!=c))
										poss[b1][b2]|=(1<<c);
	k=0;
		Fox1(i,LIM)
		{
				for (j=i; j<=LIM; j+=i)
					dv[j].pb(i);
			Max(k,Sz(dv[i]));
		}
	Read(T);
		while (T--)
		{
			int A,B,C;
			Read(A),Read(B),Read(C);
			int NA=Sz(dv[A]);
			int NB=Sz(dv[B]);
			int NC=Sz(dv[C]);
			K=0;
				Fox(i,NA)
					lst[K++]=dv[A][i];
				Fox(i,NB)
					lst[K++]=dv[B][i];
				Fox(i,NC)
					lst[K++]=dv[C][i];
			sort(lst,lst+K);
			K=unique(lst,lst+K)-lst;
				Fox(i,K)
				{
					v=lst[i];
					lstD[i]=0;
						if (A%v==0)
							lstD[i]+=1;
						if (B%v==0)
							lstD[i]+=2;
						if (C%v==0)
							lstD[i]+=4;
				}
				Fox(i,K)
				{
					Fill(dyn1[i],0);
					Fill(dyn2[i],0);
				}
				Fox(i,K)
				{
					dyn1[i][lstD[i]]++;
						Fox(j,8)
							dyn1[i+1][j]+=dyn1[i][j];
				}
				Fox(i,K)
				{
					Fox(j,8)
						if (d=dyn1[i][j])
						{
							dyn2[i][b=poss[j][lstD[i]]]+=d;
								/*if (DEBUG)
							printf("%d (%d) %d -> %d\n",i,lstD[i],j,b);*/
						}
					Fox(j,8)
						dyn2[i+1][j]+=dyn2[i][j];
				}
			int ans=0;
				Fox(i,K)
					Fox(j,8)
						if (d=dyn2[i][j])
							if ((j&lstD[i])!=0)
							{
								ans+=d;
								/*if (DEBUG)
								printf("ans: %d %d + %d\n",i,j,d);*/
							}
				/*if (DEBUG)
				{
					printf("lst:\n");
					Fox(i,K)
						printf("%d %d\n",lst[i],lstD[i]);
					printf("1:\n");
					Fox(i,K)
						Fox(j,8)
							if (d=dyn1[i][j])
								printf("%d %d .. %d\n",i,j,d);
					printf("2:\n");
					Fox(i,K)
						Fox(j,8)
							if (d=dyn2[i][j])
								printf("%d %d .. %d\n",i,j,d);
				}*/
			printf("%d\n",ans);
				if (DEBUG)
				{
					int cor=0;
					int mx=max(A,max(B,C));
						Fox1(a,mx)
							FoxI(b,a,mx)
								FoxI(c,b,mx)
								{
										if (A%a==0 && B%b==0 && C%c==0)
											goto Good;
										if (A%a==0 && C%b==0 && B%c==0)
											goto Good;
										if (B%a==0 && A%b==0 && C%c==0)
											goto Good;
										if (B%a==0 && C%b==0 && A%c==0)
											goto Good;
										if (C%a==0 && A%b==0 && B%c==0)
											goto Good;
										if (C%a==0 && B%b==0 && A%c==0)
											goto Good;
									continue;
Good:;
									cor++;
								}
						if (cor!=ans)
							printf("SHOULD BE %d\n",cor);
				}
		}
	return(0);
}