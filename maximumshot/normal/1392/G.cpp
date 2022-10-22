#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<int> mul(const vector<int>& a, const vector<int>& b) {
    vector<int> c = a;
    for (int i = 0; i < (int) c.size(); i++) {
        c[i] = a[b[i]];
    }
    return c;
}

vector<int> inv(const vector<int>& a) {
    vector<int> b = a;
    for (int i = 0; i < (int) a.size(); i++)
        b[a[i]] = i;
    return b;
}

vector<int> get_id_perm(int n) {
    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = i;
    return id;
}

vector<int> get_pair_perm(int n, int i, int j) {
    vector<int> id = get_id_perm(n);
    swap(id[i], id[j]);
    return id;
}

string apply_perm(const string& s, const vector<int>& perm) {
    string t = s;
    for (int i = 0; i < (int) perm.size(); i++) {
        t[perm[i]] = s[i];
    }
    return t;
}

int get_cnt_eq(const string& a, const string& b) {
    int res = 0;
    for (int i = 0; i < (int) a.size(); i++)
        res += a[i] == b[i];
    return res;
}

tuple<int, int, int> slow(int n, int m, int k, string a, string b, vector<pii> pairs) {
    int best_eq = -1, L = -1, R = -1;
    for (int l = 0; l < n; l++) {
        string c = a;
        for (int r = l; r < n; r++) {
            auto [i, j] = pairs[r];
            swap(c[i], c[j]);
            if (r - l + 1 >= m) {
                int cnt_eq = 0;
                for (int q = 0; q < k; q++)
                    cnt_eq += b[q] == c[q];
                if (best_eq < cnt_eq) {
                    best_eq = cnt_eq;
                    L = l, R = r;
                }
            }
        }
    }
    return {best_eq, L + 1, R + 1};
}

int string_to_int(const string& s) {
    int res = 0;
    for (char c : s)
        res = res * 2 + c - '0';
    return res;
}

tuple<int, int, int> fast(int n, int m, int k, string a, string b, vector<pii> pairs) {
    int best_eq = -1, L = -1, R = -1;
    auto update_res = [&](int tmp_eq, int l, int r) {
        if (tmp_eq > best_eq) {
            best_eq = tmp_eq;
            L = l, R = r;
        }
    };
    vector<vector<int>> suff(n), pref(n);
    for (int i = 0; i < n; i++) {
        if (i == 0)
            pref[i] = get_id_perm(k);
        else
            pref[i] = pref[i - 1];
        pref[i] = mul(pref[i], get_pair_perm(k, pairs[i].first, pairs[i].second));
    }
    {
        vector<int> used(1 << k, -1);
        for (int j = 0, i = 0; i < n; i++) {
            while (i - j + 1 >= m) {
                int xa = string_to_int(apply_perm(a, j > 0 ? pref[j - 1] : get_id_perm(k)));
                if (used[xa] == -1)
                    used[xa] = j;
                j++;
            }
            int y = string_to_int(apply_perm(b, pref[i]));
            if (used[y] != -1 && i - used[y] + 1 >= m) {
                return {k, used[y] + 1, i + 1};
            }
        }
    }
    vector<pii> as;
    vector<int> dist(1 << k, inf), from(1 << k, -1);
    queue<int> que;
    auto add = [&](int mask, int i) {
        dist[mask] = 0;
        from[mask] = i;
        que.push(mask);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int bit = 0; bit < k; bit++) {
                int to = v ^ (1 << bit);
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    from[to] = from[v];
                    que.push(to);
                }
            }
        }
    };
    for (int j = 0, i = 0; i < n; i++) {
        while (i - j + 1 >= m) {
            int xa = string_to_int(apply_perm(a, j > 0 ? pref[j - 1] : get_id_perm(k)));
            add(xa, j);
            j++;
        }
        int y = string_to_int(apply_perm(b, pref[i]));
        if (dist[y] != inf) {
            update_res(k - dist[y], from[y], i);
        }
    }
//    for (int l = 0; l < n; l++) {
//        for (int r = l + m - 1; r < n; r++) {
//            string s1 = apply_perm(b, pref[r]);
//            string s2 = apply_perm(a, (l > 0 ? pref[l - 1] : get_id_perm(k)));
//            update_res(get_cnt_eq(s1, s2), l, r);
//        }
//    }
    return {best_eq, L + 1, R + 1};
}

void work() {
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    vector<pii> pairs(n);
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
        pairs[i].first--;
        pairs[i].second--;
    }
    auto [s, l, r] = fast(n, m, k, a, b, pairs);
    cout << s << "\n" << l << " " << r << "\n";
}

string gen_binary_string(int n, mt19937& rnd) {
    string res(n, '?');
    for (char& c : res)
        c = rnd() % 2 + '0';
    return res;
}

void test() {
    mt19937 rnd(42);
    const int N = 15;
    while (1) {
        int n, m, k;
        n = rnd() % N + 1;
        m = rnd() % n + 1;
        k = rnd() % N + 2;
        string a, b;
        a = gen_binary_string(k, rnd);
        b = gen_binary_string(k, rnd);
        vector<pii> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i].first = rnd() % k;
            while (1) {
                pairs[i].second = rnd() % k;
                if (pairs[i].first != pairs[i].second)
                    break;
            }
        }
        auto [fs_s, fs_l, fs_r] = fast(n, m, k, a, b, pairs);
        auto [sl_s, sl_l, sl_r] = slow(n, m, k, a, b, pairs);
        if (fs_s == sl_s) {
            cout << "OK(" << fs_s << " " << fs_l << " " << fs_r << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl_s << " " << sl_l << " " << sl_r << "\n";
            cout << "fnd = " << fs_s << " " << fs_l << " " << fs_r << "\n";
            cout << n << " " << m << " " << k << "\n";
            cout << a << "\n" << b << "\n";
            for (auto [i, j] : pairs)
                cout << i + 1 << " " << j + 1 << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}