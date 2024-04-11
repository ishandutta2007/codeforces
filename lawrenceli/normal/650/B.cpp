#include <bits/stdc++.h>

using namespace std;

const int maxn = 500100;

int N, a, b, T;
char s[maxn];
int pw[maxn], ph[maxn];
int ans;

void go() {
    for (int i = 0; i < N; i++) {
        pw[i + 1] = (s[i] == 'w') + pw[i];
        ph[i + 1] = (s[i] == 'h') + ph[i];
    }

    for (int i = 0; i < N; i++) {
        int sum = i + 1 + a * i + b * pw[i + 1];
        if (sum <= T) ans = max(ans, i + 1);

        int lo = i + 1, hi = N;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int val = sum + a * i + (N - mid) * (a + 1) + b * (pw[N] - pw[mid]);
            if (val <= T) hi = mid;
            else lo = mid + 1;
        }

        if (lo < N) ans = max(ans, i + 1 + N - lo);
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> N >> a >> b >> T >> s;
    go();
    reverse(s, s + N);
    rotate(s, s + N - 1, s + N);
    go();

    cout << ans << '\n';
}