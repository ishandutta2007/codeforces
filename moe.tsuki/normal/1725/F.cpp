#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        ++R[i];
    }

    int qans[30] = {};
    for (int l = 0; l < 30; l++) {
        int &ans = qans[l];
        vector<pair<int,int>> seg;
        for (int i = 0; i < N; i++)
            if (R[i] - L[i] >= (1 << l)) {
                seg.emplace_back(0, 1);
                seg.emplace_back(1 << l, -1);
            } else {
                int le = L[i] % (1 << l);
                int ri = R[i] % (1 << l);
                if (le < ri) {
                    seg.emplace_back(le, 1);
                    seg.emplace_back(ri, -1);
                } else {
                    seg.emplace_back(0, 1);
                    seg.emplace_back(ri, -1);

                    seg.emplace_back(le, 1);
                    seg.emplace_back(1 << l, -1);
                }
            }
        sort(seg.begin(), seg.end());

        int cnt = 0;
        for (int i = 0, j; i < seg.size(); i = j) {
            for (j = i; j < seg.size(); j++) {
                if (seg[j].first != seg[i].first) {
                    break;
                }
                cnt += seg[j].second;
            }
            ans = max(ans, cnt);
        }
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        int W;
        cin >> W;
        int lg = __lg(W & -W);
        cout << qans[lg] << '\n';
    }
}