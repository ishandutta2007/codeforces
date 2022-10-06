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
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<pair<int,int> > p;
    rep(i,n){
        p.PB(MP(a[i],i));
    }
    sort(p.begin(),p.end());
    set<int> st;
    vector<pair<int,int> > res;
    
    rep(i,n){
        int id = p[i].second;
        int k = p[i].first;
        auto x = st.lower_bound(id);
        if(x==st.end()){
            st.insert(id);
        }else{
            auto y = st.end();
            y--;
            while(1){
                res.push_back(MP(id,*y));
                // swap(a[id],a[*y]);
                if(y==x)break;
                y--;
            }
            st.insert(id);
            
            // rep(i,n)cerr << a[i] << " ";
            // cerr << endl;
        }
    }
    // rep(i,n)cerr << a[i] << " ";
    // cerr << endl;
    cout << res.size() << "\n";
    for(auto x:res){
        cout << x.first+1 << " " << x.second+1 << "\n";
    }
    cout << "\n";
    return 0;
}