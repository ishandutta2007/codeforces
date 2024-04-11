#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <map> 
#include <time.h> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <assert.h> 
#include <math.h> 
#include <complex>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
#define pb push_back 
#define mp make_pair 
#define x first 
#define y second 
#define all(v) (v).begin(),(v).end() 

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;

const int INF = 2e9;
const int mod = 1e9 + 7;
const ll LONGINF = 4e18;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;

vector<pair<int, int> > ev;

multimap<int, int> r;

int st[200200], R[200200];



void solve(){
    int n, m, d, f, t;
    scanf("%d%d", &n, &m);
    For(i, n){
        scanf("%d", &d);
        ev.pb(mp(d, 0));
    }
    For(i, m){
        scanf("%d%d", &f, &t);
        ev.pb(mp(f - t, -(i + 1)));
        ev.pb(mp(f + t, i + 1));
        R[i + 1] = f + t;
    }
    For(i, 200200) st[i] = 0;
    sort(all(ev));
    int ans = 0;
    For(i, ev.size()){
        if (ev[i].y < 0){
            r.insert(mp(R[-ev[i].y], -ev[i].y));
        }
        if (ev[i].y == 0){
            if (r.size() > 0){
                auto it = r.begin();
                st[it->y] = 1;
                ++ans;
                r.erase(it);
            }
        }
        if (ev[i].y > 0){
            if (st[ev[i].y] == 0){
                r.erase(ev[i].x);
            }
        }
    }
    printf("%d", ans);
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}