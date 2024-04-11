#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 300111, max_val = 1e6 + 100, inf = 1000111222;

int m[max_n];
int ind[max_val];
int n;
int ans[max_n];
int pr[max_n];
int sz[max_n];

int get_pr(int cur) {
    if (pr[cur] == cur) {
        return cur;
    }
    int res = get_pr(pr[cur]);
    pr[cur] = res;
    return res;
}

void unite(int a, int b) {
    a = get_pr(a);
    b = get_pr(b);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    sz[a] += sz[b];
    pr[b] = a;
}

bool is_sos[max_val];
int pr_ind[max_val];

void init() {
    for(int i= 0 ; i < max_n; ++i) {
        sz[i]= 1;
        pr[i] = i;
    }
    for (int cur = 2; cur < max_val; ++cur) {
        if (is_sos[cur]) {
            continue;
        }
        vector<int> v;
        m[n] = cur;
        v.PB(n);
        pr_ind[cur] = n;
        ++n;

        for (int j = cur; j < max_val; j += cur) {
            if (j != cur) {
                is_sos[j] = 1;
            }
            if (ind[j] != -1) {
                v.PB(ind[j]);
            }
        }
        for (int i = 0; i + 1 < v.size(); ++i) {
            unite(v[i], v[i + 1]);
        }
    }
}

map<pair<int, int>, vector<int>> mp;

vector<int> getp(int x) {
    vector<int> p;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            p.PB(i);
        }
        while(x % i == 0) {
            x /= i;
        }
    }
    if (x != 1) {
        p.PB(x);
    }
    return p;
}

int main() {
    int q;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> q;
    int orn = n;
    memset(ind, -1, sizeof(ind));
    for (int i = 0; i < n; ++i) {
        scanf("%d", m + i);
        ind[m[i]] = i;
    }
    init();
    for (int i = 0; i < q; ++i) {
        int s, t;
        scanf("%d%d", &s, &t);
        --s, --t;
        int ss = get_pr(s);
        int tt = get_pr(t);
        if (ss == tt) {
            ans[i] = 0;
            continue;
        }
        if (m[s] % 2 == 0 || m[t] % 2 == 0) {
            ans[i] = 1;
            continue;
        }
        ans[i] = 2;
        if (ss > tt) {
            swap(ss, tt);
        }
        mp[MP(ss, tt)].PB(i);
    }
    for (int i = 0; i < orn; ++i) {
        int x = m[i];
        vector<int> p1 = getp(x);
        vector<int> p2 = getp(x + 1);
        for (int x : p2) {
            p1.PB(x);
        }
        vector<int> pp;
        for (int a : p1) {
            pp.PB(get_pr(pr_ind[a]));
        }
        sort(pp.begin(), pp.end());
        pp.erase(unique(pp.begin(), pp.end()), pp.end());
        for (int i = 0; i < pp.size(); ++i){
            for (int j = i + 1; j < pp.size(); ++j) {
                int a = pp[i], b = pp[j];
                if (mp.find(MP(a, b)) != mp.end()) {
                    for (int x : mp[MP(a, b)]) {
                        ans[x] = 1;
                    }
                    mp[MP(a, b)].clear();
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}