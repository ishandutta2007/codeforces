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

int n, m;
char p[N];
char t[N];
int a[N];
int ord[N];

bool verify(int step){
    int pt = 0;
    rep(i,0,n-1){
        if(pt >= m)break;
        if(ord[i] <= step)continue;
        if(p[i] == t[pt])pt++;
    }
    //printf(">%d %d\n",step,pt);
    if(pt >= m)return true;
    else return false;
}

int main(){
    scanf("%s %s",p,t);
    n = strlen(p);
    m = strlen(t);
    rep(i,0,n-1)scanf("%d",&a[i]);
    rep(i,0,n-1)ord[a[i]-1] = i+1;

    int lo = 0, mid, hi = n;
    int ans = 0;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(verify(mid)){
            lo = mid+1;
            ans = max(ans, mid);
        }else{
            hi = mid-1;
        }
    }

    printf("%d\n",ans);
    return 0;
}