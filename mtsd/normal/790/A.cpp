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
string p[60];
int main(){
    int n,k;
    cin >> n >> k;
    vector<string> res(n);
    rep(i,52){
        int k = i/26;
        p[i].push_back('A'+k);
        p[i].push_back('a'+(i%26));
    }
    rep(i,k-1){
        res[i] = p[i];
    }
    rep(i,n-k+1){
        string s;
        cin >> s;
        if(s=="YES"){
            res[i+k-1] = p[i+k-1];
        }else{
            res[i+k-1] = res[i];
        }
    }
    rep(i,n){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}