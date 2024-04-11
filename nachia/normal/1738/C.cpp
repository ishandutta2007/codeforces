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

int dptable[128][128][2][2] = {};

int Dp(int alice, int cnt0, int cnt1, int turn){
    if(dptable[cnt0][cnt1][alice][turn] != 0) return dptable[cnt0][cnt1][alice][turn];
    if(cnt0 == 0 && cnt1 == 0) return dptable[cnt0][cnt1][alice][turn] = 1 - alice * 2;
    int ans = 0;
    if(turn == 1){
        ans = -1;
        if(cnt0) ans = max(ans, Dp(alice, cnt0-1, cnt1, turn^1));
        if(cnt1) ans = max(ans, Dp(alice^1, cnt0, cnt1-1, turn^1));
    }
    else{
        ans = 1;
        if(cnt0) ans = min(ans, Dp(alice, cnt0-1, cnt1, turn^1));
        if(cnt1) ans = min(ans, Dp(alice, cnt0, cnt1-1, turn^1));
    }
    return dptable[cnt0][cnt1][alice][turn] = ans;
}

int main(){
    int T; cin >> T;
    rep(t,T){
        int N; cin >> N;
        int C[2] = {};
        rep(i,N){ int a; cin >> a; C[(a%2+2)%2]++; }
        if(Dp(0, C[0], C[1], 1) == 1) cout << "Alice\n"; else cout << "Bob\n";
    }
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;