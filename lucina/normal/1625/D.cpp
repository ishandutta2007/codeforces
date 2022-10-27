#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int a[nax];
array <int, 2> fuck[nax];
/// ref: https://atcoder.jp/contests/arc122/submissions/23369258
struct Node {
    Node * ch[2];
    Node() : ch{} {}
};
using ptr = Node*;

ptr root;
void add(int d, int x) {
    ptr p = root;
    for (int i = d - 1; i >= 0; i--) {
        int v = x >> i & 1;
        if (p->ch[v] == nullptr) {
            p->ch[v] = ptr(new Node());
        }
        p = p->ch[v];
    }
}

int query(int d, int x) {
    int ans = 0;
    ptr p = root;
    for (int i = d - 1; i >= 0; i--) {
        int v = x >> i & 1;
        if (p->ch[v ^ 1] != nullptr) {
            ans |= 1 << i;
            p = p->ch[v ^ 1];
        } else {
            p = p->ch[v];
        }
    }
    return ans;
}

vector <int> ans;

bool solve(int b, int l, int r) {
    if (b < 0) {
        for (int j = l ; j <= r ; ++ j)
            ans.push_back(j);
        return r >= l;
    }
    if (l > r) return false;

    if (k >> b & 1) {
        /// this means we have to choose
        /// maximum pair and test whether it's greater than k
        root = ptr(new Node());
        add(30, a[l]);
        for (int j = l + 1 ; j <= r ; ++ j) {
            int foo = query(30, a[j]);
            if (foo >= k) {
                ans.push_back(j);
                int good = a[j] ^ foo;
                for (int v = l ; v < j ; ++ v)
                if (a[v] == good) {
                    ans.push_back(v);
                    return true;
                }
                assert(false);
            }
            add(30, a[j]);
        }
        return false;
    } else {
        int par = l;
        for (int i = l ; i <= r ; ++ i) {
            if (a[i] >> b & 1) {
                par = i;
                break;
            }
        }
        bool gl = solve(b - 1, l, par - 1);
        bool gr = solve(b - 1, par, r);
        if (gl && gr) return true;
        if (!gl && gr) {
            if (l <= par - 1) ans.push_back(l);
            return true;
        }
        if (!gr && gl) {
            if (par <= r) ans.push_back(par);
            return true;
        }
        if (!gl && !gr && l <= par - 1 && par <= r) {
            ans.push_back(l);
            ans.push_back(r);
            return true;
        }
        return false;
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        fuck[i] = {a[i], i};
    }
    sort(fuck + 1, fuck + 1 + n);
    for (int i = 1 ; i <= n ; ++ i)
        a[i] = fuck[i][0];

    solve(29, 1, n);

    if (ans.empty()) {
        cout << "-1\n";
        return 0;
    }
    cout << ans.size() << '\n';
    for (int x : ans)
        cout << fuck[x][1] << ' ';
    cout << '\n';
}