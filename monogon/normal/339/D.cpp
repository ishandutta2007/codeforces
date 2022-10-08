
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

const int N = (1 << 17) + 5;
int tree[4 * N], a[N];

void build(int i, int l, int r, bool x) {
    if(l == r) {
        tree[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m, !x);
    build(2 * i + 2, m + 1, r, !x);
    if(x) tree[i] = tree[2 * i + 1] ^ tree[2 * i + 2];
    else tree[i] = tree[2 * i + 1] | tree[2 * i + 2];
}
void upd(int i, int l, int r, int k, bool x) {
    if(l == r) {
        tree[i] = a[k];
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) upd(2 * i + 1, l, m, k, !x);
    else upd(2 * i + 2, m + 1, r, k, !x);
    if(x) tree[i] = tree[2 * i + 1] ^ tree[2 * i + 2];
    else tree[i] = tree[2 * i + 1] | tree[2 * i + 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 0, 1 << n) cin >> a[i];
    bool x = (n % 2 == 0);
    build(0, 0, (1 << n) - 1, x);
    while(m--) {
        int p, b;
        cin >> p >> b;
        a[p - 1] = b;
        upd(0, 0, (1 << n) - 1, p - 1, x);
        cout << tree[0] << '\n';
    }
}