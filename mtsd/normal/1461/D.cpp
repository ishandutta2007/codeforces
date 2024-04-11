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
void calc(vector<ll>&a,vector<ll>& s,int L,int R,set<ll>&st){
    if(R-L==0)return;
    st.insert(s[R]-s[L]);
    if(a[R-1]==a[L])return;
    ll k = (a[R-1]+a[L])/2;
    int id = upper_bound(all(a),k)-a.begin();
    calc(a,s,L,id,st);
    calc(a,s,id,R,st);
}
int main(){
     cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n,m;
        cin >> n >> m;
        vector<ll> a(n);
        rep(i,n) cin >> a[i];
        sort(all(a));
        
        vector<ll> s(n+1);
        rep(i,n){
            s[i+1] =  a[i]+ s[i];
        }
        set<ll> st;
        calc(a,s,0,n,st);
        rep(i,m){
            ll k;
            cin >> k;
            if(st.count(k)){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }
    return 0;
}