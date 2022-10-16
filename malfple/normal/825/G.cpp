#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define repp(i,a,b,d) for(int i=a;i<=b;i+=d)
#define rep(i,a,b) repp(i,a,b,1)
#define revv(i,a,b,d) for(int i=a;i>=b;i-=d)
#define rev(i,a,b) revv(i,a,b,1)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

//end of macro

const int N = 1000005;

int n,q;
vi lst[N];
int root;

int p[N];
int mintoroot[N];
inline void dfs(int idx, int par){
    stack<pii>stk;
    stk.push(mp(idx,par));
    while(!stk.empty()){
        idx = stk.top().ff;
        par = stk.top().ss;
        stk.pop();

        p[idx] = par;
        mintoroot[idx] = idx;
        if(par != -1)mintoroot[idx] = min(mintoroot[idx], mintoroot[par]);

        rep(i,0,(int)lst[idx].size()-1){
            if(lst[idx][i] == par)continue;
            stk.push(mp(lst[idx][i], idx));
        }
    }
}

int globalmin;
bool vis[N];

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie();

    scanf("%d %d",&n,&q);
    rep(i,1,n-1){
        int a,b;
        scanf("%d %d",&a,&b);
        lst[a].pb(b);
        lst[b].pb(a);
    }

    int ord,x;
    scanf("%d %d",&ord,&x);
    root = (x%n)+1;

    dfs(root, -1);

    vis[root] = true;
    globalmin = root;

    int last = 0; // for modified query

    rep(i,2,q){
        scanf("%d %d",&ord,&x);
        x = ((x+last)%n)+1;

        if(ord == 1){
            while(!vis[x]){
                vis[x] = true;
                globalmin = min(globalmin, x);
                assert(x != p[x]);
                x = p[x];
            }
        }else if(ord == 2){
            last = min(globalmin, mintoroot[x]);
            printf("%d\n",last);
        }
    }

    return 0;
}