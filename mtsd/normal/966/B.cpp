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
    ll a[2];
    cin >> n >> a[0] >> a[1];
    vector<pair<ll,int> > c;
    rep(i,n){
        ll C;
        cin >> C;
        c.PB(MP(C,i));
    }
    sort(all(c));
    rep(zz,2){
        ll X = a[zz];
        ll Y = a[1-zz];
        int R = -1;
        for(int i=n-1;i>=0;i--){
            if((X+n-i-1)/(n-i) <= c[i].first){
                R = i;
                break;
            }
        }
        if(R==-1)continue;
        for(int i=1;i<n;i++){
            int id = lower_bound(all(c),MP((Y+i-1)/i,-1)) - c.begin();
            int cnt = (R-id);
            if(cnt>=i){
                cout << "Yes\n";
                vector<int>P,Q;
                for(int j=R;j<n;j++){
                    P.push_back(c[j].second+1);
                }
                for(int j=id;j<R;j++){
                    Q.push_back(c[j].second+1);
                }
                if(zz==1)swap(P,Q);
                cout << P.size() << " " << Q.size() << "\n";
                for(auto x:P){
                    cout << x << " ";
                }
                cout << "\n";
                for(auto x:Q){
                    cout << x << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    } 
    cout << "No\n";
    return 0;
}