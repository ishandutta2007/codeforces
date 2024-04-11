#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

const i64 INF = 1001001001001001001;

i64 testcase(){
    int N, K; cin >> N >> K;
    vector<i64> S(K); rep(i,K) cin >> S[i];
    if(K == 1) return 1;
    vector<i64> A(K-1); rep(i,K-1) A[i] = S[i+1] - S[i];
    rep(i,K-2) if(A[i] > A[i+1]) return 0;
    i64 s = S[0], a = A[0], n = N-K+1;
    if(s > a*n) return 0;
    return 1;
}

int main(){
    int T; cin >> T;
    rep(t,T) cout << (testcase() ? "Yes" : "No") << '\n';
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;