#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int l, r;
int a[nax];
int n;

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

int query_max(int d, int x) {
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

int query_min(int d, int x) {
    int ans = 0;
    ptr p = root;
    for (int i = d - 1; i >= 0; i--) {
        int v = x >> i & 1;
        if (p->ch[v] != nullptr) {
            p = p->ch[v];
        } else {
            p = p->ch[v ^ 1];
            ans |= 1 << i;
        }
    }
    return ans;
}



void solve() {
    cin >> l >> r;
    n = r - l + 1;
    int sum = 0;
    int sum_a = 0;
    for (int i = 0 ; i < n ; ++ i) {
        sum ^= l + i;
        cin >> a[i];
        sum_a ^= a[i];
    }
    if (n % 2) {
        cout << (sum_a ^ sum) << '\n';
        return;
    }
    int res = a[n - 1]; /// b ^ x
    int res_a = sum_a ^ a[n - 1];
    vector <int> candidate;
    for (int i = n - 1 ; i >= 0 ; -- i) {
        int o_sum = sum ^ (l + i);
        int x1 = o_sum ^ res_a;
        int x2 = res ^ (l + i);
        if (x1 == x2) {
            candidate.push_back(x1);
        }
    }

    root = new Node();
    for (int i = 0 ; i < n ; ++ i) {
        add(17, a[i]);
    }

    for (auto x : candidate) {
        bool ok = true;
        int mn = query_min(17, x);
        int mx = query_max(17, x);
        if (mn >= l && mn <= r && mx >= l && mx <= r) {
            cout << x << '\n';
            return;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}