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
#define FORD(i,a) for(int i=a-1; i>=0; i--)

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

const int N = 35005;
const int H = 15;
const int K = 55;

int n,k;
int arr[N];
int last[N];
int leftsame[N];

int segtree[3][2*N];
int segpend[3][N];

void apply(int* tree, int* pend, int x, int v){
	tree[x] += v;
	if(x < n)pend[x] += v;
}

void calc(int* tree, int* pend, int x){
	tree[x] = max(tree[x<<1], tree[x<<1|1]) + pend[x];
}

void upgate(int* tree, int* pend, int x){
	while(x>1){
		x>>=1;
		calc(tree, pend, x);
	}
}

void downgate(int* tree, int* pend, int x){
	for(int h=H; h>0; h--){
		int i = x>>h;
		if(pend[i]){
			apply(tree, pend, i<<1, pend[i]);
			apply(tree, pend, i<<1|1, pend[i]);
			pend[i] = 0;
		}
	}
}

void update(int* tree, int* pend, int l,int r,int v){
	l += n-1, r += n;
	int lt = l, rt = r;
	
	for(; l<r; l>>=1, r>>=1){
		if(l&1)apply(tree, pend, l++, v);
		if(r&1)apply(tree, pend, --r, v);
	}
	upgate(tree, pend, lt);
	upgate(tree, pend, rt-1);
}

int query(int* tree,int* pend, int l,int r){
	l += n-1, r += n;
	downgate(tree, pend, l);
	downgate(tree, pend, r-1);
	
	int ret = 0;
	for(; l<r; l>>=1, r>>=1){
		if(l&1)ret = max(ret, tree[l++]);
		if(r&1)ret = max(ret, tree[--r]);
	}
	return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n>>k;
    REP(i,1,n)cin>>arr[i];
    REP(i,1,n){
        leftsame[i] = last[arr[i]];
        last[arr[i]] = i;
    }
    //REP(i,1,n)cout<<leftsame[i]<<" ";cout<<endl;

    int prev = 0, next = 1;
    int ans = 0;
    REP(i,1,k){
        memset(segtree[next], 0, sizeof segtree[next]);
        memset(segpend[next], 0, sizeof segpend[next]);

        REP(j,1,n){
            int leftlimit = leftsame[j]+1;
            update(segtree[prev], segpend[prev], leftlimit, j, 1);

            int ultramax = query(segtree[prev], segpend[prev], 1,j);
            if(j<n)update(segtree[next], segpend[next], j+1,j+1,ultramax);

            if(i == k && j == n)ans = ultramax;

            /*REP(l,1,n){
                cout<<query(segtree[prev], segpend[prev], 1,1,n,l,l)<<" ";
            }cout<<endl;
            REP(l,1,n){
                cout<<query(segtree[next], segpend[next], 1,1,n,l,l)<<" ";
            }cout<<endl;*/
        }

        prev ^= 1;
        next ^= 1;
    }

    cout << ans << endl;

    return 0;
}