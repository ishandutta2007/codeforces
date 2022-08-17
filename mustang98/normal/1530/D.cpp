#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int m[max_n];
int n;
int cnt[max_n];
int ans[max_n];

void solve_n() {
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        printf("%d ", m[i] + 1);
    }
    cout << "\n";
}

void solve_n1() {
    for (int i = 0; i < n; ++i) {
        cnt[m[i]]++;
    }
    int other = -1;
    int two = -1;
    for (int i = 0; i < n; ++i) {
        if (!cnt[i]) {
            other = i;
        }
        if (cnt[i] == 2) {
            two = i;
        }
    }
    //cout << other << ' ' << two << endl;
    if (m[other] == two) {
        ans[other] = two;
        for (int i = 0; i < n; ++i) {
            if (i == other) continue;
            if (m[i] == two) {
                ans[i] = other;
                continue;
            }
            ans[i] = m[i];
        }
    } else {
        for (int i = 0; i < n; ++i) {
            ans[i] = m[i];
            if (ans[i] == two) {
                ans[i] = other;
                two = -1;
            }
        }
    }
    cout << n - 1 << "\n";
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i] + 1);
    }
    cout << "\n";
}

void solve() {
    vector<int> pos;
    vector<int> val;
    for (int i = 0; i < n; ++i) {
        int cur = m[i];
        if (cnt[cur]) {
            ans[i] = -1;
            pos.PB(i);
        } else {
            ans[i] = cur;
            cnt[cur] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!cnt[i]) {
            val.PB(i);
        }
    }
    while (pos.size() > 2) {
        int p = pos.back();
        pos.pop_back();
        int v = val.back();
        val.pop_back();
        if (v != p) {
            ans[p] = v;
            continue;
        }
        ans[p] = val.back();
        val.back() = v;
    }
    int p1 = pos[0], p2 = pos[1];
    int v1 = val[0], v2 = val[1];
    if (p1 == v1 || p2 == v2) {
        swap(v1, v2);
    }
    ans[p1] = v1;
    ans[p2] = v2;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (ans[i] == m[i]) ++k;
    }
    printf("%d\n", k);
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i] + 1);
    }
    cout << "\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        set<int> s;
        for (int i = 0; i < n + 5; ++i) {
            ans[i] = cnt[i] = m[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", m + i);
            --m[i];
            s.insert(m[i]);
        }
        if (s.size() == n) {
            solve_n();
        } else if (s.size() + 1 == n) {
            solve_n1();
        } else {
            solve();
        }
    }

    return 0;
}