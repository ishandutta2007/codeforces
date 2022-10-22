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
    vector<i64> A(N);
    rep(i,N) cin >> A[i];
    // sort(A.begin(), A.end());
    int ans = N;
    for(int i=0; i<N; ){
        i64 s = A[i];
        auto p = upper_bound(A.begin(), A.end(), s);
        int s_count = p - lower_bound(A.begin(), A.end(), s);
        int tmp = s_count;
        i += s_count;
        while(p != A.end()){
            i64 pval = *p;
            tmp++;
            p = lower_bound(p, A.end(), pval * 2 - s);
        }
        ans = min(ans, N - tmp);
    }
    cout << ans << "\n";
}


int main(){
    int T; cin >> T;
    rep(caseid, T) testcase();
    return 0;
}




struct ios_do_not_sync {
    ios_do_not_sync() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} ios_do_not_sync_instance;