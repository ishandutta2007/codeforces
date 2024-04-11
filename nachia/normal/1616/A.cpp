
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


void testcase(){
    int N; cin >> N;
    vector<int> C(101, 0);
    rep(i,N){
        int a; cin >> a;
        C[abs(a)]++;
    }
    int ans = 0;
    ans += min(1,C[0]);
    for(int i=1; i<=100; i++) ans += min(2,C[i]);
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