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

#define LIM 200005

#define SZ 1325497237
#define BS 1473

#include <unordered_set>
unordered_set<int> vis;

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K,A,B;
	int i,j,k,a,b,c,x,y,z,d,h,p;
	char S[5001];
	int V[5001];
	int H[5001];
	static bool C[5001][5001];
	int dyn[5001];
	Read(N),Read(A),Read(B);
	scanf("%s",&S);
		Fox(i,N)
			V[i]=S[i]-'a';
		Fox1(k,N)
		{
			vis.clear();
			h=0;
				Fox(i,k)
					h=((LL)h*BS+V[i])%SZ;
			p=1;
				Fox(i,k-1)
					p=(LL)p*BS%SZ;
				Fox(i,N-k+1)
				{
					H[i]=h;
						if (vis.count(h))
							C[i][i+k-1]=1;
					j=i-k+1;
						if (j>=0)
							vis.insert(H[j]);
					h=((h-(LL)p*V[i])%SZ+SZ)%SZ;
					h=((LL)h*BS+V[i+k])%SZ;
				}
		}
	Fill(dyn,60);
	dyn[0]=0;
		Fox(i,N)
		{
			d=dyn[i];
			Min(dyn[i+1],d+A);
				FoxI(j,i,N-1)
					if (C[i][j])
						Min(dyn[j+1],d+B);
					else
						break;
		}
	printf("%d\n",dyn[N]);
	return(0);
}