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
        vector<int> res(n);
        rep(i,n) cin >> a[i];
        rep(i,n)a[i]--;
        vector<vector<int> > p(n);
        rep(i,n)p[a[i]].push_back(i);
        set<int> st;
        st.insert(-1);
        st.insert(n);
        for(int i=0;i<n;i++){
            for(auto x:p[i]){
                auto ss = st.lower_bound(x);
                int nxt = (*ss);
                ss--;
                int pre = (*ss);
                res[x] = nxt-pre - 2;
                st.insert(x);
            }
        }
        vector<vector<int> > s(n);
        rep(i,n){
            s[res[i]].push_back(a[i]);
        }
        vector<bool> flag(n+1);
        int id = 0;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            for(auto x:s[i]){
                flag[x] = 1;
            }
            while(flag[id])id++;
            if(n-i==id){
                ans[i] = 1;
            }
        }
        rep(i,n)cout << ans[i];
        cout << "\n";
    }
    return 0;
}