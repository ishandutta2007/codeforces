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

const int N = 200005;

int n;
vi lst[N];

int color[N];
int maxcol = 1;
void rec(int idx, int par){
    int colnow = 1;
    rep(i, 0, (int)lst[idx].size()-1){
        if(lst[idx][i] == par)continue;
        while(colnow == color[idx] || colnow == color[par])colnow++;
        color[lst[idx][i]] = colnow++;
        rec(lst[idx][i], idx);
    }
    maxcol = max(maxcol, colnow-1);
}

int main(){
    scanf("%d",&n);
    rep(i,1,n-1){
        int a,b;
        scanf("%d %d",&a,&b);
        lst[a].pb(b);
        lst[b].pb(a);
    }

    color[1] = 1;
    rec(1, 0);
    printf("%d\n",maxcol);
    rep(i,1,n)printf("%d ",color[i]);
    printf("\n");
    return 0;
}