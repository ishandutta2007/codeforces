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
        string a,b;
        cin >> a >> b;
        bool ng = 0;
        set<pair<int,int> > st;
        rep(i,n){
            if(a[i]>b[i]){
                ng = 1;
            }else if(a[i]<b[i]){
                st.insert(MP(a[i]-'a',b[i]-'a'));
            }
        }
        if(ng){
            cout << -1 << "\n";
            continue;
        }
        vector<pair<int,int> > c;
        for(auto x:st){
            c.push_back(x);
        }
        int m = c.size();
        int res = 0;
        while(1){            
            bool flag = 1;
            rep(i,m){
                if(c[i].first!=c[i].second)flag = 0;
            }
            if(flag)break;
            res++;
            rep(i,m){
                if(c[i].first==c[i].second)continue;
                int a = c[i].first;
                int b = c[i].second;
                rep(j,m){
                    if(c[j].first==c[j].second)continue;
                    if(c[j].first==a){
                        c[j].first = b; 
                    }    
                }
                break;
            }
            sort(c.begin(),c.end());
        }
        cout << res << "\n";
    }
    return 0;
}