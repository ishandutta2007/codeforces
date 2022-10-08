
#include <bits/stdc++.h>

using namespace std;

// ind[color] = list of indices that have this color
// hist[frequency] = list of colors with this frequency
// a solution with priority_queue is perhaps simpler to implement,
// but here is an O(n) solution because we can.

const int N = 1e5 + 5;
int t, n, x, y, b[N], a[N];
vector<int> ind[N], hist[N];
bool mis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        for(int i = 0; i <= n + 1; i++) {
            ind[i].clear();
            hist[i].clear();
            mis[i] = false;
            a[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            ind[b[i]].push_back(i);
        }
        for(int i = 1; i <= n + 1; i++) {
            hist[ind[i].size()].push_back(i);
        }
        // greedily choose x indices by frequency
        int idx = n;
        for(int k = 1; k <= x; k++) {
            while(hist[idx].empty()) idx--;
            int col = hist[idx].back();
            // match the color and update our ind/hist structures
            a[ind[col].back()] = col;
            ind[col].pop_back();
            hist[idx].pop_back();
            hist[idx - 1].push_back(col);
        }
        while(idx > 0 && hist[idx].empty()) idx--;
        vector<int> ve;
        // idx = max frequency color of the remaining unmatched indices
        if(idx * 2 > 2 * n - x - y) {
            cout << "NO\n";
            continue;
        }
        // create a vector of the indices
        // put same colors together so that all we have to do is rotate by floor((n - x) / 2)
        for(int i = 1; i <= idx; i++) {
            for(int col : hist[i]) {
                ve.insert(ve.end(), ind[col].begin(), ind[col].end());
            }
        }
        int mismatch = n - y;
        auto makemismatch = [&](int i) {
            a[i] = hist[0][0];
            mismatch--;
            mis[i] = true;
        };
        for(int i = 0; i < n - x; i++) {
            a[ve[i]] = b[ve[(i + (n - x) / 2) % (n - x)]];
            if(a[ve[i]] == b[ve[i]]) makemismatch(ve[i]);
        }
        for(int i = 0; mismatch > 0; i++) {
            if(!mis[ve[i]]) makemismatch(ve[i]);
        }
        cout << "YES\n";
        for(int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}