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
const double EPS = 1e-6;
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
int BLT[100001];

void update(int i,int v)
{
		for (i++;i<=N;i+=(i&-i))
			BLT[i]+=v;
}

int query(int i)
{
	int v=0;
		for (i++;i>0;i-=(i&-i))
			v+=BLT[i];
	return(v);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int M,K;
	int i,j,v,r1,r2;
	bool rev=0;
	Read(N),Read(M);
	K=N;
	r1=0;
	r2=N-1;
		Fox(i,N)
			update(i,1);
		while (M--)
		{
				/*FoxI(i,r1,r2)
					printf("%d ",query(i)-query(i-1));
			printf("\n");*/
			Read(i);
				if (i==1)
				{
					Read(i);
						if (i>K-i)
						{
							rev=!rev;
							i=K-i;
						}
					K-=i;
						if (!rev)
						{
							r1+=i;
								Fox(j,i)
								{
									v=query(r1-j-1)-query(r1-j-2);
									update(r1+j,v);
								}
						}
						else
						{
							r2-=i;
								Fox(j,i)
								{
									v=query(r2+j+1)-query(r2+j);
									update(r2-j,v);
								}
						}
				}
				else
				{
					Read(i),Read(j),j--;
						if (!rev)
						{
							i+=r1;
							j+=r1;
						}
						else
						{
							i=r2-i;
							j=r2-j;
							swap(i,j);
						}
					printf("%d\n",query(j)-query(i-1));
				}
		}
	return(0);
}