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
#define int long long
signed main(){
    int n,a,b;
    cin >> n >> a >> b;
    int A=-1,B=-1;
    for(int i=0;i<=1000000;i++){
        if(n< a*i)break;
        if((n-a*i)%b==0){
            A = i;
            B = (n-a*i)/b;
        }
    }

    if(A==-1){
        cout << -1 << endl;
        return 0;
    }
    int id = 0;
    vector<int> res(n);
    for(int i=0;i<A;i++){
        for(int j=0;j<a;j++){
            res[id+j] = id+(j+1)%a;
        }
        id += a;
    }
    for(int i=0;i<B;i++){
        for(int j=0;j<b;j++){
            res[id+j] = id+(j+1)%b;
        }
        id += b;
    }
    rep(i,n){
        cout << res[i]+1;
        if(i!=n-1)cout << " ";
    }
    cout << endl;
    return 0;
}