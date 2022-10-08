
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n, p[N], c[N];
vector<vector<int>> cycles;
bool vis[N];

bool check(const vector<int> &v, int k) {
    int n = v.size();
    for(int i = 0; i < k; i++) {
        int j = i;
        int minc = N, maxc = -1;
        do {
            minc = min(minc, c[v[j]]);
            maxc = max(maxc, c[v[j]]);
            j = (j + k) % n;
        }while(j != i);
        if(minc == maxc) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        fill(vis, vis + n, false);
        cycles.clear();
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vector<int> v;
                int j = i;
                do {
                    v.push_back(j);
                    vis[j] = true;
                    j = p[j];
                }while(j != i);
                cycles.push_back(v);
            }
        }
        int ans = n;
        for(int i = 0; i < (int) cycles.size(); i++) {
            int p = cycles[i].size();
            for(int d = 1; d * d <= p; d++) {
                if(p % d == 0) {
                    if(check(cycles[i], d)) {
                        ans = min(ans, d);
                    }
                    if(check(cycles[i], p / d)) {
                        ans = min(ans, p / d);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}