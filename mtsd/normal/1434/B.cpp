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
    vector<pair<int,int> >a;
    rep(i,2*n){
        char c;
        cin >> c;
        if(c=='+'){
            a.push_back(MP(0,0));
        }else{
            int k;
            cin >> k;
            a.push_back(MP(1,k));
        }
    }
    vector<int> p(n);
    int id = n-1;
    bool ng = 0;
    set<int> st;
    for(int i=2*n-1;i>=0;i--){
        if(a[i].first==0){
            if(st.size()==0){
                ng = 1;
                break;
            }else{
                p[id] = *(st.begin());
                st.erase(p[id]);
                id--;
            }
        }else{
            st.insert(a[i].second);
        }
    }
    if(ng){
        cout << "NO\n";
        return 0;
    }
    id = 0;
    rep(i,2*n){
        if(a[i].first==0){
            st.insert(p[id]);
            id++;
        }else{
            if(st.size()==0){
                ng = 1;
                break;
            }else{
                if(a[i].second!=*st.begin()){
                    ng = 1;
                    break;
                }else{
                    st.erase(st.begin());
                }
            }
        }
    }
    if(ng){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        rep(i,n){
            cout << p[i];
            if(i!=n-1)cout << " ";
        }
        cout << "\n";
    }
    return 0;
}