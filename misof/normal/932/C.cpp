// another fine solution by misof
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

void add_cycle(vector<int> &perm, int &kde, int dlzka) {
    for (int i=0; i<dlzka-1; ++i) perm[kde+i] = kde+i+1;
    perm[kde+dlzka-1] = kde;
    kde += dlzka;
}

void solve(long long N, long long ca, long long A, long long cb, long long B) {
    vector<int> answer(N+1);
    int kde = 1;
    for (int i=0; i<ca; ++i) add_cycle(answer,kde,A);
    for (int i=0; i<cb; ++i) add_cycle(answer,kde,B);
    for (int n=1; n<=N; ++n) cout << (n>1?" ":"") << answer[n];
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long N, A, B;
    cin >> N >> A >> B;
    for (long long ca=0; ca<=N; ++ca) {
        if (ca * A > N) break;
        if ((N - ca * A) % B) continue;
        long long cb = (N - ca * A) / B;
        solve(N,ca,A,cb,B);
        return 0;
    }
    cout << -1 << "\n";
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread