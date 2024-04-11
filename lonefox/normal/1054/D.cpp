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
#define LIM 200005

map<int,int> M1;//M2;
int V[LIM];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z,v;
	Read(N),Read(K);
	int P=(1<<K)-1;
	int g1=0,g2=P;
	LL tot=(LL)N*(N+1)/2;
	//LL c1=0,c2=0;
	LL ans=0;
	M1[0]=1;
	//M2[0]=1;
		Fox(i,N)
		{
			Read(v);
			//v=rand()%P;
			V[i]=v;
			g1^=v;
			g2=P-g1;
			/*LL b1=min(c1+M1[g1],c1+M2[g1]);
			LL b2=min(c2+M1[g2],c2+M2[g2]);
			c1=b1,c2=b2;*/
			ans+=min(M1[g1],M1[g2]);
			//printf("%d %d: ",M1[g1],M1[g2]);
				if (M1[g1]<=M1[g2])
				{
					//printf("%d\n",v);
					M1[g1]++;
				}
				else
				{
					//printf("%d\n",P-v);
					M1[g2]++;
				}
			/*M1[g1]++;
			M2[g2]++;*/
		}
	cout << tot-ans << endl;
	/*LL cor=INF;
		Fox(b,1<<N)
		{
			M1.clear();
			M1[0]=1;
			LL cur=0;
			int g=0;
				Fox(i,N)
				{
						if (b&(1<<i))
							v=P-V[i];
						else
							v=V[i];
					g^=v;
					cur+=M1[g];
					M1[g]++;
				}
			Min(cor,cur);
		}
		if (cor!=ans)*/
	return(0);
}