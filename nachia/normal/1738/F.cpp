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
    vector<int> Deg(N);
    rep(i,N) cin >> Deg[i];

    vector<int> Col(N, -1);
    int ColI = 1;
    vector<int> A(N); rep(i,N) A[i] = i;
    sort(A.begin(), A.end(), [&](int l, int r) -> bool { return Deg[l] > Deg[r]; });

    for(int a : A) if(Col[a] == -1){
        vector<int> Q = {a};
        while((int)Q.size() <= Deg[a]){
            cout << "? " << (a+1) << endl << flush;
            int res; cin >> res; res--;
            if(Col[res] != -1){
                for(int q : Q) Col[q] = Col[res];
                Q.clear();
                break;
            }
            Q.push_back(res);
        }
        if(Q.size()){
            for(int q : Q) Col[q] = ColI;
            ColI++;
        }
    }

    cout << "!";
    rep(i,N) cout << " " << Col[i];
    cout << endl << flush;
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