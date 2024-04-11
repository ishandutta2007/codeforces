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
#define LIM 300003

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N;
	LL X,Y;
	LL ans=0,cur,tmp;
	int i,j,c,ind[3],nxt[3];
	static int P[LIM],M[3],S[3][LIM];
	static char C[LIM];
	Read(N);
		Fox(i,N)
		{
			scanf("%d %c",&P[i],&C[i]);
				if (C[i]=='G')
					c=0;
				if (C[i]=='R')
					c=1;
				if (C[i]=='B')
					c=2;
			S[c][M[c]++]=P[i];
		}
		if (!M[0])
		{
				Fox1(c,2)
					if (M[c])
						ans+=S[c][M[c]-1] - S[c][0];
			cout << ans << endl;
			return(0);
		}
		Fox1(c,2)
		{
			//L
			if ((M[c]) && (S[c][0]<S[0][0]))
				ans+=S[0][0]-S[c][0];
			//R
			if ((M[c]) && (S[c][M[c]-1]>S[0][M[0]-1]))
				ans+=S[c][M[c]-1]-S[0][M[0]-1];
		}
	Fill(ind,0);
		Fox(i,M[0]-1)
		{
			X=S[0][i];
			Y=S[0][i+1];
				Fox1(c,2)
				{
						while ((ind[c]<M[c]) && (S[c][ind[c]]<X))
							ind[c]++;
					nxt[c]=ind[c];
						while ((nxt[c]<M[c]) && (S[c][nxt[c]]<Y))
							nxt[c]++;
				}
			cur=Y-X;
				Fox1(c,2)
					if (ind[c]<nxt[c])
					{
						tmp=INF;
							FoxI(j,ind[c],nxt[c])
							{
								LL v=0;
									if (j>ind[c])
										v+=S[c][j-1]-X;
									if (j<nxt[c])
										v+=Y-S[c][j];
								Min(tmp,v);
							}
						cur+=tmp;
					}
			ans+=min(2*(Y-X),cur);
				Fox1(c,2)
					ind[c]=nxt[c];
		}
	cout << ans << endl;
	return(0);
}