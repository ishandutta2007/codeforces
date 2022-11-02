#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200 * 1000 + 100;
const int INF = (int)1e9;

const string WANT = "2017";

struct Node {
    int dp[5][5];

    Node() {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                dp[i][j] = INF;
    }
};

Node unite(const Node& L, const Node& R) {
    Node res;
    for (int l = 0; l < 5; l++)
        for (int r = l; r < 5; r++) 
            for (int k = l; k <= r; k++)
                res.dp[l][r] = min(res.dp[l][r], L.dp[l][k] + R.dp[k][r]);         
    return res;
}

Node tree[4 * N + 10];
string s;
int n, q;

void build(int i, int l, int r) {
    if (l == r) {
        for (int j = 0; j < 5; j++) {
            if (j < WANT.length() && s[l] == WANT[j]) {
                tree[i].dp[j][j + 1] = 0;
                tree[i].dp[j][j] = 1;
            } else {
                tree[i].dp[j][j] = 0;
            }
        }        
        if (s[l] == '6') {
            tree[i].dp[3][3] = tree[i].dp[4][4] = 1;        
        }
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = unite(tree[2 * i + 1], tree[2 * i + 2]);
}

Node get(int i, int tl, int tr, int l, int r) {
    if (l == tl && r == tr)
        return tree[i];
    int m = (tl + tr) / 2;
    Node L;
    Node R;
    if (l <= m)
        L = get(2 * i + 1, tl, m, l, min(r, m));
    if (r > m)
        R = get(2 * i + 2, m + 1, tr, max(m + 1, l), r);
    if (r <= m)
        return L;
    if (l > m)
        return R;
    return unite(L, R);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> q;
    cin >> s;
    build(0, 0, n - 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int res = get(0, 0, n - 1, l, r).dp[0][4];
        if (res >= N)
            res = -1;
        cout << res << "\n";       
    }
}