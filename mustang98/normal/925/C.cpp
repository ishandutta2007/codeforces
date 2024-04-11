#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_p = 63, inf = 1000111222;

vector<ll> v[max_p + 10];
int n;
vector<ll> result;

bool get_bit(ll a, int i) {
    return (a & (1LL << i)) ? 1 : 0;
}

ll f(int bit, ll mid) {
    bool bit_v = get_bit(mid, bit);
    if (bit_v == 0 && v[bit].size()) {
        ll cur = v[bit].back();
        v[bit].pop_back();
        if (bit) {
            ll l_mid = f(bit - 1, mid);
            result.PB(cur);
            ll r_mid = f(bit - 1, l_mid ^ mid ^ cur);
            return l_mid ^ cur ^ r_mid;
        } else {
            result.PB(cur);
            return cur;
        }
    } else {
        if (bit == 0) return 0;
        return f(bit - 1, mid);
    }
}

void print(ll a) {
    for (int j = 5; j >= 0; --j) {
        cout << get_bit(a, j);
    }
        cout << endl;
}

void clr() {
    for (int i = 0; i <= max_p; ++i) {
        v[i].clear();
    }
    result.clear();
}

vector<ll> solve(vector<ll> init) {
    vector<ll> empt;
    int n = init.size();
    for (int i = 0; i < n; ++i) {
        ll a = init[i];
        for (int j = max_p; j >= 0; --j) {
            if ((1LL << j) & a) {
                v[j].PB(a);
                break;
            }
        }
    }
    int max_bit;
    for (int i = max_p; i >= 0; --i) {
        if (v[i].size()) {
            max_bit = i;
            break;
        }
    }
    if (v[max_bit].size() > 1) {
        return empt;
    }
    f(max_bit, 0);

    if (result.size() != n) {
        return empt;
    }
    return result;
}

bool check(vector<ll> v) {
    int a = 0;
    vector<ll> r;
    for (int i = 0; i < result.size(); ++i) {
        a ^= v[i];
        r.PB(a);
    }
    for (int i = 1; i < r.size(); ++i) {
        if (r[i] <= r[i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //cin >> n;
    if (0) {
        int len = 17;
        for (int i = 0; i < 100; ++i) {
            clr();
            vector<ll> a;
            vector<ll> init;
            for (int j = 0; j < len; ++j) {
                a.PB(1 + rand() % 1000000);
            }
            sort(a.begin(), a.end());
            bool cont = 0;
            for (int j = 1; j < a.size(); ++j) {
                if (a[j] == a[j - 1]) {
                    cont = 1;
                    break;
                }
            }
            if (cont) continue;
            init.PB(a[0]);
            for (int j = 1; j < a.size(); ++j) {
                init.PB(a[j] ^ a[j - 1]);
            }
            vector<ll> res = solve(init);
            if (res.size() == 0 || check(res) == 0) {
                cout << "WA" << endl;
                for (int k = 0; k < init.size(); ++k) {
                    cout << a[k] << ' ';
                }
                cout << endl;
                for (int k = 0; k < init.size(); ++k) {
                    cout << init[k] << ' ';
                }
                exit(0);
            }
            cout << "OK" << endl;
        }
    } else {
        int n;
        cin >> n;
        vector<ll> a;
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            a.PB(x);
            //print(x);
        }
        vector<ll> res = solve(a);
        if (res.size() == 0) {
            cout << "No";
            return 0;
        }
        cout << "Yes" << endl;
        for (int i = 0; i < n; ++i) {
            cout << res[i] << ' ';
        }
    }

    return 0;
}