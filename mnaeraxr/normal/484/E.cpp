#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

struct node{
    node *l, *r;
    int L, R, M;
};

node* clone(node *u){
    node *ans = new node();
    ans->l = u->l, ans->r = u->r,
    ans->L = u->L, ans->R = u->R, ans->M = u->M;
    return ans;
}

node* build(int b, int e){
    node *ans = new node();
    if (b + 1 < e){
        int m = (b + e) >> 1;
        ans->l = build(b, m);
        ans->r = build(m, e);
    }
    return ans;
}

void merge(node* l, node* r, node* p, int b, int m, int e){
    p->R = r->R == e - m ? r->R + l->R : r->R;
    p->L = l->L == m - b ? l->L + r->L : l->L;
    p->M = max({l->M, r->M, l->R + r->L});
}

node* update(node *root, int b, int e, int x){
    root = clone(root);

    if (b + 1 == e){
        root->L = root->R = root->M = 1;
    }
    else{
        int m = (b + e) >> 1;
        if (x < m) root->l = update(root->l, b, m, x);
        else root->r = update(root->r, m, e, x);

        merge(root->l, root->r, root, b, m, e);
    }

    return root;
}

int query(node *root, int b, int e, int x, int y){
    if (x <= b && e <= y)
        return root->M;

    int m = (b + e) >> 1, a = 0;

    if (x < m) a = max(a, query(root->l, b, m, x, y));
    if (m < y) a = max(a, query(root->r, m, e, x, y));

    if (x < m && m < y)
        a = max(a, min(m - x, root->l->R) + min(y - m, root->r->L));

    return a;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<pii> arr(n);

    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        arr[i] = {-v, i};
    }

    sort(arr.begin(), arr.end());
    vector<node*> R(n + 1);

    R[0] = build(0, n);

    for (int i = 0; i < n; ++i)
        R[i + 1] = update(R[i], 0, n, arr[i].second);

    int q; cin >> q;

    while (q--){
        int a, b, c;
        cin >> a >> b >> c;
        a--;

        int lo = -1, hi = n - 1;
        while (lo + 1 < hi){
            int m = (lo + hi) / 2;

            if (query(R[m + 1], 0, n, a, b) >= c)
                hi = m;
            else
                lo = m;
        }

        cout << -arr[hi].first << endl;
    }

    return 0;
}