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
    int n,m;
    cin >> n >> m;
    vector<ll> d(n);
    rep(i,m){
        int a,b;
        ll dd;
        cin >> a >> b >> dd;
        a--;b--;
        d[a] += dd;
        d[b] -= dd;
    }
    vector<pair<int,ll> > p;
    vector<pair<int,ll> > q;
    rep(i,n){
        if(d[i]>0){
            p.push_back(MP(i,d[i]));
        }else if(d[i]<0){
            q.push_back(MP(i,-d[i]));
        }
    }
    int id = 0;
    vector<pair<pair<int,int>,ll> > res;
    rep(i,p.size()){
        ll cost = p[i].second;
        int a = p[i].first;
        while(cost>0){
            int b = q[id].first;
            if(q[id].second > cost){
                res.push_back(MP(MP(a+1,b+1),cost));
                q[id].second -= cost;
                break;
            }else{
                res.push_back(MP(MP(a+1,b+1),q[id].second));
                cost -= q[id].second;
                id++;
            }
        }
    }
    cout << res.size() << "\n";
    for(auto x:res){
        cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
    }
    return 0;
}