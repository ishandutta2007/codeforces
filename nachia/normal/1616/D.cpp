
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
    vector<i64> A(N);
    rep(i,N) cin >> A[i];
    i64 x; cin >> x;

    i64 sum_seg = 0;
    i64 len_seg = 0;
    i64 ans = 0;
    for(auto a : A){
        i64 sum_seg_tmp = sum_seg + a;
        i64 len_seg_tmp = len_seg + 1;
        if(1 < len_seg_tmp && len_seg_tmp * x > sum_seg_tmp){
            sum_seg = 0;
            len_seg = 0;
        }
        else{
            ans++;
            if(len_seg * x <= sum_seg){
                sum_seg = a;
                len_seg = 1;
            }
            else{
                sum_seg = sum_seg_tmp;
                len_seg = len_seg_tmp;
            }
        }
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