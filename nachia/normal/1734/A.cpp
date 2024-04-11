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


int main(){
    int T; cin >> T;
    rep(i,T){
        int N; cin >> N;
        i64 ans = 1001001001001001001;
        vector<i64> A(N); rep(i,N) cin >> A[i];
        rep(a,N) rep(b,N) rep(c,N) if(a != b && b != c && a != c){
            i64 B[3] = {A[a],A[b],A[c]};
            sort(B, B+3);
            i64 ansp = 0;
            rep(d,3) ansp += abs(B[d]-B[1]);
            ans = min(ans, ansp);
        }
        cout << ans << '\n';
    }
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;