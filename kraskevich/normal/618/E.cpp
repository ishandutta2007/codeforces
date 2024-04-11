#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = (int)2e6;
const double M_PI = acos(-1);


double to_rad(double a) {
    return a / 180.0 * M_PI;
}

double make_norm(double a) {
    return fmod(a, 2 * M_PI);
}

struct Node {
    double len;
    double alpha;
    double last_alpha;
    
    Node(double len = 1.0, double a = 0.0, double l_a = 0.0): len(len), alpha(a), last_alpha(l_a) {}
    
    Node unite(const Node& rhs) const {
        double res_x = len * cos(alpha) + rhs.len * cos(last_alpha + rhs.alpha);
        double res_y = len * sin(alpha) + rhs.len * sin(last_alpha + rhs.alpha);
        double res_len = sqrt(res_x * res_x + res_y * res_y);
        double res_alpha = atan2(res_y, res_x);
        double res_last_alpha = make_norm(last_alpha + rhs.last_alpha);
        return Node(res_len, res_alpha, res_last_alpha);
    }
};

Node tree[N];

Node unite(const Node& l, const Node& r) {
    return l.unite(r);
}

void build(int i, int l, int r) {
    if (l == r)
        return;
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = unite(tree[2 * i + 1], tree[2 * i + 2]);
}

void upd(int i, int tl, int tr, int pos, double d_a, double d_len) {
    if (tl == tr) {
        tree[i].len += d_len;
        tree[i].alpha = make_norm(tree[i].alpha + d_a);
        tree[i].last_alpha = tree[i].alpha;
        //cerr << tl << " " << tr << " " << tree[i].len << " " << tree[i].alpha << " " << tree[i].last_alpha << " " << endl;
        return;
    }
    int m = (tl + tr) / 2;
    if (pos <= m)
        upd(2 * i + 1, tl, m, pos, d_a, d_len);
    else
        upd(2 * i + 2, m + 1, tr, pos, d_a, d_len);
    tree[i] = unite(tree[2 * i + 1], tree[2 * i + 2]);
    //cerr << tl << " " << tr << " " << tree[i].len << " " << tree[i].alpha << " " << tree[i].last_alpha << " " << endl;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    build(0, 0, n - 1);
    while (q--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        y--;
        if (x == 1) {
            upd(0, 0, n - 1, y, 0.0, z);
        } else {
            upd(0, 0, n - 1, y, -to_rad(z), 0.0);
        }
        double xx = tree[0].len * cos(tree[0].alpha);
        double yy = tree[0].len * sin(tree[0].alpha);
        printf("%.10lf %.10lf\n", xx, yy);
    }
}