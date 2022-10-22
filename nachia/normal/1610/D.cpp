#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


const u64 MOD = 1'000'000'007;

u64 powm(u64 a, u64 i, u64 m){
    if(i == 0) return 1;
    u64 r = powm(a*a%m, i/2, m);
    if(i&1) r = r*a%m;
    return r;
}


void testcase(){
    int N; cin >> N;
    vector<u32> A(N);
    rep(i,N) cin >> A[i];
    vector<int> Ax(32,0);
    for(auto a : A) Ax[__builtin_ctz(a)]++;
    vector<int> SAx = Ax;
    for(int i=SAx.size()-1; i>=1; i--) SAx[i-1] += SAx[i];
    //for(int a : Ax) cout << a << " "; cout << endl;
    //for(int a : SAx) cout << a << " "; cout << endl;
    u64 ans = powm(2,N,MOD) - 1;
    for(int i=Ax.size()-2; i>=1; i--){
        if(Ax[i] <= 0) continue;
        auto tmp = powm(2, Ax[i]-1, MOD) * powm(2, SAx[i+1], MOD) % MOD;
        ans = (ans + MOD - tmp) % MOD;
    }
    cout << ans << "\n";
}


int main(){
    //int T; cin >> T;
    //rep(caseid, T) testcase();
    testcase();
    return 0;
}




struct ios_do_not_sync {
    ios_do_not_sync() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} ios_do_not_sync_instance;