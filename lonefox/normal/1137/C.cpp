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
//#define LIM 50005

#if DEBUG
#define LIM 50005
#else
#define LIM 5000005
#endif

int V,NC;
//int group_cnt;
vector<int> adj[LIM];
//radj[LIM];
int zz;
//bool vis[LIM];
char sss[LIM];
int stk[LIM],S;
vector<int> emp;

int discovery[LIM], low_link[LIM];
int index;

bool on_stack[LIM];

vector<int> components[LIM];
int which_component[LIM];

// Tarjan's algorithm
void dfs(int node) {
    discovery[node] = low_link[node] = index++;
    stk[S++] = node;
    on_stack[node] = true;

	int i;
	Fox(i,Sz(adj[node])) {
		int neighbor = adj[node][i];
        if (discovery[neighbor] == -1) {
            dfs(neighbor);
            low_link[node] = min(low_link[node], low_link[neighbor]);
        } else if (on_stack[neighbor]) {
            low_link[node] = min(low_link[node], discovery[neighbor]);
        }
	}

    if (low_link[node] == discovery[node]) {
        vector<int> &component = components[NC++];
        int x;

        do {
            assert(S > 0);
            x = stk[--S];
            on_stack[x] = false;
            component.push_back(x);
            which_component[x] = NC - 1;
        } while (x != node);
    }
}

void build() {
	Fill(discovery,-1);
	Fill(low_link,-1);
	Fill(which_component,-1);

    S = 0;
    index = 0;

    for (int i = 0; i < V; i++)
        if (discovery[i] == -1)
            dfs(i);
}

int C[LIM];

/*int rec(int i)
{
	int j,c;
		if (stk[i]>=0)
			return(stk[i]);
	int m=0;
		Fox(j,Sz(radj[i]))
		{
			c=rec(radj[i][j]);
			Max(m,c);
		}
	return(stk[i]=C[i]+m);
}*/

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	//freopen("in2.txt","r",stdin);
	int N,M,K;
	int a,b,i,j,k,x,y;
	Read(N),Read(M),Read(K);
	//N=100000, M=100000, K=50;
	V=N*K;
		while (M--)
		{
			Read(a),Read(b),a--,b--;
			//a=rand()%N, b=rand()%N;
			b+=N;
				Fox(i,K)
				{
						if (a>=V)
							a-=V;
						if (b>=V)
							b-=V;
					adj[a].pb(b);
					//radj[b].pb(a);
					a+=N;
					b+=N;
				}
		}
	build();
	M=NC;
		/*Fox(i,V)
			radj[i].clear();*/
	Fill(stk,0);
		Fox(i,N)
		{
			scanf("%s",&sss);
			zz++;
			k=i;
				Fox(j,K)
				{
						if (sss[j]=='1')
						//if (rand()&1)
						{
							a=which_component[k];
								if (stk[a]!=zz)
								{
									C[a]++;
									stk[a]=zz;
								}
						}
					k+=N;
				}
		}
	Fill(stk,0);
	for (int i = 0; i < M; i++) {
		Fox(j,Sz(components[i]))
		{
			x=components[i][j];
			Fox(k,Sz(adj[x]))
			{
            int neighbor=adj[x][k];
                stk[i] = max(stk[i], stk[which_component[neighbor]]);
			}
		}

        stk[i] += C[i];
    }

	printf("%d\n",stk[which_component[0]]);
	return(0);
}