
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct node {
    int a, b, c, ab, bc, abc;
    node() {
        a = b = c = ab = bc = abc = 0;
    }
    node(char ch) {
        a = b = c = ab = bc = abc = 0;
        if(ch == 'a') a = 1;
        else if(ch == 'b') b = 1;
        else if(ch == 'c') c = 1;
    }
    node operator+(const node &o) const {
        node X;
        X.a = a + o.a;
        X.b = b + o.b;
        X.c = c + o.c;
        X.ab = min(ab + o.b, a + o.ab);
        X.bc = min(bc + o.c, b + o.bc);
        X.abc = min({a + o.abc, ab + o.bc, abc + o.c});
        return X;
    }
};

const int N = 1e5 + 5;
node tree[4 * N];

void build(int i, int l, int r, const string &s) {
    if(l == r) {
        tree[i] = node(s[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m, s);
    build(2 * i + 2, m + 1, r, s);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void upd(int i, int l, int r, int k, char c) {
    if(l == r) {
        tree[i] = node(c);
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) upd(2 * i + 1, l, m, k, c);
    else upd(2 * i + 2, m + 1 ,r ,k, c);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    string s;
    cin >> n >> q >> s;
    build(0, 0, n - 1, s);
    while(q--) {
        int i; char c;
        cin >> i >> c;
        i--;
        upd(0, 0, n - 1, i, c);
        cout << tree[0].abc << '\n';
    }
}