#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, q;
const int maxN = 2 * (int)1e5 + 10;
struct node{
    int state[4][4];
    node(){
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                state[i][j] = 0;
            }
        }
    }
};
char s[maxN];
node t[4 * maxN];
string k216 = "2016";
const int INF = (int)1e9;
node merge(const node& a, const node& b) {
    node c;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c.state[i][j] = INF;
        }
    }
    for (int st = 0; st < 4; st++) {
        for (int en = st; en < 4; en++) {
            for (int bet = st; bet <= en; bet++) {
                c.state[st][en] = min(c.state[st][en], a.state[st][bet] + b.state[bet][en]);
            }
        }
    }
    return c;
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        for (int i = 0; i < 4; i++) {
            for (int j = i; j < 4; j++) {
                if (j > i + 1) {
                    t[v].state[i][j] = INF;
                }
                else if (j == i) {
                    t[v].state[i][j] = (k216[i] == s[tl]);
                }
                else {
                    if (k216[i] == s[tl]) t[v].state[i][j] = 0;
                    else t[v].state[i][j] = INF;
                }
            }
        }
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = merge(t[v + v], t[v + v + 1]);
}
int before[maxN];
int pref6[maxN];
node get(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(v + v, tl, tm, l, r);
    else if (l > tm) return get(v + v + 1, tm + 1, tr, l, r);
    else return merge(get(v + v, tl, tm, l, tm), get(v + v + 1, tm + 1, tr, tm + 1, r));
}
int main() {
    srand(1488);
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        pref6[i] = pref6[i - 1] + (s[i] == '6');
    }
    before[0] = 0;
    for (int i = 1; i <= n; i++) {
        before[i] = before[i - 1];
        if (s[i] == '7') before[i] = i;
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        int x = before[b];
        if (x < a) {
            cout << -1 << '\n';
            continue;
        }
        int ans = pref6[b] - pref6[x - 1];
        node c = get(1, 1, n, a, x);
        ans += c.state[0][3];
        /*for (int ii = 0; ii < 5; ii++) {
            for (int jj = 0; jj < 5; jj++) {
                cout << c.state[ii][jj  ] << " ";
            }
            cout << '\n';
        }*/
        if (ans > n) {
            cout << -1 << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }
    return 0;
}