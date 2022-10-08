#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;

int n, m, ka, kb, deg[N];
priority_queue<int, vector<int>, greater<int>> pa, pb;
vector<int> a, b;
vector<pair<int, int>> ve;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> ka >> kb;
    a = vector<int>(ka); b = vector<int>(kb);
    for (int i = ka - 1; i >= 0; i--) {
        cin >> a[i];
        deg[a[i]]++;
    }
    for (int i = kb - 1; i >= 0; i--) {
        cin >> b[i];
        deg[b[i]]++;
    }
    for (int i = 1; i <= n + m; i++) {
        if (deg[i] == 0) {
            (i <= n ? pa : pb).push(i);
        }
    }
    while (!a.empty() || !b.empty()) {
        if (!b.empty() && !pa.empty()) {
            ve.push_back({b.back(), pa.top()});
            pa.pop();
            if (--deg[b.back()] == 0) {
                pb.push(b.back());
            }
            b.pop_back();
        } else if (!a.empty() && !pb.empty()) {
            ve.push_back({a.back(), pb.top()});
            pb.pop();
            if (--deg[a.back()] == 0) {
                pa.push(a.back());
            }
            a.pop_back();
        } else {
            return cout << "No\n", 0;
        }
    }
    while (!pa.empty()) {
        a.push_back(pa.top()); pa.pop();
    }
    while (!pb.empty()) {
        b.push_back(pb.top()); pb.pop();
    }
    if (a.empty() || b.empty()) {
        return cout << "No\n", 0;
    }
    ve.push_back({a[0], b[0]});
    for (int i = 1; i < a.size(); i++) {
        ve.push_back({a[i], b[0]});
    }
    for (int i = 1; i < b.size(); i++) {
        ve.push_back({b[i], a[0]});
    }
    cout << "Yes\n";
    for (pair<int, int> &v : ve) {
        cout << v.first << " " << v.second << '\n';
    }
}