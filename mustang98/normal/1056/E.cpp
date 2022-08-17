#include <bits/stdc++.h>
#include <random>
#include <chrono>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222, mod = 1000000009;

string base;
string s;
char cs[max_n];

ll h[max_n];
ll h1[max_n];
ll pr = 37;
ll pr1 = 101;
vector<int> prm{29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107};

ll p[max_n];
ll p1[max_n];

void init() {
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    pr = prm[gen() % prm.size()];
    pr1 = prm[gen() % prm.size()];

    p[0] = 1;
    p1[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        p1[i] = p1[i - 1] * pr1;
        p[i] = p[i - 1] * pr;
        p[i] %= mod;
    }

    h[0] = pr * s[0];
    h1[0] = pr1 * s[0];
    for (int i = 1; i < s.size(); ++i) {
        h1[i] = (h1[i - 1] + s[i]) * pr1;
        h[i] = (h[i - 1] + s[i]) * pr;
        h[i] %= mod;
    }
}

ll get_hash(int l, int r) {
    if (l == 0) return h[r];
    return (h[r] - (h[l - 1] * p[r - l + 1]) % mod + 2 * mod) % mod;
}

ll get_hash1(int l, int r) {
    if (l == 0) return h1[r];
    return (h1[r] - h1[l - 1] * p1[r - l + 1]);
}

ll h01, h02;

bool is_eq0(int l2, int r2) {
    ll h21 = get_hash(l2, r2);
    ll h22 = get_hash1(l2, r2);
    return h01 == h21 && h02 == h22;
}

ll h11, h12;

bool is_eq1(int l2, int r2) {
    ll h21 = get_hash(l2, r2);
    ll h22 = get_hash1(l2, r2);
    return h11 == h21 && h12 == h22;
}


bool is_eq(int l1, int r1, int l2, int r2) {
    ll h11 = get_hash(l1, r1);
    ll h12 = get_hash1(l1, r1);
    ll h21 = get_hash(l2, r2);
    ll h22 = get_hash1(l2, r2);

    return h11 == h21 && h12 == h22;
}

int cnt0 = 0, cnt1 = 0;
int fst1 = -1;

bool check(int l0, int l1) {
    int st1 = fst1 * l0;
    if (is_eq(0, l0 - 1, st1, st1 + l1 - 1)) {
        return 0;
    }
    h01 = get_hash(0, l0 - 1);
    h02 = get_hash1(0, l0 - 1);
    h11 = get_hash(st1, st1 + l1 - 1);
    h12 = get_hash1(st1, st1 + l1 - 1);

    int start = 0;
    for (int i = 0; i < base.size(); ++i) {
        if (base[i] == '0') {
            if (!is_eq0(start, start + l0 - 1)) {
                return 0;
            }
            start += l0;
        } else {
            if (!is_eq1(start, start + l1 - 1)) {
                return 0;
            }
            start += l1;
        }
    }
    return 1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%s", cs);
    base = cs;
    scanf("%s", cs);
    s = cs;
    init();
    if (base[0] == '1') {
        for (int i = 0; i < base.size(); ++i) {
            if (base[i] == '0') {
                base[i] = '1';
            } else {
                base[i] = '0';
            }
        }
    }
    for (int i = 0; i < base.size(); ++i) {
        if (base[i] == '0') {
            ++cnt0;
        } else {
            if (fst1 == -1) {
                fst1 = i;
            }
            ++cnt1;
        }
    }
    int ans = 0;
    for (int len0 = 1; len0 <= s.size(); ++len0) {
        ll sumlen0 = 1LL * cnt0 * len0;
        if (sumlen0 >= s.size()) break;
        ll sumlen1 = s.size() - sumlen0;
        if (sumlen1 % cnt1 != 0) continue;
        int len1 = sumlen1 / cnt1;
        ans += check(len0, len1);
    }
    cout << ans;
    return 0;
}