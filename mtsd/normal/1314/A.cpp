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
#include <iomanip>
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
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll>a(n),t(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> t[i];
    }
    ll ans = 0;
    vector<pair<int,int> > v;
    rep(i,n){
        v.PB(MP(a[i],t[i]));   
    }
    sort(v.begin(),v.end());
    priority_queue<pair<int,int> >  pq;
    int s = -1;
    int p = -1;
    ll sm = 0;
    rep(i,n){
        while(!pq.empty()){
            auto x = pq.top();
            if(s>=v[i].first){
                break;
            }else{
                pq.pop();
                sm -= x.first;
                ans += (ll)(sm);
                s++;
            }
        }
        if(!pq.empty()){
            pq.push(MP(v[i].second,v[i].first));
            sm += v[i].second;
        }else{
            pq.push(MP(v[i].second,v[i].first));
            s = v[i].first;
            sm = v[i].second;
        }
        // cerr << s << " " << sm << " " << ans << endl;
    }
    int tt = s - v[n-1].first;
    // cerr << s << " " << v[n-1].first << " " << pq.size() << endl;
    while(!pq.empty()){
        auto x = pq.top();
        
        sm -= x.first;
        pq.pop();
        ans += sm;
    }
    cout << ans << endl;
    return 0;
}