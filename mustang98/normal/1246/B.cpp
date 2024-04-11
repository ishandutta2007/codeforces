#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int m[max_n];
int n, k;
vector<ll> pk;

void calcpk() {
    const ll mx = 1LL * max_n * max_n;
    for (int i = 1; i < max_n; ++i) {
        ll val = i;
        for (int j = 1; j < k; ++j) {
            val *= i;
            if (val > mx) {
                return;
            }
        }
        pk.push_back(val);
    }
}

vector<int> del[max_n];
set<int> del2[max_n];
int cnt[max_n];

ll solve2() {
    for (int i = 0; i < n; ++i) {
        cnt[m[i]]++;
    }
    for (int i = 1; i < max_n; ++i) {
        for (int j = i; j < max_n; j += i) {
            del[j].push_back(i);
        }
    }
    for (int i = 1; i < max_n; ++i) {
        for (int a : del[i]) {
            for (int b : del[i]) {
                if (1LL * a * b >= max_n) {
                    continue;
                }
                del2[i].insert(a * b);
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < max_n; ++i) {
        ll p = 1LL * i * i;
        for (int d1 : del2[i]) {
            ll d2 = p / d1;
            if (d2 >= max_n) {
                continue;
            }
            if (d1 == d2) {
                ans += 1LL * cnt[d1] * (cnt[d1] - 1);
            } else {
                ans += 1LL * cnt[d1] * cnt[d2];
            }
        }
    }
    return ans / 2;
}

ll solve3() {
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int a = m[i];
        for (ll j : pk) {
            ll res = j / a;
            if (res >= max_n || res * a != j) {
                continue;
            }
            ans += cnt[res];
        }
        ++cnt[a];
    }
    return ans;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //n = 100000;
    //k = 3;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        //m[i] = 1 + rand() % 100000;
        cin >> m[i];
    }
    if (k >= 3) {
        calcpk();
        cout << solve3() << endl;
        return 0;
    } else {
        cout << solve2() << endl;
        return 0;
    }
    return 0;
}