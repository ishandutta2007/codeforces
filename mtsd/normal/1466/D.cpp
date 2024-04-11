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
    int t;
    cin >> t;
    rep(zz,t){
        int n;
        cin >> n;
        vector<ll> a(n);
        rep(i,n)cin >> a[i];
        vector<int> c(n);
        rep(i,n-1){
            int p,q;
            cin >> p >> q;
            p--;q--;
            c[p]++;
            c[q]++;
        }
        vector<pair<ll,int> > res;
        rep(i,n){
            res.push_back(MP(a[i],c[i]));
        }
        sort(res.rbegin(),res.rend());
        vector<ll> ans(n+2);
        ans[0] = accumulate(all(a),0LL);
        int id = 0;
        for(int i=1;i<=n-2;i++){
            while(id!=n&&res[id].second==1){
                id++;
            }
            ans[i] = ans[i-1];
            if(id!=n){
                ans[i] += res[id].first;
                res[id].second--;
            }
        }
        rep(i,n-1){
            cout << ans[i];
            if(i!=n-2)cout << " ";
        }
        cout << "\n";
    }
    return 0;
}