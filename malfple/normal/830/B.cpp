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

int n;
int arr[N];

pii tree[3*N];

void update(int idx,int left,int right,int x,int v){
    if(left==right)tree[idx] = mp(v, x);
    else{
        int mid = (left+right)/2;
        if(x <= mid)update(2*idx, left, mid, x, v);
        else update(2*idx+1, mid+1, right, x, v);

        tree[idx] = min(tree[2*idx], tree[2*idx+1]);
    }
}

pii query(int idx,int left,int right,int l,int r){
    if(left > r || right < l)return mp(OO, -1);
    if(left >= l && right <= r)return tree[idx];
    int mid = (left+right)/2;
    return min(query(2*idx, left, mid, l, r), query(2*idx+1, mid+1, right,l,r));
}

int bitt[N];

void u_bit(int x,int v){
    repp(i,x,n,i&-i)bitt[i] += v;
}

int q_bit(int x){
    int ret = 0;
    revv(i,x,1,i&-i)ret += bitt[i];
    return ret;
}

int qr_bit(int l,int r){
    return q_bit(r) - q_bit(l-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n;
    rep(i,1,n)cin>>arr[i];

    rep(i,1,n){
        u_bit(i,1);
        update(1,1,n,i,arr[i]);
    }

    int currpos = 1;
    ll ans = 0;
    rep(i,1,n){
        pii mn = query(1,1,n,1,n);
        pii get = query(1,1,n,currpos,n);
        if(get.ff != mn.ff)get = mn;
        //printf("%d %d\n",get.ff,get.ss);
        update(1,1,n,get.ss,OO);

        int step;
        if(get.ss < currpos){
            step = qr_bit(currpos, n);
            step += qr_bit(1,get.ss);
        }else{
            step = qr_bit(currpos, get.ss);
        }
        currpos = get.ss;
        u_bit(currpos, -1);

        //printf("%d\n",step);
        ans += step;
    }
    cout << ans << endl;
    return 0;
}