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
    string s;
    cin >> s;
    int n = s.size();
    int c = 0;
    int k = 0;
    rep(i,n){
        if(s[i]=='('){
            c++;
        }else if(s[i]==')'){
            c--;
        }else{
            k++;
        }
    }
    string t;
    vector<int> res;
    rep(i,n){
        if(s[i]=='#'){
            if(k!=1){
                res.push_back(1);
                t.push_back(')');
                c--;
                k--;
            }else{
                if(c<=0){
                    cout << -1 << endl;
                    return 0;
                }
                res.push_back(c);
                rep(zz,c)t.push_back(')');
            }
        }else{
            t.push_back(s[i]);
        }
    }
    int m = t.size();
    int cc = 0;
    rep(i,m){
        if(t[i]=='('){
            cc++;
        }else{
            cc--;
        }
        if(cc<0){
            cout << -1 << endl;
            return 0;
        }
    }
    for(auto x:res){
        cout << x << "\n";
    }
    return 0;
}