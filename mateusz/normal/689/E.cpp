#include <bits/stdc++.h>

using namespace std;

const int N = 200005, M = 1e9 + 7;

int fact[N], factInv[N];
int from[N], to[N];
int state[2 * N];
int difference[2 * N];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

int power(int a, int k) {
    if (k == 0) {
        return 1;
    }
    return (long long)power((long long)a * a % M, k / 2) * (k % 2 == 1 ? a : 1) % M;
}

int inv(int w) {
    return power(w, M - 2);
}

int newton(int n, int k) {
    if (k > n) {
        return 0;
    }
    return (long long)((long long)fact[n] * factInv[k] % M) * factInv[n - k] % M;
}

int n, k;

int main() {

    scanf("%d %d", &n, &k);

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (long long)fact[i - 1] * i % M;
    }

    factInv[n] = inv(fact[n]);
    for (int i = n - 1; i >= 0; i--) {
        factInv[i] = (long long)factInv[i + 1] * (i + 1) % M;
    }

    vector<pair<int, int> > events;
    events.push_back({-M, 0});
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &from[i], &to[i]);
        events.push_back({from[i], 0});
        events.push_back({to[i] + 1, 1});
    }

    sort(events.begin(), events.end());

    int in = 0;
    for (int i = 1; i < events.size(); i++) {
        if (events[i].first != events[i - 1].first) {
            in++;
            difference[in - 1] = events[i].first - events[i - 1].first;
        }
        if (events[i].second == 0) {
            state[in]++;
        } else {
            state[in]--;
        }
    }

    int ans = 0;
    int cnt = 0;
    for (int i = 1; i < in; i++) {
        cnt += state[i];
        add(ans, (long long)newton(cnt, k) * difference[i] % M);
    }

    printf("%d\n", ans);

    return 0;
}