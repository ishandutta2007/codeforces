#include <bits/stdc++.h>

using namespace std;

int N, K;
bool b[200005];
vector <int> v;

int main(void) {
    cin >> N >> K;
    int x;
    for (int i = 1; i <= N; ++i) cin >> x, b[i] = (x >= 0);
    int cur = 0, mn = 1;
    for (int i = 1; i <= N; ++i) {
        mn = min(mn, 1 * b[i]);
        if (b[i]) ++cur;
        else {
            --K;
            if (cur) v.push_back(cur);
            cur = 0;
        }
    }
    if (K < 0) return cout << -1 << endl, 0;
    if (mn == 1) return cout << 0 << endl, 0;
    if (b[1] == 1) v.erase(v.begin());
    int tot = 2 * (v.size() + 1);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) if (K >= v[i]) tot -= 2, K -= v[i]; else break;
    if (K >= cur) --tot;
    cout << tot << endl;
}