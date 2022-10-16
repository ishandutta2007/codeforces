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
const ll MOD = (ll)1e9 + 7;

ll fact[N];
ll F(int x){
    if(x < 0)return 0;
    else return fact[x];
}

int n,m;
char in[N];
int pre[N];

ll exp(ll a,ll e){
    if(e < 0)return 1;
    else if(e == 1)return a;
    else{
        ll ret = exp(a,e/2);
        ret = (ret * ret)%MOD;
        if(e & 1)ret = (ret * a)%MOD;
        return ret;
    }
}

ll C(int a,int b){
    if(b > a)return 0;
    return (F(a) * exp((F(a-b) * F(b))%MOD, MOD-2))%MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    fact[0] = 1;
    rep(i,1,N-5){
        fact[i] = (fact[i-1] * i)%MOD;
    }

    scanf("%s",in);
    m = strlen(in);
    n = 0;
    rep(i,0,m-1){
        if(in[i] == '(')n++;
    }
    for(int i=m-1, nn = n,cnt = 0; i>=0; i--){
        if(in[i] == ')'){
            cnt++;
        }else{
            pre[nn--] = cnt;
        }
    }
    ll ans = 0;
    rep(i,1,n){
        ans = (ans + C(i + pre[i] - 1, i))%MOD;
    }
    cout << ans << endl;
    return 0;
}