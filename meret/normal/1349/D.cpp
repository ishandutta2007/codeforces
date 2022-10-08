#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MD = 998244353;
const int MX = 300005;

int n;

int mul(int a, int b) {
    return (a * (LL) b) % MD;
}

int power(int x, int y) {
    int result = 1;
    for (; y > 0; y >>= 1) {
        if (y & 1) {
            result = mul(result, x);
        }
        x = mul(x, x);
    }
    return result;
}

int inverse(int x) {
    return power(x, MD - 2);
}

int sub(int a, int b) {
    return (a + MD - b) % MD;
}

int add(int a, int b) {
    return (a + b) % MD;
}

int time_to_next[MX];
int a[MX];

int time_to_all[MX];

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < sum; ++i) {
        int chance_zero = mul(mul(sum - i, inverse(sum)), sub(1, inverse(n - 1)));
        int chance_minus = mul(i, inverse(sum));
        // x = 1 + (chance_minus + chance_zero) * x + chance_minus * time_to_next[i - 1]
        // (1 - (chance_minus + chance_zero)) * x = 1 + chance_minus * time_to_next[i - 1]
        int prev = 0;
        if (i > 0) {
            prev = time_to_next[i - 1];
        }
        time_to_next[i] = mul(inverse(sub(1, add(chance_minus, chance_zero))), add(1, mul(chance_minus, prev)));
    }
    time_to_all[sum] = 0;
    for (int i = sum - 1; i >= 0; --i) {
        time_to_all[i] = add(time_to_next[i], time_to_all[i + 1]);
    }
    // i_win_time = any_win_time + (1 - P(i_wins)) * time_change
    // sum(i_win_time) = n * any_win_time + (n - 1) * time_change
    int sum_to_all = 0;
    for (int i = 0; i < n; ++i) {
        sum_to_all = add(sum_to_all, time_to_all[a[i]]);
    }
    int result = mul(sub(sum_to_all, mul(n - 1, time_to_all[0])), inverse(n));
    cout << result << endl;
}