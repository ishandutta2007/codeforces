#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int X = 5e5 + 5;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, k, n, s;

    cin >> m >> k >> n >> s;

    vector<int> a(m);
    vector<vector<int>> ar(X);

    for (int i = 0; i < m; i++) {
        cin >> a[i];
        ar[a[i]].push_back(i);
    }

    vector<int> b(s);
    vector<int> CNT(X);

    for (int i = 0; i < s; i++) {
        cin >> b[i];
        CNT[b[i]]++;
    }
    sort(b.begin(), b.end());

    int can = m - k * n;

    for (int i = 0; i < m; i += k) {
        int j = min(m, i + can + k);
        // [i, j)
        int ok = 1;
        for (int qi = 0; qi < s; qi++) {
            int qj = qi;
            while (qj < s && b[qi] == b[qj]) {
                qj++;
            }
            qj--;
            int qcnt = qj - qi + 1;
            int hcnt = lower_bound(ar[b[qi]].begin(), ar[b[qi]].end(), j)
                    - lower_bound(ar[b[qi]].begin(), ar[b[qi]].end(), i);
            if (hcnt < qcnt) {
                ok = 0;
                break;
            }
            qi = qj;
        }
        if (ok) {
            vector<int> ans;
            for (int q = i; q < j && can > 0; q++) {
                if (CNT[a[q]]) {
                    CNT[a[q]]--;
                } else {
                    can--;
                    ans.push_back(q + 1);
                }
            }
            cout << (int)ans.size() << "\n";
            for (int x : ans) {
                cout << x << " ";
            }
            cout << "\n";
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}