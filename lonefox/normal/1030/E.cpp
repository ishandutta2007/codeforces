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
#define LIM 300003

int sum[LIM],V[LIM];
PR P[LIM];
set<int> S;
set<int>::iterator I,J;

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,D,M,K;
	int i,j,k,a,b,c,x,y,z,m,s1,s2,s;
	LL v,ans;
	Read(N);
		Fox1(i,N)
		{
			ReadLL(v);
			c=0;
				while (v)
				{
					c+=v%2;
					v/=2;
				}
			sum[i]=sum[i-1]+c;
			P[i-1]=mp(-c,i);
			V[i]=c;
		}
	sort(P,P+N);
	S.insert(0);
	S.insert(N+1);
	int cnt[2]={0};
	ans=0;
	s=0;
	cnt[0]++;
		Fox1(i,N)
		{
			s+=V[i];
			ans+=cnt[s%2];
			cnt[s%2]++;
		}
		Fox(i,N)
		{
			c=-P[i].x;
			j=P[i].y;
			I=J=S.lower_bound(j);
			I--;
			a=*I+1;
			b=*J-1;
			S.insert(j);
			// sub
			s1=0;
				FoxRI(x,a,j)
				{
					s1+=V[x];
						if (s1>=c*2)
							break;
					s2=0;
						FoxI(y,j,b)
						{
							s2+=V[y];
								if (s1+s2-c>=c*2)
									break;
								if ((s1+s2-c)%2==0)
								{
									ans--;
									//printf("%d %d %d\n",x,j,y);
								}
						}
				}
		}
	cout << ans << endl;
		if (DEBUG)
		{
			LL cor=0;
				Fox1(i,N)
				{
					v=m=0;
						FoxI(j,i,N)
						{
							v+=V[j];
							Max(m,V[j]);
								if ((v%2==0) && (v>=m*2))
									cor++;
						}
				}
				/*if (ans!=cor)
					printf("SHOULD BE %lld\n",cor);*/
		}
	return(0);
}