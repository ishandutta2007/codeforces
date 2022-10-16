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

const int N = 3e5 + 5;

int n,m;
int d[N];
vii lst[N];
bool vis[N];

vi ans;

int dfs(int now){
	if(vis[now])return 0;
	vis[now] = true;
	
	int mask = 0;
	if(d[now] == 1)mask = 1;
	
	FOR(i, lst[now].size()){
		int to = lst[now][i].ff;
		int e = lst[now][i].ss;
		
		int curr = dfs(to);
		if(curr == 1)ans.pb(e);
		mask ^= curr;
	}
	
	return mask;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n>>m;
    REP(i,1,n)cin>>d[i];
    REP(i,1,m){
        int a,b;
        cin>>a>>b;
        lst[a].pb(mp(b,i));
        lst[b].pb(mp(a,i));
    }

	int cnt = 0;
	int dummy = -1;
	REP(i,1,n){
		if(d[i] == 1)cnt++;
		else if(d[i] == -1)dummy = i;
	}
	
	if(cnt&1){
		if(dummy == -1){
			cout << -1 << endl;
			return 0;
		}
		d[dummy] = 1;
	}
	
	dfs(1);
	
	cout << ans.size() << endl;
	FOR(i,ans.size())cout << ans[i] << endl;

    return 0;
}