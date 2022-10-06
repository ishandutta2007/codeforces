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
template<typename T>
T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a,T b)
{
    return  a / gcd(a,b) * b;
}
int c[15000001];
int b[15000001];
bool flag[15000001];
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int k = 0;
    rep(i,n) k = gcd(k,a[i]);     
    rep(i,n) a[i]/=k;
    rep(i,n){
        c[a[i]]++;
    }
    int mx = 0;
    for(int i=2;i<=15000000;i++){
        if(flag[i])continue;
        for(int j=i;j<=15000000;j+=i){
            b[i] += c[j];
            flag[j] = 1;
        }
        chmax(mx,b[i]);
    }
    if(mx==0){
        cout << -1 << endl;
    }else{
        cout << n-mx << endl;
    }
    return 0;
}