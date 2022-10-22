#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n * m);
        for (int i = 0; i < n * m; i++) cin >> a[i];
        vector<int> perm(n * m); iota(perm.begin(), perm.end(), 0);
        sort(perm.begin(), perm.end(), [&](int i, int j) {
            if (a[i] == a[j]) return i < j;
            return a[i] < a[j];
        });
        for (int it = 0; it < (int) perm.size(); it++) {
            int jit = it;
            while (jit < (int) perm.size() && a[perm[it]] == a[perm[jit]] && it / m == jit / m) jit++;
            jit--;
            // [it, jit]
            sort(perm.begin() + it, perm.begin() + jit + 1);
            reverse(perm.begin() + it, perm.begin() + jit + 1);
            it = jit;
        }
//        for (int i : perm)
//            cout << i << " ";
//        cout << "\n";
        vector<int> ppos(n * m);
        for (int i = 0; i < n * m; i++)
            ppos[perm[i]] = i;
        vector<vector<int>> used(n, vector<int>(m));
        int res = 0;
        for (int it = 0; it < (int) perm.size(); it++) {
            int pos = ppos[it];
            int i = pos / m;
            int j = pos % m;
            for (int q = 0; q <= j; q++) res += used[i][q];
            used[i][j] = 1;
        }
        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}