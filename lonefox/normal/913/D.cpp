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

#define MOD 1000000007
#define LIM 200005

int CC[2],CT[2];
set<PR> S[2],CS[2];
set<PR>::iterator I;

void Ins(int i,PR p)
{
	CS[i].insert(p);
	CC[i]++,CT[i]+=p.x;
}

void Del(int i,PR p)
{
	CS[i].erase(p);
	CC[i]--,CT[i]-=p.x;
}

void DelLast(int i)
{
	I=CS[i].end(),I--;
	Del(i,*I);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,T,K;
	int i,j,a,t;
	static vector<PR> P[LIM];
	int ansV=0;
	set<int> ansS;
	set<int>::iterator J;
	Read(N),Read(T);
	set<PR> O;
		Fox1(i,N)
		{
			Read(a),Read(t);
			P[a+1].pb(mp(t,i));
			O.insert(mp(t,i));
		}
	int z;
		Fox(z,2)
		{
			S[0]=O;
			CS[0].clear();
			CC[0]=CT[0]=0;
				Fox1(K,N)
				{
					Fox(i,Sz(P[K]))
					{
						t=P[K][i].x;
						j=P[K][i].y;
						PR p=mp(t,j);
						S[0].erase(p);
							if (CS[0].count(p))
								Del(0,p);
					}
					if (Sz(S[0])<K)
						break;
					if (!CS[0].empty())
						I=S[0].lower_bound(*CS[0].rbegin()),I++;
					else
						I=S[0].begin();
					while (CC[0]<K)
					{
						Ins(0,*I),I++;
							if (CT[0]>T)
								goto Out;
					}
					if (CT[0]<=T)
					{
							if (!z)
								ansV=K;
							else
							if (K==ansV)
							{
								Foxen(I,CS[0])
									ansS.insert(I->y);
								break;
							}
					}
				}
Out:;
		}
	printf("%d\n%d\n",ansV,Sz(ansS));
	i=0;
		Foxen(J,ansS)
		{
				if (i++)
					printf(" ");
			printf("%d",*J);
		}
	printf("\n");
	return(0);
}