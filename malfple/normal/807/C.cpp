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

int t;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        ll x,y,p,q;
        cin>>x>>y>>p>>q;

        if(p == 0){
            if(x == 0)cout << 0 << endl;
            else cout << -1 << endl;
        }else if(p == q){
            if(x == y)cout << 0 << endl;
            else cout << -1 << endl;
        }else{
            if(x*q >= y*p){
                ll mula = x/p;
                if(x%p)mula++;
                ll mulb = y/q;
                if(y%q)mulb++;
                ll mul = max(mula, mulb);

                cout << q*mul - y << endl;
            }else{
                ll lo = 1, mid, hi = 1000000000;
                ll ans = hi;
                while(lo <= hi){
                    mid = (lo+hi)/2;

                    bool fail = false;
                    if(p*mid < x)fail = true;
                    else if(q*mid < y)fail = true;
                    else if(q*mid-y < p*mid-x)fail = true;

                    if(fail)lo = mid+1;
                    else{
                        ans = min(ans, mid);
                        hi = mid-1;
                    }
                }
                cout << q*ans - y << endl;
            }
        }
    }
    return 0;
}