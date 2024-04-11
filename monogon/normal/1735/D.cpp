
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
    node* child[3];
    node() {
        rep(i, 0, 3) {
            child[i] = NULL;
        }
    }
};

void ins(node *x, const vi &v) {
    for(int k : v) {
        if(x->child[k] == NULL) {
            x->child[k] = new node();
        }
        x = x->child[k];
    }
}
bool check(node *x, const vi &v) {
    for(int k : v) {
        if(x->child[k] == NULL) return false;
        x = x->child[k];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vi> a(n, vi(k));
    node* root = new node;
    rep(i, 0, n) {
        rep(j, 0, k) {
            cin >> a[i][j];
        }
        ins(root, a[i]);
    }
    vi add(k);
    ll ans = 0;
    rep(i, 0, n) {
        int cnt = 0;
        rep(j, 0, n) {
            if(i == j) continue;
            rep(l, 0, k) {
                add[l] = (a[i][l] == a[j][l] ? a[i][l] : 3 ^ a[i][l] ^ a[j][l]);
            }
            cnt += check(root, add);
        }
        cnt /= 2;
        ans += 1ll * cnt * (cnt - 1) / 2;
    }
    cout << ans << '\n';
}