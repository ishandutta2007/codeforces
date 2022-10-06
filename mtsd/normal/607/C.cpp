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
void z_algorithm(const string& S, vector<int>& res)
{
    int sz = (int)S.size();
    res.resize(sz, 0);
    int i = 1, j = 0;
    while(i < sz){
        while(i+j < sz && S[j] == S[i+j]) j++;
        res[i] = j;
        if(j == 0){
            i++;
            continue;
        }
        int k = 1;
        while(i+k < sz && k+res[k] < j){
            res[i+k] = res[k], k++;
        }
        i += k; j -= k;
    }
}

int main(){
    map<char,char> inv;
    int n;
    cin >> n;
    n--;
    string a,b;
    cin >> a >> b;
    inv['N'] = 'S';
    inv['S'] = 'N';
    inv['E'] = 'W';
    inv['W'] = 'E';
    reverse(all(b));
    string bb;
    rep(i,n){
        bb.push_back(inv[b[i]]);
    }
    string re;
    re += bb;
    re += "$";
    re += a;
    // cerr << re << endl;
    vector<int> res;
    z_algorithm(re,res);
    bool flag = 0;
    for(int i=n;i<res.size();i++){
        if(res[i]==(int)(res.size()-i))flag = 1;
    }
    if(flag){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }
    return 0;
}