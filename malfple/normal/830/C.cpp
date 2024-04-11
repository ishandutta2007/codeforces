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

const int N = 105;

int n;
ll k;

ll arr[N];
vector<pll>vec[N];

inline ll ceildiv(ll a,ll b){ // a/b
    ll ret = a/b;
    if(a%b != 0)ret++;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n>>k;
    rep(i,1,n)cin>>arr[i];

    ll C = k;
    rep(i,1,n)C += arr[i];

    rep(i,1,n){
        ll divisor = arr[i];
        while(1){
            ll divided = ceildiv(arr[i], divisor);

            vec[i].pb(mp(divided, divisor));

            if(divisor == 1)break;

            divided++;
            if(ceildiv(arr[i], divided) == divisor){
                divisor--;
            }else{
                divisor = ceildiv(arr[i], divided);
            }
        }
    }

    /*rep(i,1,n){
        printf("divisors for %lld\n",arr[i]);
        rep(j,0,(int)vec[i].size()-1){
            printf("%lld:%lld\n",vec[i][j].ff, vec[i][j].ss);
        }
    }*/

    //array of pointers
    int p[N];
    rep(i,1,n)p[i] = 0;

    ll ans = -1;

    ll upperbound = INF;
    while(1){
        ll currsum = 0;
        rep(i,1,n)currsum += vec[i][p[i]].ff;
        ll maxdivisor = 0;
        rep(i,1,n)maxdivisor = max(maxdivisor, vec[i][p[i]].ss);
        ll optimal = C/currsum;
        optimal = min(optimal, upperbound);

        //printf("sum=%lld %lld-%lld optimal=%lld\n",currsum, upperbound, maxdivisor, optimal);

        if(optimal >= maxdivisor){
            ans = optimal;
            break;
        }

        if(maxdivisor == 1)break; // done

        upperbound = maxdivisor-1;

        rep(i,1,n){
            if(vec[i][p[i]].ss == maxdivisor){
                p[i]++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}