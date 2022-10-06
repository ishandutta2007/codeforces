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
    rep(i,n) cin >> a[i];
    vector<pair<int,int> > res;
    set<int> st[2];
    int p = 0;
    rep(i,n){
        if(a[i]==2){
            if((int)st[1].size()!=0){
                auto x = *st[1].begin();
                res.push_back(MP(x,i));
                st[1].erase(x);
                res.push_back(MP(p,i));
                st[0].insert(p);
                p++;
            }else{
                res.push_back(MP(p,i));
                st[0].insert(p);
                p++;
            }
        }else if(a[i]==3){
            if((int)st[1].size()!=0){
                auto x = *st[1].begin();
                res.push_back(MP(x,i));
                st[1].erase(x);
                res.push_back(MP(p,i));
                st[1].insert(p);
                p++;
            }else{
                res.push_back(MP(p,i));
                st[1].insert(p);
                p++;
            }
        }else if(a[i]==1){
            if((int)st[0].size()!=0){
                auto x = *st[0].begin();
                res.push_back(MP(x,i));
                st[0].erase(x);
            }else if((int)st[1].size()!=0){
                auto x = *st[1].begin();
                res.push_back(MP(x,i));
                st[1].erase(x);
                res.push_back(MP(p,i));
                p++;
            }else{
                res.push_back(MP(p,i));
                p++;
            }
        }
    }
    if(p>=n+1||(int)st[0].size()!=0||(int)st[1].size()!=0){
        cout << -1 << endl;
        return 0;
    }
    cout << res.size() << "\n";
    for(auto x:res){
        cout << x.first+1 << " " << x.second+1 << "\n";
    }
    return 0;
}