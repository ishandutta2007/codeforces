#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 2E6 + 5, MOD = 1E9 + 7;

int n, sum[N];
long long hsh[N], pw[N] = {1};
char s[N];
pair<int, int> ans = {N, N};
deque<int> de;

long long get_hash(int l, int r) {
    return (hsh[r] - hsh[l - 1] * pw[r - l + 1] + 1LL * MOD * MOD) % MOD;
}

bool compare(int u, int v) {
    int le = 0, ri = n - 1;
    while (le <= ri) {
        int mi = (le + ri) / 2;
        if (get_hash(u, u + mi) == get_hash(v, v + mi)) {
            le = mi + 1;
        } else {
            ri = mi - 1;
        }
    }
    if (le == n) {
        return true;
    } else {
        return s[u + le] < s[v + le];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        s[i + n] = s[i];
        sum[i + n] = sum[i] = (s[i] == '(' ? 1 : -1);
        hsh[i + n] = hsh[i] = (s[i] == '(' ? 0 : 1);
    }
    for (int i = 1; i < 2 * n; i++) {
        sum[i] += sum[i - 1];
        pw[i] = pw[i - 1] * 2 % MOD;
        (hsh[i] += hsh[i - 1] * 2) %= MOD;
    }
    for (int i = 0; i < n; i++) {
        while (!de.empty() && sum[de.back()] >= sum[i]) {
            de.pop_back();
        }
        de.push_back(i);
    }
    for (int i = n; i < 2 * n; i++) {
        int u = i - n + 1;
        while (!de.empty() && sum[de.back()] >= sum[i]) {
            de.pop_back();
        }
        de.push_back(i);
        while (!de.empty() && de.front() < i - n) {
            de.pop_front();
        }
        int len = sum[i - n] - sum[de.front()];
        if (len < ans.fi) {
            ans = {len, u};
        } else if (len == ans.fi && compare(u, ans.se)) {
            ans = {len, u};
        }
    }
    for (int i = 0; i < ans.fi; i++) {
        cout << '(';
    }
    for (int i = 0; i < n; i++) {
        cout << s[ans.se % n + i];
    }
    for (int i = 0; i < ans.fi + sum[n - 1]; i++) {
        cout << ')';
    }
}