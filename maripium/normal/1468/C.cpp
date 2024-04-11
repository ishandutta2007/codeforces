#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> Q;
    vector<int> A;
    set<int> all;
    map<int, queue<int>> qs;
    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            int c; cin >> c;
            all.emplace(A.size());
            qs[c].emplace(A.size());
            A.emplace_back(c);
        } else if (op == 2) {
            int cur = *all.begin();
            cout << cur+1 << ' ';
            all.erase(cur);
            qs[A[cur]].pop();
        } else {
            while ((--qs.end())->second.empty()) qs.erase(--qs.end());
            int cur = (--qs.end())->second.front();
            cout << cur+1 << ' ';
            qs[A[cur]].pop();
            all.erase(cur);
        }
    }
}