//    
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

ll binpow(ll a, int p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        (a *= a) %= mod;
        p >>= 1;
    }
    return res;
}

int combine(int a, int b) {
    int mn = min(a, b);
    return mn + (a - mn) / 3 * 2 + (b - mn);
}

pair<ll, int> solve0(vector<int>& cycles, int n) {
    ll prod = binpow(3, n / 3);
    int cnt = 0;
    vector<int> mod(3);
    for (int len : cycles) {
        mod[len % 3]++;
        cnt += (len - 1) / 3;
    }
    cnt += combine(mod[1], mod[2]);
    return {prod, cnt};
}

pair<ll, int> solve1(vector<int>& cycles, int n) {
    ll prod = 4 * binpow(3, n / 3 - 1) % mod;
    int cnt = 0;
    bool isFourDetachable = false;
    vector<int> mod(3);
    for (int len : cycles) {
        mod[len % 3]++;
        cnt += (len - 1) / 3;
        isFourDetachable |= (len >= 4) && (len % 3 == 1);
    }

    vector<int> mem = mod;
    int cnt22 = cnt;
    if (mod[2] >= 2) {
        mod[2] -= 2;
        cnt22 += combine(mod[1], mod[2]);
    } else if (mod[2]) {
        mod[2]--;
        mod[1] -= 2;
        cnt22++;
        cnt22 += combine(mod[1], mod[2]);
    } else if (mod[1] >= 4) {
        mod[1] -= 4;
        cnt22 += 2;
        cnt22 += combine(mod[1], mod[2]);
    } else {
        // no reason to combine
        cnt22 = 1e9;
    }

    int cnt4 = cnt;
    mod = mem;
    if (isFourDetachable) {
        mod[1]--;
        cnt4--;
        cnt4 += combine(mod[1], mod[2]);
    } else if (mod[0] && mod[1]) {
        mod[1]--;
        cnt4++;
        cnt4 += combine(mod[1], mod[2]);
    } else {
        // no reason to combine
        cnt4 = 1e9;
    }

    return {prod, min(cnt22, cnt4)};
}

pair<ll, int> solve2(vector<int>& cycles, int n) {
    ll prod = 2 * binpow(3, n / 3) % mod;
    int cnt = 0;
    vector<int> mod(3);
    for (int len : cycles) {
        mod[len % 3]++;
        cnt += (len - 1) / 3;
    }
    if (mod[2]) {
        mod[2]--;
        cnt += combine(mod[1], mod[2]);
    } else {
        mod[1] -= 2;
        cnt++;
        cnt += combine(mod[1], mod[2]);
    }
    return {prod, cnt};
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& i : p) {
        cin >> i;
        i--;
    }

    vector<int> cycles;
    vector<int> used(n);
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        int length = 1;
        for (int v = p[i]; v != i; v = p[v]) {
            used[v] = 1;
            length++;
        }
        cycles.push_back(length);
    }

    vector<function<pair<ll, int>(vector<int>&, int)>> get{solve0, solve1, solve2};
    ll prod, cnt;
    tie(prod, cnt) = get[n % 3](cycles, n);
    cout << prod << ' ' << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}