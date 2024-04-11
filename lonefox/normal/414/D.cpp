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
	int N,K,P;
	int i,j,k,ans=0,cur,end;
	int r1,r2,m;
	LL c;
	static vector<int> con[100001];
	static int dep[100001],cnt[100001],sum[100001];
	static LL sum2[100001];
	queue <int> Q;
	Read(N),Read(K),Read(P);
		if (K)
			ans=1;
	N--;
		while (N--)
		{
			Read(i),Read(j),i--,j--;
			con[i].pb(j);
			con[j].pb(i);
		}
	Fill(dep,-1);
	Q.push(0),dep[0]=0;
	end=0;
		while (!Q.empty())
		{
			i=Q.front(),Q.pop();
			cnt[dep[i]]++;
			Max(end,dep[i]);
				Fox(j,Sz(con[i]))
					if (dep[k=con[i][j]]<0)
						Q.push(k),dep[k]=dep[i]+1;
		}
		Fox1(i,end)
		{
			sum[i]=sum[i-1]+cnt[i];
			sum2[i]=sum2[i-1]+sum[i];
			r1=1,r2=i;
				while (r1<=r2)
				{
					m=(r1+r2)>>1;
					c=sum2[i-1]-sum[m-1]*(i-(m-1)-1)-sum2[m-1];
						if (c>P)
							r1=m+1;
						else
						{
							c=P-c;
							cur=sum[i]-sum[m-1];
								if (m-1>0)
									cur+=min((LL)cnt[m-1],c/(i-(m-1)));
							Max(ans,cur);
							r2=m-1;
						}
				}
		}
	printf("%d\n",min(K,ans));
	return(0);
}