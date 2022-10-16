#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

struct node{
    node *l, *r;
    int value;
};

node* clone(node *u){
    node *ans = new node();
    ans->l = u->l, ans->r = u->r, ans->value = u->value;
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

node* update(node *root, int b, int e, int x){
    root = clone(root);

    if (b + 1 == e){
        root->value = 1;
    }
    else{
        int m = (b + e) >> 1;
        if (x < m) root->l = update(root->l, b, m, x);
        else root->r = update(root->r, m, e, x);
        root->value = root->l->value + root->r->value;
    }

    return root;
}

int query(node *root, int b, int e, int x, int y){
    if (x <= b && e <= y) return root->value;

    int m = (b + e) >> 1;
    int answer = 0;

    if (x < m) answer += query(root->l, b, m, x, y);
    if (m < y) answer += query(root->r, m, e, x, y);
    return answer;
}

int n, q;
int col[maxn];
int idx[maxn];
node* roots[maxn];

int subrect(int x1, int y1, int x2, int y2){
    if (x1 > x2) return 0;
    if (y1 > y2) return 0;
    return query(roots[y2], 0, n, x1, x2+1) - query(roots[y1 - 1], 0, n, x1, x2 + 1);
}

int64 tri(int n){
    return 1LL * n * (n - 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 0; i < n; ++i){
        cin >> col[i];
        idx[i] = i;
    }

    sort(idx, idx + n, [&](int u, int v){
        return col[u] < col[v];
    });

    roots[0] = build(0, n);

    for (int i = 1, p = 0; i <= n; ++i){
        roots[i] = roots[i - 1];

        while (p < n && col[idx[p]] == i){
            roots[i] = update(roots[i], 0, n, idx[p]);
            p++;
        }
    }

    while (q--){
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        l--; r--;

        int64 answer = 0;

        answer =    tri( subrect(r + 1, 1, n-1, n) ) +
                    tri( subrect(0, 1 ,l-1, n) ) +
                    tri( subrect(0, u + 1,n-1, n) ) +
                    tri( subrect(0, 1, n-1, d-1) ) -
                    tri( subrect(r+1, u+1, n-1, n) ) -
                    tri( subrect(r+1, 1,n-1, d-1) ) -
                    tri( subrect(0, 1,l-1, d-1) ) -
                    tri( subrect(0, u+1,l-1, n) );

        answer = tri(n) - answer;

        cout << answer << endl;
    }



    return 0;
}