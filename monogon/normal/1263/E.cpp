
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// letter = 0
// ( = 1
// ) = -1
// check that minimum prefix sum = 0 and sum = 0.

const int N = 1e6 + 5;
int n;
string s;
char ch[N];

struct node {
    int mn, mx, lazy;
    node(): mn(0), mx(0), lazy(0) {}
    node(int a, int b): mn(a), mx(b), lazy(0) {}
    node operator+(const node &o) const {
        return {min(mn, o.mn), max(mx, o.mx)};
    }
} tree[4 * N];

void prop(int i, int l, int r) {
    tree[i].mn += tree[i].lazy;
    tree[i].mx += tree[i].lazy;
    if(l < r) {
        tree[2 * i + 1].lazy += tree[i].lazy;
        tree[2 * i + 2].lazy += tree[i].lazy;
    }
    tree[i].lazy = 0;
}
node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return {INT_MAX, INT_MIN};
    if(L <= l && r <= R) return tree[i];
    prop(i, l, r);
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}
void upd(int i, int l, int r, int L, int R, int x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        tree[i].lazy += x;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int chval(char c) {
    return c == '(' ? 1 : c == ')' ? -1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int j = 0, sum = 0;
    for(char c : s) {
        switch(c) {
        case 'L':
            j = max(0, j - 1);
            break;
        case 'R':
            j++;
            break;
        default:
            int val = chval(c) - chval(ch[j]);
            ch[j] = c;
            sum += val;
            upd(0, 0, N - 1, j, N - 1, val);
            break;
        }
        node q = query(0, 0, N - 1, 0, N - 1);
        if(sum == 0 && q.mn == 0) {
            cout << q.mx << " ";
        }else {
            cout << "-1 ";
        }
    }
    cout << endl;
}