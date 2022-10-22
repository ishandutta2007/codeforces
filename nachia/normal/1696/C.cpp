
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
    int lenA; cin >> lenA;
    i64 M; cin >> M;
    vector<i64> A(lenA);
    rep(i,lenA) cin >> A[i];
    int lenB; cin >> lenB;
    vector<i64> B(lenB);
    rep(i,lenB) cin >> B[i];

    auto compress = [M](const vector<i64>& A) -> vector<pair<i64,i64>> {
        vector<pair<i64,i64>> res;
        for(auto a : A){
            i64 smalla = a;
            while(smalla % M == 0) smalla /= M;
            res.push_back(make_pair(smalla, a/smalla));
        }
        vector<pair<i64,i64>> res2;
        for(auto& [u,c] : res){
            if(res2.empty() || res2.back().first != u) res2.push_back(make_pair(u,c));
            else res2.back().second += c;
        }
        return res2;
    };

    vector<pair<i64, i64>> Ac = compress(A);
    vector<pair<i64, i64>> Bc = compress(B);
    bool ans = Ac == Bc;
    cout << (ans ? "Yes\n" : "No\n");
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