#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <ios>
#include <cassert>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 100100;
const int BLOCK = 400;

int N, W;
pii V[maxn];
int na[maxn], nb[maxn];
int pa[maxn], pb[maxn];

vector<vector<pll> > L;
vector<int> vn, vx, vp;

bool del(pll p1, pll p2, pll p3) {
    return ld(p1.A - p2.A) / (p2.B - p1.B) >= ld(p1.A - p3.A) / (p3.B - p1.B);
}

void add(vector<pll>& v, pll p) {
    while (v.size() > 1 && del(v[v.size() - 2], v[v.size() - 1], p)) v.pop_back();
    v.push_back(p);
}

void init(int st) {
    L.clear();
    vn.clear();
    vx.clear();
    vp.clear();

    int nd = min(N, st + BLOCK);
    vn.resize(nd - st + 1);
    for (int i = st; i < nd; i++)
        vn[i - st] = V[i].B;
    vn[nd - st] = maxn - 1;
    sort(vn.begin(), vn.end());

    L.resize(vn.size(), vector<pll>());
    vx.resize(vn.size(), 0);
    vp.resize(vn.size(), 0);

    for (int i = maxn - 1; i >= 0; i--)
        pb[i] = nb[i] + (i == maxn - 1 ? 0 : pb[i + 1]);

    int p = 0;
    for (int i = 0; i < maxn; i++) {
        while (p < vn.size() && vn[p] < i) p++;
        add(L[p], pll(ll(i) * pb[i], i));
    }

    for (int i = st; i < nd; i++)
        nb[V[i].B]++;
}

ll val(pll p, int x) {
    return p.A + p.B * x;
}

ll av[maxn];
int ap[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    int mb = 0;
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> V[i].B >> V[i].A;
        mb = max(mb, V[i].A);
        na[V[i].A]++;
        V[i].A++;
    }

    sort(V, V + N);
    
    for (int i = 0; i < N; i++) {
        //cout << i << endl;
        if (i % BLOCK == 0) {
            init(i);
        }

        ll mv = 0;
        int mp = 0;
        for (int j = 0; j < vn.size(); j++) {
            if (vn[j] > V[i].B) break;
            vx[j]++;
            while (vp[j] + 1 < L[j].size() && val(L[j][vp[j]], vx[j]) <= val(L[j][vp[j] + 1], vx[j])) vp[j]++;
        }

        for (int j = 0; j < vn.size(); j++)
            if (!L[j].empty()) {
                //cout << L[j][vp[j]].A << ' ' << L[j][vp[j]].B << ' ' << vx[j] << endl;
                ll v = val(L[j][vp[j]], vx[j]);
                if (v > mv)
                    mv = v, mp = L[j][vp[j]].B;
            }

        av[V[i].A] = mv, ap[V[i].A] = mp;
        //cout << V[i].A << ' ' << av[V[i].A] << ' ' << ap[V[i].A] << endl;
    }

    for (int i = 1; i <= mb + 1; i++)
        if (av[i - 1] > av[i])
            av[i] = av[i - 1], ap[i] = ap[i - 1];

    for (int i = maxn - 1; i >= 0; i--)
        pa[i] = na[i] + (i == maxn - 1 ? 0 : pa[i + 1]);

    for (int i = 0; i <= mb + 1; i++)
        cout << av[i] + ll(W) * pa[i] * i << ' ' << ap[i] << '\n';
}