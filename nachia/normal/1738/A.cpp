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
    int N; cin >> N;
    vector<int> T(N), C(N);
    rep(i,N) cin >> T[i];
    rep(i,N) cin >> C[i];
    vector<i64> A[2];
    rep(i,N) A[T[i]].push_back(C[i]);
    rep(t,2) sort(A[t].rbegin(), A[t].rend());
    if(A[0].size() > A[1].size()) swap(A[0], A[1]);

    if(A[0].size() == A[1].size()){
        i64 ans = 0;
        rep(t,2) for(i64 a : A[t]) ans += a * 2;
        ans -= min(A[0].back(), A[1].back());
        return ans;
    }

    i64 ans = 0;
    rep(t,2) for(i64 a : A[t]) ans += a;
    rep(t,2) rep(i,A[0].size()) ans += A[t][i];
    return ans;
}

int main(){
    int T; cin >> T;
    rep(t,T) cout << testcase() << '\n';
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;