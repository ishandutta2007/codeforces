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
vector<vector<int> > g;
int c[1010];
bool ok[1010];
int main(){
    int n;
    cin >> n;
    g.resize(n);
    rep(i,n){
        ok[i] = 1;
    }
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        c[a]++;
        c[b]++;
    }
    int m = n;
    while(m!=1){
        int a = -1;
        int b = -1;
        rep(i,n){
            if(ok[i]&&c[i]==1){
                if(a==-1){
                    a = i;
                }else{
                    b = i;
                    break;
                }
            }
        }
        if(a==-1||b==-1){
            rep(i,n){
                if(ok[i]){
                    cout << "! " << i+1 << endl;
                    return 0;
                }
            }
        }
        cout << "? " << a+1 << " " << b+1 << endl;
        int k;
        cin >> k;
        if(k==a+1||k==b+1){
            cout <<"! "<< k << endl;
            return 0;
        }else{
            ok[a] = 0;
            ok[b] = 0;
            for(auto x:g[a]){
                c[x]--;
            }
            for(auto x:g[b]){
                c[x]--;
            }
        }
    }
    return 0;
}