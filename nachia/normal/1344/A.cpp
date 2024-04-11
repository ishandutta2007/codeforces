#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL T; scanf("%d", &T);
        while (T--) {
            UL N; scanf("%d", &N);
            vector<int> A(N); rep(i, N) scanf("%d", &A[i]);
            rep(i, N) {
                A[i] += 1000000000;
                A[i] += i;
                A[i] %= N;
            }
            sort(A.begin(), A.end());
            bool ok = true;
            rep(i, N) if (A[i] != i) ok = false;
            cout << (ok ? "YES" : "NO") << endl;
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}