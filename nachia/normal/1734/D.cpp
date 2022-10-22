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


void testcase(){
    int N; cin >> N;
    int K; cin >> K; K--;
    vector<i64> A(K); rep(i,K) cin >> A[i];
    i64 F; cin >> F;
    vector<i64> B(N-1-K); rep(i,N-1-K) cin >> B[i];
    reverse(B.begin(), B.end());
    rep(i,N){
        while(A.size() > 1 && A.back() < 0 && A.back() + F >= 0){
            i64 c = A.back();
            A.pop_back();
            A.back() += c;
        }
        while(B.size() > 1 && B.back() < 0 && B.back() + F >= 0){
            i64 c = B.back();
            B.pop_back();
            B.back() += c;
        }
        if(!A.empty() && A.back() >= 0){ F += A.back(); A.pop_back(); }
        if(!B.empty() && B.back() >= 0){ F += B.back(); B.pop_back(); }
    }
    if(A.empty() || B.empty() || A.back() >= -F || B.back() >= -F) cout << "YES\n"; else cout << "NO\n";
    flush(cout);
}

int main(){
    int T; cin >> T;
    rep(caseid, T) testcase();
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;