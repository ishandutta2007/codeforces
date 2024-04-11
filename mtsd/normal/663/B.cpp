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
    int n;
    cin >> n;
    rep(zz,n){
        string s;
        cin >> s;
        string t;
        rep(i,s.size()){
            if(isdigit(s[i])){
                t.push_back(s[i]);
            }
        }
        int m = t.size();
        int y = 1989;
        int dd = 1;
        int p = 0;
        for(int i=m-1;i>=0;i--){
            if(i==m-1){
                for(int k=1989;k<=1999;k++){
                    if(k%10==t[i]-'0'){
                        y = k;
                        break; 
                    }
                }
                p += t[i]-'0';
                dd *= 10;
            }else{
                p += dd*(t[i]-'0');
                dd *= 10;
                int tmp = y;
                tmp /= dd;
                tmp =  tmp * dd + p;
                if(tmp > y){
                    y = tmp;
                }else{
                    y = tmp + dd;
                }
            }
        }
        cout << y << "\n";
    }
    return 0;
}