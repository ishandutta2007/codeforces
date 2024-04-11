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

int a[6];
int b[6];

int main(){
    int n;
    cin>>n;
    int x;
    rep(i,1,n){
        cin>>x;
        a[x]++;
    }
    rep(i,1,n){
        cin>>x;
        b[x]++;
    }

    int exch = 0;
    bool possible = true;
    rep(i,1,5){
        if((a[i] + b[i])%2 != 0)possible = false;
        if(!possible)break;
        exch += (max(a[i], b[i]) - min(a[i], b[i]))/2;
    }
    if(!possible)printf("-1\n");
    else printf("%d\n",exch/2);
    return 0;
}