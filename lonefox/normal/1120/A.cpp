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
#define LIM 500005

int A[LIM];
int req[LIM],rem,nz;
int cnt[LIM];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K,S;
	int i,j,k,a,b,c,x,y,z;
	vector<int> ans;
	Read(M),Read(K),Read(N),Read(S);
		Fox(i,M)
			Read(A[i]),A[i]--;
		Fox(i,S)
		{
			Read(j),j--;
			req[j]++;
		}
		Fox(i,LIM)
			if (req[i])
				nz++;
	rem=nz;
	j=0;
		Fox(i,M)
		{
				while (rem || j-i<K)
				{
						if (j==M)
							goto Imp;
					k=A[j++];
						if ((++cnt[k])==req[k])
							rem--;
				}
			a=i;
			b=M-j;
				if (a/K + b/K + 1 >= N)
				{
					int del=(j-i)-K;
						FoxI(k,i,j-1)
						{
								if (!del)
									break;
							int v=A[k];
								if (cnt[v]>req[v])
								{
									del--;
									cnt[v]--;
									ans.pb(k);
								}
						}
					N--;
					del=a%K;
						if (a>K*N)
							del+=((a/K)-N)*K;
						Fox(k,del)
							ans.pb(k);
					goto Good;
				}
			k=A[i];
				if ((--cnt[k])==req[k]-1)
					rem++;
		}
	goto Imp;
Good:;
		/*if (Sz(ans)!=M-K*N)
			exit(1);*/
	printf("%d\n",Sz(ans));
		Fox(i,Sz(ans))
			printf("%d\n",ans[i]+1);
	return(0);
Imp:;
	printf("-1\n");
	return(0);
}