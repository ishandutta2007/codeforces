
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>


using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


const i64 INF = 1001001001001001001;



void testcase(){
    u32 N; cin >> N;
    vector<u32> A(N);
    rep(i,N) cin >> A[i];
    rep(i,N) A[i] = ((A[i] == 0) ? 0 : 1);
    A.erase(unique(A.begin(), A.end()), A.end());
    int c = 0;
    for(auto a : A) if(a != 0) c++;
    if(c == 0) cout << "0\n";
    else if(c == 1) cout << "1\n";
    else cout << "2\n";
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