
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i32 = int;
using u32 = unsigned int;
#define rep(i,n) for(int i=0; i<(n); i++)


void testcase(){
    int N; cin >> N;
    vector<vector<int>> A(N+1);
    rep(i,N){ int a; cin >> a; A[a].push_back(i); }
    for(auto& a : A) reverse(a.begin(), a.end());
    int p = 0;
    vector<int> ans;
    while(true){
        if(A[0].empty()) break;
        int mexval = 0;
        int maxidx = 0;
        while(A[mexval].size()){
            while(A[mexval].size() && A[mexval].back() < p) A[mexval].pop_back();
            if(A[mexval].size() == 0) break;
            maxidx = max(maxidx, A[mexval].back());
            mexval++;
        }
        if(mexval == 0) break;
        p = maxidx + 1;
        ans.push_back(mexval);
    }
    for(auto& a : A){
        while(a.size() && a.back() < p) a.pop_back();
        for(auto aa : a) ans.push_back(0);
    }

    cout << ans.size() << "\n";
    rep(i,ans.size()){ if(i) cout << " "; cout << ans[i]; } cout << "\n";
}


int main() {
    int T; cin >> T;
    rep(i,T) testcase();
    return 0;
}



struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;