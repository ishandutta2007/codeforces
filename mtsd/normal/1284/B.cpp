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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define int long long
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>mi,mx;
    int res = 0;
    int K = 0;
    rep(i,n){
        int k;
        cin >> k;
        int sm = 0; 
        int sss = inf;
        int ttt = 0;
        int pre = inf;
        bool flag = 0;
        rep(z,k){
            int t;
            cin >> t;
            if(pre < t){
                flag = 1;
            }
            sss = min(sss,t);
            ttt = max(ttt,t);
            pre = t;
        }
        if(flag){
            K++;
        }else{
            mi.push_back(sss);
            mx.push_back(ttt);
        }
    }
    res += 2*K*n- K*K;
    // cerr << res << endl;
    // cerr << K << endl;
    if(mx.size()>0){
        sort(mx.begin(),mx.end());
        rep(i,mx.size()){
            res += mx.end()-upper_bound(mx.begin(),mx.end(),mi[i]);
        }
    }
    cout << res << endl;
    return 0;
}