#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


bool is_palindrome(const vector<int>& A){
    int N = A.size();
    rep(i,N) if(A[i] != A[N-1-i]) return false;
    return true;
}

vector<int> erased(const vector<int>& A, int to_erase){
    vector<int> res;
    for(int a : A) if(a != to_erase) res.push_back(a);
    return res;
}


void testcase(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    int to_erase[2] = { -1 , -1 };
    rep(i,N){
        if(A[i] != A[N-1-i]){
            to_erase[0] = A[i];
            to_erase[1] = A[N-1-i];
            break;
        }
    }
    rep(t,2) if(is_palindrome(erased(A,to_erase[t]))){ cout << "YES\n"; return; }
    cout << "NO\n";
}


int main(){
    int T; cin >> T;
    rep(caseid, T) testcase();
    return 0;
}




struct ios_do_not_sync {
    ios_do_not_sync() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} ios_do_not_sync_instance;