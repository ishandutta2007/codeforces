#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N, Q;
int A[200000];
int l, r;
LL C[1000001] = {};
LL mo_res = 0;

void mo_moverange(int new_l, int new_r) {
    for (; l > new_l; l--) { LL a = A[l - 1]; mo_res += a * (C[a] * 2 + 1); C[a]++; }
    for (; r < new_r; r++) { LL a = A[r]; mo_res += a * (C[a] * 2 + 1); C[a]++; }
    for (; l < new_l; l++) { LL a = A[l]; C[a]--; mo_res -= a * (C[a] * 2 + 1); }
    for (; r > new_r; r--) { LL a = A[r - 1]; C[a]--; mo_res -= a * (C[a] * 2 + 1); }
}

struct Query { int l, r, i; };
vector<vector<Query>> queries(500);
bool pred_querysort(const Query& a, const Query& b) { return a.r > b.r; }

LL ans[200000];

int main() {
    cin >> N >> Q;
    rep(i, N) cin >> A[i];

    rep(i, Q) {
        int l, r; cin >> l >> r; l--; r--;
        queries[l / 500].push_back({ l,r,i });
    }

    rep(i, 500) sort(queries[i].begin(), queries[i].end(), pred_querysort);

    l = r = 0;

    rep(i, 500) for (auto q : queries[i]) { mo_moverange(q.l, q.r + 1); ans[q.i] = mo_res; }

    rep(i, Q) cout << ans[i] << "\n";

    return 0;
}