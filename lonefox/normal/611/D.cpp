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

#define MOD 1000000007

int L;
char s[5005];

struct SuffixArray {
	vector<vector<int> > P;

  SuffixArray(int xxx) {
	  vector<vector<int> > P2(1, vector<int>(L, 0));
		  P=P2;
  vector<pair<pair<int,int>,int> > M(L);
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++) 
	M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++) 
	P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }    
  }

  vector<int> GetSuffixArray() { return P.back(); }

  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int LCP(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
	i += 1 << k;
	j += 1 << k;
	len += 1 << k;
      }
    }
    return len;
  }
};

void Add(int &a,int b)
{
	a+=b;
		if (a>=MOD)
			a-=MOD;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N;
	int i,j,k,c,a,b,d;
	static int dyn[5005][5005];
	static int nxt[5005][5005];
	Read(N);
	L=N;
	scanf("%s",&s);
	Fill(nxt,60);
	SuffixArray sa(1);
		Fox(i,N)
			FoxI(j,i,N-1)
				if ((j==N-1) || (s[j+1]=='0'))
					continue;
				else
				{
					k=j+(j-i)+1;
						if (k>=N)
							break;
					c=sa.LCP(i,j+1);
					a=i+c;
					b=j+1+c;
						if ((b<=k) && (s[b]>s[a]))
							k=k;
						else
							k++;
					nxt[i][j]=k;
				}
		Fox(i,N)
			dyn[0][i]=1;
		Fox(i,N)
			FoxI(j,i,N-1)
			{
				d=dyn[i][j];
					if ((i) && (j))
					{
						Add(d,dyn[i][j-1]);
						dyn[i][j]=d;
					}
					if (!d)
						continue;
				k=nxt[i][j];
					if (k>=N)
						continue;
				Add(dyn[j+1][k],d);
			}
	int ans=0;
		Fox(i,N)
			Add(ans,dyn[i][N-1]);
	printf("%d\n",ans);
	return(0);
}