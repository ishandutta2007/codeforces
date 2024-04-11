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
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        rep(i,n)a[i]--;
        vector<int> c(n);
        rep(i,n)c[a[i]]++;
        bool ng = 0;
        rep(i,n){
            if(c[i] > (n+1)/2){
                ng = 1;
            }
        }
        if(ng){
            cout << -1 << "\n";
            continue;
        }
        int s = 0;
        int t = 0;
        vector<pair<int,int> > p;
        vector<int> sss(n);
        int res = 0;
        while(t<n-1){
            if(a[t]!=a[t+1]){
                t++;
                res++;
            }else{
                p.push_back(MP(a[s],a[t]));
                sss[a[s]]++;
                sss[a[t]]++;
                t++;
                s = t;
                
            }
        }
        sss[a[s]]++;
        sss[a[t]]++;
        sort(sss.rbegin(),sss.rend());
        int sm = accumulate(all(sss),0);
        int T = sss[0];
        // cerr << T << " " << sm << endl;
        if(T<=(sm-T+2)){
            cout << n-1 - res << "\n";
        }else{
            cout << n-1 - (res - (T - (sm-T+2))/2) << "\n";
        }
    }
    return 0;
}