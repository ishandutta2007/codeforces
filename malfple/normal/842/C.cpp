#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

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

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

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

const int N = 2e5 + 5;

int n;
int arr[N];
vi lst[N];

int gcd[N];
set<int>st[N];

void dfs(int now, int par){
    if(par != -1){
        gcd[now] = __gcd(gcd[par], arr[now]);
        st[now].insert(gcd[par]);
        for(set<int>::iterator it = st[par].begin(); it != st[par].end(); it++){
            st[now].insert(__gcd(*it, arr[now]));
        }
    }

    FOR(i, lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;
        dfs(to, now);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n;
    REP(i,1,n)cin>>arr[i];
    REP(i,1,n-1){
        int a,b;
        cin>>a>>b;
        lst[a].pb(b);
        lst[b].pb(a);
    }

    st[1].insert(0);
    gcd[1] = arr[1];

    dfs(1, -1);

    REP(i,1,n){
        //printf("%d: %d\n",i,gcd[i]);
        int ans = gcd[i];
        for(set<int>::iterator it = st[i].begin(); it != st[i].end(); it++){
            //printf("%d\n",*it);
            ans = max(ans, *it);
        }
        cout<<ans<<" ";
    }
    cout<<endl;

    return 0;
}