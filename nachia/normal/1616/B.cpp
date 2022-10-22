
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
    string S; cin >> S;
    string rS = S;
    reverse(rS.begin(), rS.end());
    if(N == 1){ cout << S << rS << "\n"; return; }
    if(S[0] <= S[1]){ cout << S.substr(0,1) << rS.substr(N-1) << "\n"; return; }
    for(int i=1; i<=N; i++){
        if(N == i){ cout << S << rS << "\n"; return; }
        if(S[i] <= S[i-1]) continue;
        cout << S.substr(0,i) << rS.substr(N-i) << "\n";
        return;
    }
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