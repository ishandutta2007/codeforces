#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 1005;
int A[maxN][maxN];
int n;
pair<int,int> p[maxN];
int sz[maxN];
pair<int,int> get(int x) {
    if (x == p[x].first) {
        return p[x];
    }
    auto t = get(p[x].first);
    p[x] = {t.first, p[x].second ^ t.second};
    return p[x];
}
void unite(int a, int b, int x) {
    auto pa = get(a);
    auto pb = get(b);
    assert(pa.first != pb.first);
    if (sz[pa.first] < sz[pb.first]) {
        swap(pa, pb);
    }
    sz[pa.first] += sz[pb.first];
    p[pb.first] = {pa.first, pa.second ^ (pb.second ^ x)};
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        p[i] = {i, 0};
        sz[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                if (A[i][j] != A[j][i]) {
                    auto pi = get(i);
                    auto pj = get(j);
                    if (pi.first != pj.first) {
                        unite(i, j, (A[i][j] > A[j][i]));
                        if (A[i][j] > A[j][i]) swap(A[i][j], A[j][i]);
                    }
                    else {
                        if ((pi.second ^ pj.second)) {
                            swap(A[i][j], A[j][i]);
                        }
                    }
                }
            }
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}