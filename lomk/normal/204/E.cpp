/*input
7 4
rubik
furik
abab
baba
aaabbbababa
abababababa
zero

3 1
abc
a
ab
*/
#ifdef UncleGrandpa
#define LOCAL 1
#else
#define LOCAL 0
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#define debug(x...) {if constexpr(LOCAL)cout << "[" << #x << "] ="; print(x);}
void print() {if constexpr(LOCAL)cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {if constexpr(LOCAL)cout << value << ' ', print(values...);}
const int N = 2e5 + 5;

struct SuffixArray {
    string a;
    int n, m;
    vector<int> SA, LCP, x, y, w, c;
    // m is the size of alphabet. In case of passing vector in, change M to max ai. All ai!=0
    SuffixArray() {};
    SuffixArray(string _a, int m = 128) : a(" " + _a), n(a.size()), m(m),
        SA(n), LCP(n), x(n), y(n), w(max(m, n)), c(n) {
        a[0] = 0;
        DA();
        kasaiLCP();
        rotate(SA.begin(), SA.begin() + 1, SA.end()); SA.pop_back();
        rotate(LCP.begin(), LCP.begin() + 1, LCP.end()); LCP.pop_back();
        a.erase(a.begin());
        for (auto &it : SA) it--;
    }

    bool cmp (int u, int v, int l) {
        return (y[u] == y[v] && (u + l < n && v + l < n ? y[u + l] == y[v + l] : false));
    }

    void Sort() {
        loop(i, 0, m - 1) w[i] = 0;
        loop(i, 0, n - 1) ++w[x[y[i]]];
        loop(i, 0, m - 2) w[i + 1] += w[i];
        rloop(i, n - 1, 0) SA[--w[x[y[i]]]] = y[i];
    }

    void DA() {
        loop(i, 0, n - 1) x[i] = a[i], y[i] = i;
        Sort();
        for (int i, j = 1, p = 1; p < n; j <<= 1, m = p) {
            for (p = 0, i = n - j; i < n; i++) y[p++] = i;
            loop(k, 0, n - 1) if (SA[k] >= j) y[p++] = SA[k] - j;
            Sort();
            for (swap(x, y), p = 1, x[SA[0]] = 0, i = 1; i < n; ++i)
                x[SA[i]] = cmp(SA[i - 1], SA[i], j) ? p - 1 : p++;
        }
    }

    void kasaiLCP() {
        loop(i, 0, n - 1) c[SA[i]] = i;
        for (int i = 0, j, k = 0; i < n; LCP[c[i++]] = k)
            if (c[i] > 0) for (k ? k-- : 0, j = SA[c[i] - 1]; a[i + k] == a[j + k]; k++);
            else k = 0;
    };
} SA;

struct SuperSet {
    int cnt[N]; int ret = 0;
    SuperSet() {
        memset(cnt, 0, sizeof(cnt));
    }
    void add(int i) {
        if (i == -1) return;
        cnt[i]++; ret += (cnt[i] == 1);
    }
    int trem(int i) {
        if (i == -1) return ret;
        return ret - (cnt[i] == 1);
    }
    void rem(int i) {
        if (i == -1) return;
        cnt[i]--; ret -= (cnt[i] == 0);
    }
    int get() {
        return ret;
    }
} Set;

int n, lim;
string s;
int in[N], eno[N], length[N];
vector<int> lcp, sa;

void prepEno() {
    int iter = 0;
    loop(i, 0, n - 1) {
        Set.add(in[sa[i]]);
        while (iter < i && Set.trem(in[sa[iter]]) >= lim) {
            Set.rem(in[sa[iter]]);
            iter++;
        }
        if (Set.get() >= lim) eno[i] = iter;
        else eno[i] = -1;
    }
}

int lg2[N], rmq[20][N];
long long ans[N];
void buildRMQ() {
    lg2[1] = 0;
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i / 2] + 1;
    for (int i = 0; i < n; i++) rmq[0][i] = lcp[i];
    for (int k = 1; k <= lg2[n]; k++)
        for (int i = 0; i + (1 << k) - 1 < n; i++)
            rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
}

int getRMQ(int l, int r) {
    int len = lg2[r - l + 1];
    return min(rmq[len][l], rmq[len][r - (1 << len) + 1]);
}

int solve(int p, int q) {
    auto check = [&](int base) {
        if (base == 0) return true;
        int L = p, R = p;
        if (p + 1 <= n - 1) {
            int l = p + 1, r = n - 1;
            while (l != r) {
                int mid = (l + r + 1) / 2;
                if (getRMQ(p + 1, mid) >= base) l = mid;
                else r = mid - 1;
            }
            if (getRMQ(p + 1, l) >= base) R = l;
        }
        if (p != 0) {
            int l = 0, r = p;
            while (l != r) {
                int mid = (l + r) / 2;
                if (getRMQ(mid, p) >= base) r = mid;
                else l = mid + 1;
            }
            if (getRMQ(l, p) >= base)
                L = l - 1;
        }
        if (eno[R] < L) return false;
        return true;
    };

    int l = 0, r = length[q];
    while (l != r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> lim; int m = n;
    memset(in, -1, sizeof(in));
    loop(i, 0, n - 1) {
        string t; cin >> t;
        s += "$" + t;
        loop(j, 1, t.size()) {
            in[s.size() - j] = i;
            length[s.size() - j] = j;
        }
    }
    n = s.size();
    SA = SuffixArray(s);
    sa = SA.SA;
    lcp = SA.LCP;
    prepEno();
    buildRMQ();
    // loop(i, 0, n - 1) cout << in[sa[i]] << sp;
    // cout << endl;
    // loop(i, 0, n - 1) cout << i << sp << eno[i] << endl;
    // cout << endl;
    // cout << endl;
    loop(i, 0, n - 1) {
        if (in[sa[i]] == -1) continue;
        // cout << i << endl;
        ans[in[sa[i]]] += solve(i, sa[i]);
    }
    loop(i, 0, m - 1) cout << ans[i] << sp;
    // print(sa);


}