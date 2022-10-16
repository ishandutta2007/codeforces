#include <iostream>
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

const int N = 100005;

int n,m;
int cond[N];
int num[N];

map<pii, int>mep;
vector<pii>lst[N];

int vis[N];
bool dfs(int now, int val){
    vis[now] = val;

    rep(i,0,(int)lst[now].size()-1){
        int t = lst[now][i].ff;
        int v = lst[now][i].ss ^ val;

        if(vis[t] == -1){
            if(!dfs(t, v))return false;
        }else{
            if(vis[t] != v)return false;
        }
    }
    return true;
}

int main(){
    scanf("%d %d",&n,&m);
    rep(i,1,n)scanf("%d",&cond[i]);
    rep(i,1,n)cond[i] ^= 1;

    bool alreadyfail = false;
    rep(i,1,m){
        int x;
        scanf("%d",&x);
        rep(j,1,x){
            int y;
            scanf("%d",&y);
            if(num[y] == 0){
                num[y] = i;
            }else{
                if(mep.find(mp(num[y], i)) != mep.end()){
                    if(mep[mp(num[y], i)] != cond[y])alreadyfail = true;
                }else{
                    mep[mp(num[y], i)] = cond[y];
                    lst[num[y]].pb(mp(i, cond[y]));
                    lst[i].pb(mp(num[y], cond[y]));
                }
            }
        }
    }

    if(alreadyfail){
        printf("NO\n");
        return 0;
    }

    bool fail = false;
    rep(i,1,m)vis[i] = -1;
    rep(i,1,m){
        if(vis[i] != -1)continue;
        if(!dfs(i, 0))fail = true;
        if(fail)break;
    }

    if(fail)printf("NO\n");
    else printf("YES\n");

    return 0;
}