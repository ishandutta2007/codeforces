#define DEBUG 0

#include <unordered_map>
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
#define LIM 5000

struct St {
	int i,f,e[4],d;
};

int A[2001],B[2001];
unordered_map<int,int> M;
//map<int,int> M;
queue<int> Q;

void Go(St s)
{
	int k;
	int h=s.i;
	h*=10;
	h+=s.f;
	sort(s.e,s.e+4);
		Fox(k,4)
		{
			h*=10;
			h+=s.e[k];
		}
		if (!M.count(h))
		{
			Q.push(h);
			M[h]=s.d;
		}
}

St Get(int h)
{
	int k;
	St s;
	s.d=M[h];
		FoxR(k,4)
		{
			s.e[k]=h%10;
			h/=10;
		}
	s.f=h%10;
	h/=10;
	s.i=h;
	return(s);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,K;
	int i,j,k,c,x,y,z;
	int h;
	St s,s2;
	Read(N);
//N=2000;
	s.i=s.f=s.d=0;
	Fill(s.e,0);
	Go(s);
		Fox(i,N)
			Read(A[i]),Read(B[i]);
//A[i]=rand()%9+1,B[i]=rand()%9+1;
		while (!Q.empty())
		{
			h=Q.front(),Q.pop();
			s=Get(h);
			//printf("%d %d: %d %d %d %d %d\n",s.d,s.i,s.f,s.e[0],s.e[1],s.e[2],s.e[3]);
			//done?
				if (s.e[0]+s.e[1]+s.e[2]+s.e[3]==0 && s.i==N)
				{
					printf("%d\n",s.d);
					return(0);
				}
			s.d++;
			//drop off
				Fox(k,4)
					if (s.f==s.e[k]-1)
					{
						s2=s;
						s2.e[k]=0;
						Go(s2);
goto Done;
					}
			//get next guy
				if (s.i<N && s.f==A[s.i]-1)
					FoxR(k,4)
						if (!s.e[k])
						{
							s2=s;
							s2.e[k]=B[s.i];
							s2.i++;
							Go(s2);
goto Done;
						}
int mn=INF,mx=-INF;
if (s.i<N)
{
Min(mn,A[s.i]-1);
Max(mx,A[s.i]-1);
}
Fox(k,4)
if (s.e[k])
{
Min(mn,s.e[k]-1);
Max(mx,s.e[k]-1);
}
			//up
				if (s.f+1<=mx)
				{
					s2=s;
					s2.f++;
					Go(s2);
				}
			//down
				if (s.f-1>=mn)
				{
					s2=s;
					s2.f--;
					Go(s2);
				}
Done:;
		}
	return(0);
}