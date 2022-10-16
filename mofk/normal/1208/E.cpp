#include <bits/stdc++.h>

using namespace std;

int n, w;
int len[1000006];
vector <int> a[1000006];
long long sub[1000006];
long long tot;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> w;
    ++w;
    for (int i = 1; i <= n; ++i) {
        cin >> len[i];
        len[i] += 2;
        a[i].resize(len[i]);
        for (int j = 1; j < len[i] - 1; ++j) cin >> a[i][j];
        int x = max_element(a[i].begin(), a[i].end()) - a[i].begin();
        tot += a[i][x];
        int spare = w - len[i] + 2;
        deque <int> dq;
        for (int j = 0; j < x; ++j) {
            while (dq.size() && j - dq.front() + 1 > spare) dq.pop_front();
            while (dq.size() && a[i][dq.back()] <= a[i][j]) dq.pop_back();
            dq.push_back(j);
            sub[j] += a[i][x] - a[i][dq.front()];
        }
        dq.clear();
        for (int j = w, k = len[i] - 1; k > x; --j, --k) {
            while (dq.size() && dq.front() - k + 1 > spare) dq.pop_front();
            while (dq.size() && a[i][dq.back()] <= a[i][k]) dq.pop_back();
            dq.push_back(k);
            sub[j] += a[i][x] - a[i][dq.front()];
        }
    }
    for (int i = 1; i < w; ++i) cout << tot - sub[i] << ' '; cout << endl;
    return 0;
}