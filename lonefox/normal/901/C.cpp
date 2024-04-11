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

#define MAX 300005

// Finds bridges and cut vertices
// Receives:
// N: number of vertices
// l: adjacency list
// Gives:
// vis, seen, par (used to find cut vertices)
// ap - 1 if it is a cut vertex, 0 otherwise
// brid - vector of pairs containing the bridges
typedef pair<int, int> PII;

int N,M;
vector <int> l[MAX];
vector <PII> brid;
int vis[MAX], seen[MAX], par[MAX], ap[MAX];
int cnt, root;

void dfs(int x){
  if(vis[x] != -1)
    return;
  vis[x] = seen[x] = cnt++;
  
  int adj = 0;
  for(int i = 0; i < (int)l[x].size(); i++){
    int v = l[x][i];
    if(par[x] == v)
      continue;
    if(vis[v] == -1){
      adj++;
      par[v] = x;
      dfs(v);
      seen[x] = min(seen[x], seen[v]);
      if(seen[v] >= vis[x] && x != root)
        ap[x] = 1;
      if(seen[v] == vis[v])
        brid.push_back(make_pair(v, x));
    }
    else{
      seen[x] = min(seen[x], vis[v]);
      seen[v] = min(seen[x], seen[v]);
    }
  }
  if(x == root) ap[x] = (adj>1);
}

void bridges(){
  brid.clear();
  for(int i = 0; i < N; i++){
    vis[i] = seen[i] = par[i] = -1;
    ap[i] = 0;
  }
  cnt = 0;
  for(int i = 0; i < N; i++)
    if(vis[i] == -1){
      root = i;
      dfs(i);
    }
}

set<PR> S;

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,k,c;
	static vector<PR> C,O,R;
	Read(N),Read(M);
		while (M--)
		{
			Read(i),Read(j),i--,j--;
			l[i].pb(j);
			l[j].pb(i);
		}
	bridges();
		Fox(i,Sz(brid))
		{
			S.insert(mp(brid[i].x,brid[i].y));
			S.insert(mp(brid[i].y,brid[i].x));
		}
	static bool vis[MAX];
		Fox(i,N)
			if (!vis[i])
			{
				int a,b;
				a=b=i;
				j=i;
Rep:;
				vis[j]=1;
				Min(a,j);
				Max(b,j);
					Fox(k,Sz(l[j]))
					{
						c=l[j][k];
							if ((!vis[c]) && (!S.count(mp(j,c))))
							{
								j=c;
								goto Rep;
							}
					}
					if (b>a)
				C.pb(mp(a,b));
			}
	sort(All(C));
	O=C;
	C.clear();
		Fox(i,Sz(O))
		{
				while ((!C.empty()) && (C[Sz(C)-1].y>=O[i].y))
					C.pop_back();
			C.pb(O[i]);
		}
		Fox(i,Sz(C))
			R.pb(mp(C[i].y,C[i].x));
	static vector<LL> V,VS;
		Fox(i,Sz(C))
		{
				if (!i)
					V.pb(0);
				else
					V.pb((LL)(C[i].x-C[i-1].x)*(1-C[i].y));
				if (!i)
					VS.pb(0);
				else
					VS.pb(VS[i-1]+V[i]);
		}
	Read(M);
		while (M--)
		{
			int A,B;
			Read(A),Read(B),A--,B--;
			int sz=B-A+1;
			LL ans=(LL)sz*(sz+1)/2;
			int a=lower_bound(All(C),mp(A,0))-C.begin();
			int b=lower_bound(All(R),mp(B+1,0))-R.begin();
			/*LL cor=ans;
				if (a<b) // TODO: REMOVE
				{
					int p=A;
						FoxI(i,a,b-1)
						{
							cor-=(LL)(C[i].x-p+1)*(B-C[i].y+1);
							p=C[i].x+1;
						}
				}*/
				if (a<b)
				{
					ans-=(LL)(C[a].x-A+1)*(B-C[a].y+1);
						if (a+1<=b-1)
							ans-=(LL)(C[b-1].x-C[a].x)*B;
					ans-=VS[b-1]-VS[a];
				}
				/*if (cor!=ans)
					printf("BAD\n");*/
			cout << ans << endl;
		}
	return(0);
}