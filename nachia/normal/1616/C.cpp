
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


u64 GCD(u64 a, u64 b){ return b ? GCD(b,a%b) : a; }


void testcase(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    int ans = N;

    if(N == 1){ cout << "0\n"; return; }

    rep(sr,N) rep(sl,sr){
        int dA = A[sr] - A[sl];
        int d = sr - sl;
        int check_dx = 1;
        if(dA != 0) check_dx = d / GCD(abs(dA), abs(d));
        int check_s = sl % check_dx;
        int check_dA = dA * check_dx / d;
        int check_sA = A[sl];
        if(dA != 0) check_sA = check_sA - check_dA * (sl - check_s) / check_dx;

        int check_A = check_sA;
        int pans = N;
        for(int i=check_s; i<N; i+=check_dx){
            if(A[i] == check_A) pans--;
            check_A += check_dA;
        }
        ans = min(ans, pans);
    }
    cout << ans << "\n";
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