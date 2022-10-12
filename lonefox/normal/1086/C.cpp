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
#define LIM 1000005

int N,K;
bool done;
char S[LIM],A[LIM],B[LIM];
int ord[26],inv[26];

void rec(int i,bool Ea,bool Eb)
{
		if (i==N)
		{
			done=1;
			return;
		}
	int s=S[i]-'a';
	int a=A[i]-'a';
	int b=B[i]-'a';
	int r1=0,r2=K-1,c;
	bool f=0;
		if (ord[s]>=0)
			r1=r2=ord[s],f=1;
		FoxI(c,r1,r2)
			if ((f) || (inv[c]<0))
			{
				bool Ea2=0,Eb2=0;
					if (Ea)
						if (c<a)
							continue;
						else
						if (c==a)
							Ea2=1;
					if (Eb)
						if (c>b)
							continue;
						else
						if (c==b)
							Eb2=1;
					if (!f)
						ord[s]=c,inv[c]=s;
				rec(i+1,Ea2,Eb2);
					if (done)
						return;
					if (!f)
						ord[s]=inv[c]=-1;
			}
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int T;
	int i,j,k,a,b,c,x,y,z;
	Read(T);
	//T=1;
		while (T--)
		{
			Read(K);
			//K=26;
			scanf("%s%s%s",&S,&A,&B);
			N=strlen(S);
			/*N=1000000;
				Fox(i,N)
					S[i]=A[i]=B[i]='z';*/
			Fill(ord,-1);
			Fill(inv,-1);
			done=0;
			rec(0,1,1);
				if (!done)
				{
					printf("NO\n");
					continue;
				}
			printf("YES\n");
			j=0;
				Fox(i,K)
				{
						if (ord[i]<0)
						{
								while (inv[j]>=0)
									j++;
							ord[i]=j++;
						}
					printf("%c",ord[i]+'a');
				}
			printf("\n");
		}
	return(0);
}