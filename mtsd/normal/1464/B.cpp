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
ll sr[2][100010];// migi
ll sl[2][100010];// hidari
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll X,Y;
    cin >> X >> Y;
    int n = s.size();
    vector<int> p;
    rep(i,n){
        if(s[i]=='0'){
            sl[0][i]++;
            sr[0][i]++;
        }else if(s[i]=='1'){
            sl[1][i]++;
            sr[1][i]++;
        }else{
            p.push_back(i);
        }
    }
    rep(k,2){
        rep(i,n){
            sl[k][i+1] += sl[k][i];        
        }
        for(int i=n-1;i>=0;i--){
            sr[k][i] += sr[k][i+1];
        }
    }
    ll A = 0;
    rep(i,n){
        if(s[i]=='0'){
            A += Y*sl[1][i];
            A += X*sr[1][i];
        }else if(s[i]=='1'){
            A += X*sl[0][i];
            A += Y*sr[0][i];
        }
    }
    A /= 2;
    cerr << A << endl;
    int K = p.size();
    ll tmp= 0;
    ll mi = 0;
    for(int i=0;i<K;i++){
        int id = p[i];
        tmp += Y*sl[1][id];
        tmp += X*sr[1][id];
    }
    mi = tmp;
    for(int i=0;i<K;i++){
        int id = p[i];
        tmp -= Y*sl[1][id];
        tmp -= X*sr[1][id];
        tmp += X*sl[0][id];
        tmp += Y*sr[0][id];
        
        chmin(mi,tmp + Y * (i+1)*(K-i-1));
    }
    for(int i=0;i<K;i++){
        int id = p[i];
        tmp -= X*sl[0][id];
        tmp -= Y*sr[0][id];
        tmp += Y*sl[1][id];
        tmp += X*sr[1][id];
        chmin(mi,tmp + X * (i+1)*(K-i-1));
    }
    cout << A + mi << endl;
    return 0;
}