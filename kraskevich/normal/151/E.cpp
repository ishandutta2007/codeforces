#include <iostream>
#include <stdlib.h>
using namespace std;

#define double long double

double add[3 * 100 * 1000];

const double inf = 1e18;

double max(double a, double b, double c, double d) {
       return max(max(a, b), max(c, d));
}

struct rmq {
       int l, r;
       double pref, suf, all, best;
       rmq *left, *right;
};

rmq* build(int l, int r) {
     rmq* root = (rmq*)malloc(sizeof(rmq));
     root->l = l;
     root->r = r;
     if(l == r) {
          root->left = root->right = NULL;
          root->suf = max((double)0, add[l]);
          root->pref = root->suf;
          root->all = add[l];
          root->best = root->suf;
     }
     else {
          root->left = build(l, (l + r) / 2);
          root->right = build((l + r) / 2 + 1, r);
          root->all = root->left->all + root->right->all;
          root->pref = max(root->left->pref, root->left->all + root->right->pref);
          root->suf = max(root->right->suf, root->left->suf + root->right->all);
          root->best = max(root->left->best, root->right->best, root->left->suf + root->right->pref, root->all);
     }
     return root;
}

void get(int l, int r, rmq* root, double &pref, double &suf, double &all, double &best) {
     if(root->l == l && root->r == r) {
                pref = root->pref;
                suf = root->suf;
                all = root->all;
                best = root->best;
                return;
     }
     double prefL = -inf, prefR = -inf, sufL = -inf, sufR = - inf, allL = -inf, allR = -inf, bestL = -inf, bestR = -inf;
     if(root->left && root->left->r >= l)
                   get(l, min(r, root->left->r), root->left, prefL, sufL, allL, bestL);
     if(root->right && root->right->l <= r)
                    get(max(root->right->l, l), r, root->right, prefR, sufR, allR, bestR);
     pref = max(prefL, allL + prefR);
     suf = max(sufR, allR + sufL);
     all = allL + allR;
     best = max(bestL, bestR, prefR + sufL, all);
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(10);
    int n, m, c;
    cin >> n >> m >> c;
    long long x[n];
    for(int i = 0; i < n; ++i) 
            cin >> x[i];
    double p[n];
    for(int i = 1; i < n; ++i) { 
            cin >> p[i];
            p[i] /= 100.0;
    }
    add[0] = 0;
    for(int i = 1; i < n; ++i)
            add[i] = 0.5 * (x[i] - x[i - 1]) - c * p[i];
    rmq* root = build(0, n - 1);
    double res = 0;
    double best, all, suf, pref;
    for(int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --b;
            get(a, b, root, pref, suf, all, best);
            res += best;
    }
    cout << res;
    cin >> n;
    return 0;
}