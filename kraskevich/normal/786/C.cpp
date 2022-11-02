#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

struct Node {
    int s;
    Node* L;
    Node* R;

    Node(int s_ = 0, Node* L_ = nullptr, Node* R_ = nullptr): s(s_), L(L_), R(R_) {} 
};

Node* build(int l, int r) {
    Node* t = new Node();
    if (l == r)
        return t;
    int m = (l + r) / 2;
    t->L = build(l, m);
    t->R = build(m + 1, r);
    return t;
}

Node* upd(Node* t, int l, int r, int pos, int delta) {
    Node* nt = new Node(t->s + delta, t->L, t->R);
    if (l == r)
        return nt;
    int m = (l + r) / 2;
    if (pos <= m)
        nt->L = upd(t->L, l, m, pos, delta);
    else
        nt->R = upd(t->R, m + 1, r, pos, delta);
    return nt;
}

int get_next(Node* t, int l, int r, int k) {
    if (t->s < k)
        return -1;
    if (l == r)
        return l;
    int m = (l + r) / 2;
    int sr = t->R->s;
    if (sr >= k)
        return get_next(t->R, m + 1, r, k);
    return get_next(t->L, l, m, k - sr);
}


const int N = 100 * 1000 + 10;
Node* roots[N];
int a[N];
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> last;
    roots[0] = build(0, n - 1);
    for (int i = 0; i < n; i++) {
        Node* cur = roots[i];
        if (last.count(a[i])) 
            cur = upd(cur, 0, n - 1, last[a[i]], -1);
        last[a[i]] = i;
        cur = upd(cur, 0, n - 1, i, 1);
        roots[i + 1] = cur;
    }
    for (int k = 1; k <= n; k++) {
        int res = 0;
        int r = n - 1;
        while (r >= 0) {
            res++;
            r = get_next(roots[r + 1], 0, n - 1, k + 1);
        }
        cout << res <<  " ";
    }
    cout << "\n";
}