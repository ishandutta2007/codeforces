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

#define LIM 3000000

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	int i,j,k,a,b,s,tmp1,tmp2,lev,nxt,v;
	LL ans=0;
	bool rev[22]={0};
	static vector<int> lst[LIM];
	static LL inv1[22],inv2[22];
	static int V[LIM];
	Read(N);
	M=1;
		Fox(i,N)
			M<<=1;
		Fox(i,M)
		{
			Read(j);
			V[i]=j;
			lst[M+i].pb(j);
		}
	nxt=M,lev=0;
		FoxR1(i,M-1)
		{
				if (i<nxt)
					nxt>>=1,lev++;
			j=i<<1;
			k=j+1;
			a=b=0;
			s=Sz(lst[j]);
				while ((a<s) && (b<s))
					if (lst[j][a]==lst[k][b])
					{
						tmp1=tmp2=0;
						v=lst[j][a];
							while ((a<s) && (lst[j][a]==v))
								lst[i].pb(lst[j][a++]),tmp1++;
							while ((b<s) && (lst[k][b]==v))
								lst[i].pb(lst[k][b++]),tmp2++;
						inv2[lev]+=(LL)tmp1*(s-b);
						inv1[lev]+=(LL)tmp2*(s-a);
					}
					else
					if (lst[j][a]<lst[k][b])
					{
						lst[i].pb(lst[j][a]);
						a++;
						inv2[lev]+=s-b;
					}
					else
					{
						lst[i].pb(lst[k][b]);
						b++;
						inv1[lev]+=s-a;
					}
				while (a<s)
					lst[i].pb(lst[j][a++]);
				while (b<s)
					lst[i].pb(lst[k][b++]);
		}
	lev++;
		Fox(i,lev)
			ans+=inv1[i];
	Read(N);
		while (N--)
		{
			Read(j);
				Fox1(i,j)
				{
						if (!rev[i])
							ans+=inv2[i]-inv1[i];
						else
							ans+=inv1[i]-inv2[i];
					rev[i]=!rev[i];
				}
			printf("%I64d\n",ans);
			/*a=1<<j;
			b=M/a;
				Fox(i,b)
				{
					int strt=a*i;
					int end=strt+a-1;
						FoxI(k,strt,end)
						{
							int k2=end-(k-strt);
								if (k2<k)
									break;
							swap(V[k],V[k2]);
						}
				}
			LL real=0;
				Fox(b,M)
					Fox(a,b)
						if (V[a]>V[b])
							real++;
				if (ans!=real)
					printf("WRONG\n");*/
		}
	return(0);
}