#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, max_a = 15100000, inf = 1000111222;

int m[max_n];
int n;
int cnt[max_a];

int r[max_a];

void fact(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            a /= i;
            cnt[i]++;
            while (a % i == 0) {
                a /= i;
            }
        }
    }
    if (a > 1) {
        cnt[a]++;
    }
}

void fact1(int a) {
    while(r[a] != 0) {
        int d = r[a];
        cnt[d]++;
        while(a % d == 0) {
            a /= d;
        }
    }
    if (a > 1) {
        cnt[a]++;
    }
}

void init() {
    for (int i = 2; i * i <= max_a; ++i) {
        if (r[i] != 0) continue;
        for (int j = i * i; j < max_a; j += i) {
            r[j] = i;
        }
    }
}

int main()
{
    init();
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", m + i);
    }
    bool is_eq = 1;
    for (int i = 1; i < n; ++i) {
        if (m[i] != m[0]) {
            is_eq = 0;
            break;
        }
    }
    if (is_eq) {
        cout << -1;
        return 0;
    }

    ll gcd = m[0];
    for (int i = 1; i < n; ++i) {
        gcd = __gcd(gcd, (ll)m[i]);
    }
    for (int i = 0; i < n; ++i) {
        m[i] /= gcd;
        fact1(m[i]);
    }
    int mx = -1;
    for (int i = 0; i < max_a; ++i) {
        mx = max(mx, cnt[i]);
    }
    cout << n - mx;

    return 0;
}