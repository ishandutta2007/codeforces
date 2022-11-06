#include <bits/stdc++.h>

using namespace std;

long long n;
int k;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool query(long long from, long long to) {
    cout << from << " " << to << endl;
    string ans;
    cin >> ans;
    return ans == "Yes";
}

void solve(long long low, long long high);

void guess(long long low, long long high) {
    if (high - low + 1 > 60) {
        solve(low, high);
    } else {
        long long x = uniform_int_distribution<long long>(low, high)(rng);
        if (!query(x, x)) {
            solve(max(1LL, low - k), min(n, high + k));
        }
    }
}

void solve(long long low, long long high) {
    if (high - low + 1 <= 60) {
        guess(low, high);
        return;
    }
    
    long long mid = (low + high) / 2;
    if (query(low, mid)) {
        solve(max(1LL,low - k), min(n, mid + k));
    } else {
        solve(max(1LL, mid - k), min(n, high + k));
    }
}

int main() {
    cin >> n >> k;
    solve(1, n);
    return 0;
}