
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>


using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


const i64 INF = 1001001001001001001;



void testcase(){
    u32 N; cin >> N;
    u32 Z; cin >> Z;
    vector<u32> A(N);
    rep(i,N) cin >> A[i];
    u32 ans = 0;
    rep(i,N) ans = max(ans, A[i] | Z);
    cout << ans << '\n';
}

int main(){
    int T; cin >> T;
    rep(t,T) testcase();
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;