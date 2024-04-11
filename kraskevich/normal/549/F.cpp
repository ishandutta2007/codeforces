#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct Tree {
    vector<pii> t;
    int size;

    void build(int i, int l, int r, const vector<int>& data) {
        if (l == r) {
            t[i] = pii(data[l], l);
            return;
        }
        int m = (l + r) / 2;
        build(2 * i + 1, l, m, data);
        build(2 * i + 2, m + 1, r, data);
        t[i] = max(t[2 * i + 1], t[2 * i + 2]);
    }

    Tree(const vector<int>& data = {}) {
        size = data.size();
        if (size == 0)
            return;
        t.resize(4 * size + 10);
        build(0, 0, size - 1, data);
    }

    pii getMax(int i, int l, int r, int tl, int tr) {
        if (l == tl && r == tr)
            return t[i];
        pii pl;
        pii pr;
        int m = (tl + tr) / 2;
        if (l <= m)
            pl = getMax(2 * i + 1, l, min(r, m), tl, m);
        if (r > m)
            pr = getMax(2 * i + 2, max(l, m + 1), r, m + 1, tr);
        return max(pl, pr);
    }

    pii getMax(int l, int r) {
        return getMax(0, l, r, 0, size - 1);
    }        
};

const int N = (int) 1e6;

vector<int> a;
vector<long long> sums;
vector<int> sub[N];
vector<int> add[N];
int n;
long long k;
Tree tree;

void solve(int l, int r) {
    if (l >= r)
        return;
    int m = tree.getMax(l, r).second;
    long long val = a[m];
    solve(l, m - 1);
    solve(m + 1, r);
    int L = m - l;
    int R = r - m;
    if (L <= R) {
        for (int i = l - 1; i <= m - 1; i++) {
            int want = (sums[i] + val) % k;
            int delta = i == m - 1 ? 1 : 0;
            if (m + delta <= r) {
                sub[m + delta].push_back(want);
                add[r].push_back(want); 
            }
        }
    } else {
        for (int i = m; i <= r; i++) {
            int want = (sums[i] - val % k + k) % k;
            int delta = i == m ? 1 : 0;
            if (l - 1 <= m - 1 - delta) { 
                sub[l - 1].push_back(want);
                add[m - 1 - delta].push_back(want);
            }
        }  
    } 
}

long long stupid() {
    int res = 0;
    for (int L = 1; L <= n; L++)
         for (int R = L; R <= n; R++) {
         }
    return res;
}

int main() {
    cin >> n >> k;
    a.resize(n + 1);
    sums.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];       
        sums[i] = sums[i - 1] + a[i];
    }
    tree = Tree(a);
    solve(1, n);
    long long res = 0;
    vector<int> cur(k);
    for (int i = 0; i <= n; i++) {
        for (int x : sub[i])
            res -= cur[x];
        cur[sums[i] % k]++;
        for (int x : add[i])
            res += cur[x];            
    }    
    cout << res << endl;
    return 0;
}