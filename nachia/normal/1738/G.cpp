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

void testcase(){
    int N, K; cin >> N >> K;
    vector<string> X(N);
    rep(i,N) cin >> X[i];
    vector<int> Q(N*2+10, -1);
    auto Qat = [&](int i) noexcept -> int& { return Q[N+i+4]; };
    for(int j=1; j<=N-K+1; j++) Qat(-j) = Qat(j) = j-1;
    Qat(0) = 0;
    vector<string> Y(N, string(N, '1'));
    rep(i,N*2-1){
        int w = i; if(i >= N-1) w = 2*N-2 - i;
        for(int j=-w; j<=w; j+=2){
            int y = (i-j)/2, x = (i+j)/2;
            if(X[y][x] == '0') continue;
            int k = Qat(j);
            if(k < 0 || k%2 != i%2) continue;
            Y[y][x] = '0';
            Qat(j)++;
            Qat(j-1) = max(Qat(j-1), min(Qat(j-2), Qat(j)));
            Qat(j+1) = max(Qat(j+1), min(Qat(j+2), Qat(j)));
        }
    }
    if(Qat(0) != (N-K)*2+1){ cout << "NO\n"; return; }
    cout << "YES\n";
    for(auto& y : Y) cout << y << '\n';
}

int main(){
    int T; cin >> T;
    rep(t,T) testcase();
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;