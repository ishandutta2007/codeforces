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
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    string t;
    cin >> t;
    int n = s.size();
    vector<int>p(n+1);
    vector<int>Lp(n+1);
    rep(i,n){
        if(s[i]!='A'){
            p[i+1]++;
        }else{
            Lp[i+1] = Lp[i]+1;
        }
        p[i+1] += p[i];
    }
    int m = t.size();
    vector<int>q(m+1);
    vector<int>Lq(m+1);
    rep(i,m){
        if(t[i]!='A'){
            q[i+1]++;
        }else{
            Lq[i+1] = Lq[i] + 1;
        }
        q[i+1] += q[i];
    }
    int qq;
    cin >> qq;
    rep(zz,qq){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int ss = p[b] - p[a-1];
        int sss = q[d] - q[c-1];
        int lp = min(Lp[b],b-a+1);
        int lq = min(Lq[d],d-c+1);
        // cerr << lp << " " << lq << endl;
        if(ss > sss || (ss-sss)%2!=0 || (lp < lq)||(lp  >  lq && ss == sss&&(lp-lq)%3!=0)){
            cout << 0;
        }else{
            if(lp==lq&&lp == b-a+1 && (ss == 0&&(sss!=0))){
                cout << 0;
            }else{
                cout << 1;
            }
        }
    }
    cout << "\n";
    return 0;
}