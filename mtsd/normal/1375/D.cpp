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
void change(int id,vector<int>&a){
    int n = a.size();
    vector<bool> flag(n);
    rep(i,n){
        if(a[i]>=n){
            continue;
        }else{
            flag[a[i]]= 1;
        }
    }        
    rep(i,n){
        if(!flag[i]){
            a[id] = i;
            return;
        }
    }
    a[id] = n;
}
bool check(vector<int>&a){
    int n = a.size();
    rep(i,n-1){
        if(a[i]>a[i+1])return false;
    }
    return true;
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
        vector<int> res;
        while(1){
            vector<bool> flag(n);
            bool fff = 0;
            rep(i,n){
                if(a[i]>=n){
                    res.push_back(i);
                    change(i,a);
                    fff = 1;
                    break;
                }else{
                    if(flag[a[i]]){
                        res.push_back(i);
                        change(i,a);
                        fff = 1;
                        break;
                    }else{
                        flag[a[i]] = 1;
                    }
                }
            }
            if(!fff)break;
        }
        int k = -1;
        rep(i,n){
            if(a[i]!=i){
                k = i;
                break;
            }
        }
        while(!check(a)){
            // rep(i,n)cerr << a[i] << " ";
            // cerr << endl;
            res.push_back(k);
            int p = a[k];
            if(p==n||a[p]==p){
                rep(i,n){
                    if(i!=k&&a[i]!=i&&a[i]!=n){
                        p = i;
                        break;
                    }
                }
            }
            change(k,a);
            k = p;
                
        }
        // rep(i,n)cerr << a[i] << " ";
        //     cerr << endl;
        cout << res.size() << "\n";
        for(auto x:res){
            cout << x+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}