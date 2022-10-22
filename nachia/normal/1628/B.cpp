
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i32 = int;
using u32 = unsigned int;
#define rep(i,n) for(int i=0; i<(n); i++)


bool testcase(){
    int N; cin >> N;
    vector<string> S(N);
    rep(i,N){ cin >> S[i]; }
    for(auto a : S){
        auto reva = a; reverse(reva.begin(), reva.end());
        if(a == reva) return true;
    }

    rep(t,2){
        set<string> s2;
        set<string> s3;
        for(auto s : S){
            if(s.size() == 2){
                auto revs = s;
                swap(revs[0], revs[1]);
                if(s2.count(revs)) return true;
                s2.insert(s);
            }
            if(s.size() == 3){
                auto revs = s;
                swap(revs[0], revs[2]);
                if(s2.count(revs.substr(0,2))) return true;
                if(s3.count(revs)) return true;
                s3.insert(s);
            }
        }
        reverse(S.begin(), S.end());
        for(auto& a : S) reverse(a.begin(), a.end());
    }
    return false;
}


int main() {
    int T; cin >> T;
    rep(i,T) cout << (testcase() ? "YES\n" : "NO\n");
    return 0;
}



struct ios_do_not_sync{
    ios_do_not_sync(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
} ios_do_not_sync_instance;