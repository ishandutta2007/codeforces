
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
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    int ans = 0;

    rep(t,2){
        int a = A[0];
        int minA = a;
        int maxA = a;
        rep(p,N){
            if(minA < a && maxA < A[p]){
                a = minA;
                ans++;
            }
            else if(maxA > a && minA > A[p]){
                a = maxA;
                ans++;
            }
            if(A[p] == 1){
                if(a != 1) ans++;
                break;
            }
            minA = min(minA, A[p]);
            maxA = max(maxA, A[p]);
        }
        reverse(A.begin(), A.end());
    }

    cout << ans << '\n';
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