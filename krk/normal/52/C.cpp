#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200000;
const ll Inf = 10000000000000000LL;

struct vertex {
       vertex *lc, *rc;
       ll lmin, rmin, lf, rf;
} tree;

int n, a[Maxn], m;

void Create(vertex &v, int l, int r)
{
     if (l == r) {
           v.lmin = v.rmin = a[l];
           v.lf = v.rf = 0;
     } else {
            int mid = (l + r) / 2;
            v.lc = new vertex; Create(*(v.lc), l, mid); v.lmin = min(v.lc->lmin, v.lc->rmin);
            v.rc = new vertex; Create(*(v.rc), mid+1, r); v.rmin = min(v.rc->lmin, v.rc->rmin);
            v.lf = v.rf = 0;
     }
}

ll Minim(vertex &v, int l, int r, int a, int b, ll toadd)
{
    if (l == a && r == b) return min(v.lmin, v.rmin) + toadd;
    else {
         int mid = (l + r) / 2;
         ll mn = 10000000000000000LL;
         if (a <= mid) mn = min(mn, Minim(*(v.lc), l, mid, a, min(b, mid), toadd+v.lf));
         if (b > mid) mn = min(mn, Minim(*(v.rc), mid+1, r, max(a, mid+1), b, toadd+v.rf));
         return mn;
    }
}

void Add(vertex &v, int l, int r, int a, int b, ll cor, ll toadd)
{
     if (l == a && r == b) {
           v.lmin += cor+toadd; v.rmin += cor+toadd;
           v.lf += cor+toadd; v.rf += cor+toadd;
     } else {
            int mid = (l + r) / 2;
            if (a <= mid) {
                  Add(*(v.lc), l, mid, a, min(b, mid), cor+v.lf, toadd);
                  v.lmin = min(v.lc->lmin, v.lc->rmin);
                  v.lf = 0;
            } else {
                   v.lmin += cor;
                   v.lf += cor;
            }
            if (b > mid) {
                  Add(*(v.rc), mid+1, r, max(a, mid+1), b, cor+v.rf, toadd);
                  v.rmin = min(v.rc->lmin, v.rc->rmin);
                  v.rf = 0;
            } else {
                   v.rmin += cor;
                   v.rf += cor;
            }
     }
}

int main()
{
    int i, lf, rg, v;
    string s;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    Create(tree, 0, n-1);
    cin >> m; getline(cin, s);
    for (i = 0; i < m; i++) {
        getline(cin, s);
        stringstream ss(s);
        ss >> lf >> rg;
        if (ss >> v) if (lf > rg) {
                        Add(tree, 0, n-1, 0, rg, 0, v);
                        Add(tree, 0, n-1, lf, n-1, 0, v);
                     } else Add(tree, 0, n-1, lf, rg, 0, v);
        else if (lf > rg) 
                cout << min(Minim(tree, 0, n-1, 0, rg, 0), Minim(tree, 0, n-1, lf, n-1, 0)) << endl;
             else cout << Minim(tree, 0, n-1, lf, rg, 0) << endl;
    }
    return 0;
}