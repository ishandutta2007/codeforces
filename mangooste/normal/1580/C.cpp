#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    vector<int> last(n, -1);
    vector<vector<pair<int, int>>> events(n);

    for (int i = 0; i < m; i++) {
        int type, id;
        cin >> type >> id;
        id--;

        if (type == 1) {
            assert(last[id] == -1);
            last[id] = i;
        } else {
            events[id].emplace_back(last[id], i);
            last[id] = -1;
        }
    }

    for (int i = 0; i < n; i++)
        if (last[i] != -1)
            events[i].emplace_back(last[i], m);

    const int B = 250;//sqrt(m);
    vector<vector<int>> updates(B);

    vector<int> pref(m + 1);
    vector<int> to_add(m + 1);

    vector<int> answer(m);
    for (int id = 0; id < n; id++)
        if (x[id] + y[id] >= B)
            for (auto [l, r] : events[id])
                for (int i = l + x[id]; i < r; i += x[id] + y[id]) {
                    pref[i]++;
                    pref[min(r, i + y[id])]--;
                }
        else
            updates[x[id] + y[id]].push_back(id);

    for (int i = 1; i < m; i++)
        pref[i] += pref[i - 1];

    for (int i = 0; i < m; i++)
        answer[i] += pref[i];

    for (int s = 2; s < B; s++) {
        fill(all(pref), 0);
        fill(all(to_add), 0);

        for (auto id : updates[s])
            for (auto [l, r] : events[id]) {
                if (l + x[id] >= r)
                    continue;

                pref[l + x[id]]++;
                int to = l + x[id] + (r - 1 - l - x[id]) / s * s;
                if (to + s < m)
                    pref[to + s]--;

                if (l + s >= r) {
                    if (r - 1 - l >= x[id])
                        to_add[r]--;

                    continue;
                }

                pref[l + s]--;
                to = l + s + (r - 1 - l - s) / s * s;
                if (to + s < m)
                    pref[to + s]++;

                if (r - 1 - to >= x[id])
                    to_add[r]--;
            }

        for (int i = s; i < m; i++)
            pref[i] += pref[i - s];

        for (int i = 0; i < m; i++)
            pref[i] += to_add[i];

        for (int i = 1; i < m; i++)
            pref[i] += pref[i - 1];

        for (int i = 0; i < m; i++)
            answer[i] += pref[i];
    }

    for (auto x : answer)
        cout << x << '\n';
}