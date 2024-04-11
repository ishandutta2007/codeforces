#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


bool test_for_k_members(
    int N,
    const vector<int>& A,
    const vector<int>& B,
    int k
){
    int left_than_me = 0;
    int right_than_me = k-1;
    rep(i,N){
        if(left_than_me <= B[i] && right_than_me <= A[i]){
            left_than_me++;
            right_than_me--;
        }
        if(left_than_me == k) return true;
    }
    return false;
}


void testcase(){
    int N; cin >> N;
    vector<int> A(N), B(N);
    rep(i,N) cin >> A[i] >> B[i];
    int ok = 0, ng = N+1;
    while(ng-ok > 1){
        int m = (ok + ng) / 2;
        if(test_for_k_members(N,A,B,m)) ok = m; else ng = m;
    }
    cout << ok << "\n";
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