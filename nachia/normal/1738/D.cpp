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
    int N; cin >> N;
    vector<int> A(N); rep(i,N){ cin >> A[i]; }
    vector<vector<int>> InvA(N+2);
    rep(i,N) InvA[A[i]].push_back(i+1);

    int k = 0;
    rep(i,N) if(A[i] > i+1) k = i+1;

    cout << k << '\n';

    vector<int> B;
    int s = 0; if(InvA[0].empty()) s = N+1;
    while(true){
        vector<int> nx = move(InvA[s]);
        if(nx.empty()) break;
        for(int& c : nx) if(InvA[c].size()) swap(c, nx.back());
        for(int c : nx) B.push_back(c);
        s = nx.back();
    }

    rep(i,N){
        if(i) cout << ' ';
        cout << B[i];
    }
    cout << '\n';
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