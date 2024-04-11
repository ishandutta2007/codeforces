#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>b(n);
    rep(i,n)cin >> a[i];
    ll sm = 0;
    rep(i,n)sm += a[i];
    int q;
    cin >> q;
    map<pair<ll,ll>,ll > mp;
    rep(zz,q){
        ll s,t,u;
        cin >> s >> t >> u;
        s--;u--;
        if(mp.find(MP(s,t))!=mp.end()){
            int k = mp[MP(s,t)];
            b[k]--;
            if(b[k]<a[k]){
                sm++;
            }
            if(u!=-1){
                mp[MP(s,t)] = u;
                if(b[u]<a[u]){
                    sm--;
                }
                b[u]++;
            }else{
                mp.erase(MP(s,t));
            }
        }else{
            if(u!=-1){
                mp[MP(s,t)] = u;
                if(b[u]<a[u]){
                    sm--;
                }
                b[u]++;
            }
        }
        cout << sm << "\n";
    }
    return 0;
}