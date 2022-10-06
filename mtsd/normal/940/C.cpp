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
bool p[27];
int main(){
    int n,m;
    string s;
    cin >> n >> m >> s;
    rep(i,n){
        p[s[i]-'a'] = 1;
    }
    if(n<m){
        char c;
        rep(i,26){
            if(p[i]){
                c = 'a'+i;
                break;
            }
        }
        cout << s;
        rep(i,m-n)cout << c;
        cout << endl;
    }else{
        char c;
        rep(i,26){
            if(p[i]){
                c = 'a'+i;
                break;
            }
        }
        char cc;
        rep(i,26){
            if(p[i]){
                cc = 'a'+i;
            }
        }
        int id;
        for(int i=m-1;i>=0;i--){
            if(s[i]!=cc){
                id = i;
                break; 
            }
        }
        char nxt;
        rep(i,26){
            if(p[i]&&(s[id]-'a')<i){
                nxt = 'a'+i;
                break;
            }
        }
        string res;
        for(int i=0;i<id;i++){
            res.push_back(s[i]);
        }
        res.push_back(nxt);
        for(int i=id+1;i<m;i++){
            res.push_back(c);
        }
        cout << res << endl;
    }
    return 0;
}