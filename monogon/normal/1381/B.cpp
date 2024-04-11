
#include <bits/stdc++.h>

using namespace std;

// compute block lengths, and do subset sum.
// O(n^2) subset sum is a standard dp
// For educational purposes, here is the O(n sqrt(n)) solution
// we treat each distinct length independently, and remember the number of occurrences
// use the helper array a to update the dp states

const int N = 1e5 + 5;
int t, n, p[2 * N], a[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int mx = 0;
        vector<int> ind;
        for(int i = 1; i <= 2 * n; i++) {
            cin >> p[i];
            if(p[i] > mx) {
                mx = p[i];
                ind.push_back(i);
            }
        }
        ind.push_back(2 * n + 1);
        vector<int> lens;
        for(int i = 1; i < (int) ind.size(); i++) {
            lens.push_back(ind[i] - ind[i - 1]);
        }
        sort(lens.begin(), lens.end());
        fill(vis, vis + n + 1, false);
        vis[0] = true;
        int m = lens.size();
        for(int k = 0; k < m; k++) {
            int r = k;
            while(r < m && lens[r] == lens[k]) r++;
            fill(a, a + n + 1, 0);
            for(int i = lens[k]; i <= n; i++) {
                if(!vis[i] && vis[i - lens[k]] && a[i - lens[k]] < r - k) {
                    a[i] = a[i - lens[k]] + 1;
                    vis[i] = true;
                }
            }
            k = r - 1;
        }
        cout << (vis[n] ? "YES" : "NO") << '\n';
    }
}