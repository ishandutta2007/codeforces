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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    string s;
    cin >> s;
    int r = 1000000000;
    int l = -1000000000;
    for(int i=4;i<n;i++){
        if(s[i-1]=='0'&&s[i]=='0'){
        }else if(s[i-1]=='1'&&s[i]=='0'){
            chmin(r,min({a[i-4],a[i-3],a[i-2],a[i-1],a[i]})-1);
        }else if(s[i-1]=='0'&&s[i]=='1'){
            chmax(l,max({a[i-4],a[i-3],a[i-2],a[i-1],a[i]})+1);
        }else{

        }
    }
    cout << l << " " << r << endl;
    return 0;
}