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

int n;
vii lst[105];

int rec(int idx, int par){
    int ret = 0;
    rep(i,0,(int)lst[idx].size()-1){
        if(lst[idx][i].ff == par)continue;
        ret = max(ret, rec(lst[idx][i].ff, idx) + lst[idx][i].ss);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    rep(i,1,n-1){
        int a,b,c;
        cin>>a>>b>>c;
        lst[a].pb(mp(b,c));
        lst[b].pb(mp(a,c));
    }
    cout << rec(0,-1) << endl;
    return 0;
}