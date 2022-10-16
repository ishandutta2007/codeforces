#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct segment_tree{
    struct node{
        node *left, *right;
        int value, lazy;
    };

    node *root;
    int b, e;

    segment_tree(){
        root = new node();
        b = 0, e = 1000000000 + 1;
    }

    void push(node *r){
        if (!r->right) r->right = new node();
        if (!r->left)  r->left  = new node();

        if (r->lazy){
            r->right->value += r->lazy;
            r->right->lazy  += r->lazy;
            r->left->value += r->lazy;
            r->left->lazy  += r->lazy;
            r->lazy = 0;
        }
    }

    void update(node *r, int b, int e, int x, int y){
        if (x <= b && e <= y){
            r->value += 1;
            r->lazy += 1;
        }
        else{
            push(r);

            int m = (b + e) / 2;

            if (x < m) update(r->left, b, m, x, y);
            if (m < y) update(r->right, m, e, x, y);

            r->value = min(r->left->value, r->right->value);
        }
    }

    int query(node *r, int b, int e, int x, int y){
        if (x <= b && e <= y) return r->value;
        
        push(r);

        int m = (b + e) / 2, ans = 2;

        if (x < m) ans = min(ans, query(r->left, b, m, x, y));
        if (m < y) ans = min(ans, query(r->right, m, e, x, y));

        return ans;
    }

    void update(int x, int y){
        update(root, b, e, x, y);
    }

    int query(int x, int y){
        return query(root, b, e, x, y);
    }
};

int main(){
    int n; cin >> n;

    segment_tree st;

    vector<pii> I(n);

    for (int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;

        I[i] = pii(x, y);

        st.update(x, y + 1);
    }

    for (int i = 0; i < n; ++i){
        int x = I[i].first, y = I[i].second;

        if (st.query(x, y + 1) > 1){
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}