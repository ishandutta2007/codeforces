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


int main(){
    int N; cin >> N;
    rep(i,N){
        int c; cin >> c;
        int d = c + N - (i*i%N);
        rep(j,N){
            if(j) cout << ' ';
            cout << ((i*j+d)%N);
        }
        cout << '\n';
    }
    return 0;
}


struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;