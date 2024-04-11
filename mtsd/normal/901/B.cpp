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
vector<int> f(vector<int>&a,vector<int>&b){
    int n = a.size();
    vector<int> res(n+1);
    for(int i=0;i<n;i++){
        res[i+1] += a[i];
    }
    for(int i=0;i<n-1;i++){
        res[i] += b[i];
        res[i] %= 2;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int>a(2);
    vector<int>b(1);
    a[1] = 1;
    b[0] = 1;
    for(int i=0;i<n-1;i++){
        b = f(a,b);
        swap(a,b);
    }
    cout << a.size()-1 << "\n";
    rep(i,a.size()){
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << b.size()-1 << "\n";
    rep(i,b.size()){
        cout << b[i] << " ";
    }
    cout << "\n";
    return 0;
}