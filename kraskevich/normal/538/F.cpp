#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6;

struct Node {
    int sum;
    Node* L;
    Node* R;
    
    Node(int sum = 0, Node* L = nullptr, Node* R = nullptr): sum(sum), L(L), R(R) {}
};

Node* build(int l, int r) {
    Node* res = new Node();
    if (l == r)
        return res;
    int m = (l + r) / 2;
    res->L = build(l, m);
    res->R = build(m + 1, r);
    return res;
}

Node* upd(Node* t, int l, int r, int pos) {
    if (l == r)
        return new Node(t->sum + 1);
    int m = (l + r) / 2;
    if (pos <= m)
        return new Node(t->sum + 1, upd(t->L, l, m, pos), t->R);
    return new Node(t->sum + 1, t->L, upd(t->R, m + 1, r, pos));
}

int getSum(Node* t, int tl, int tr, int l, int r) {
    if (l == tl && r == tr)
        return t->sum;
    int m = (tl + tr) / 2;
    int sl = 0;
    int sr = 0;
    if (l <= m)
        sl = getSum(t->L, tl, m, l, min(r, m));
    if (r > m)
        sr = getSum(t->R, m + 1, tr, max(l, m + 1), r);
    return sl + sr;
}

int ans[N];
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pii> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }   
    sort(b.begin(), b.end());
    Node* root = build(0, n - 1);
    vector<Node*> roots;
    for (int i = 0; i < n; i++) {
        roots.push_back(root);
        root = upd(root, 0, n - 1, b[i].second);
    }
    for (int i = 0; i < n; i++) {
        int v = lower_bound(b.begin(), b.end(), pii(a[i], i)) - b.begin();
        for (int k = 1; k <= n - 1; k++) {
            int low = k * i + 2;
            int high = k * (i + 1) + 1;
            low--;
            high--;
            high = min(high, n - 1);
            if (low >= n)
                break;
            ans[k] += getSum(roots[v], 0, n - 1, low, high);
        }
    }
    for (int i = 1; i <= n - 1; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}