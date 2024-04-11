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

const int N = 60005;

int n;
double x[N];
double v[N];

double gettime(double xnow){
    double ret = 0;
    rep(i,1,n)ret = max(ret, max(xnow-x[i], x[i]-xnow) / v[i]);
    return ret;
}

int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%lf",&x[i]);
    rep(i,1,n)scanf("%lf",&v[i]);

    double lo = 1, ml, mr, hi = 1000000000;
    while(max(hi-lo, lo-hi) > 1e-6){
        ml = (2*lo + hi)/3;
        mr = (lo + 2*hi)/3;
        double tl = gettime(ml);
        double tr = gettime(mr);
        //printf("%lf %lf %lf %lf | %lf %lf\n",lo,ml,mr,hi,tl,tr);
        if(tl < tr){
            hi = mr;
        }else{
            lo = ml;
        }
    }
    printf("%lf\n",gettime(lo));

    return 0;
}