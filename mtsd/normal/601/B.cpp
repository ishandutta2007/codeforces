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
int a[100001];
ll d[100001];
int L[100001];
int R[100001];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n-1){
        d[i] = abs(a[i+1]-a[i]);
    }
    priority_queue<pair<int,int> > pq;
    rep(i,n-1){
        pq.push(MP(d[i],-i));
    }
    set<int> st;
    st.insert(-1);
    st.insert(n-1);
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int V = x.first;
        int id = -x.second;
        auto z = st.lower_bound(id);
        R[id] = (*z)-1;
        z--;
        L[id] = (*z)+1;
        st.insert(id);
    }
    // rep(i,n-1){
    //     cerr << d[i] << " ";
    // }
    // cerr << endl;
    // rep(i,n-1){
    //     cerr << L[i] << " " << R[i] << endl;
    // }
    rep(zz,q){
        int l,r;
        cin >> l >> r;
        l--;r--;
        r--;
        ll res = 0;
        for(int i=l;i<=r;i++){
            int LL = max(L[i],l);
            int RR = min(R[i],r);
            // cerr << i <<  " " << LL << " " <<RR << endl;
            res += d[i] * (i - LL + 1)*(RR - i + 1);
            // cerr << res << endl;
        }
        cout << res << "\n";
    }
    return 0;
}