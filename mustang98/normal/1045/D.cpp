#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

const int sz = 300;

vector<int> v[max_n];
int n, q;
double p[max_n];
vector<pair<int, double>> qr;
double sum_to[max_n];
double cv = 0, ce = 0;
double pr[max_n];

void rebuild() {
    cv = ce = 0;
    for (int i = 0; i < n; ++i) {
        cv += p[i];
        sum_to[i] = 0;
        for (int to : v[i]) {
            sum_to[i] += p[to];
        }
        ce += sum_to[i] * p[i];
        pr[i] = p[i];
    }
}

int have[max_n];

int P[max_n];

void dfs(int cur, int pp) {
    P[cur] = pp;
    for (int to : v[cur]) {
        if (to != pp) {
            dfs(to, cur);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", p + i);
        p[i] = 1 - p[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].PB(b);
        v[b].PB(a);
    }
    dfs(0, -1);
    scanf("%d", &q);
    int qind = 0;
    for (int i = 0; i < q; ++i) {
        int ver;
        double np;
        scanf("%d%lf", &ver, &np);
        np = 1 - np;
        qr.push_back(MP(ver, np));
    }
    int V = 0;
    for (int i = 0; i < q; ++i) {
        if (i % sz == 0) {
            rebuild();
        }
        int ver = qr[i].F;
        double np = qr[i].S;
        double st = sum_to[ver];
        ++V;
        for (int j = i - 1; j >= 0 && j / sz == i / sz; --j) {
            int to = qr[j].F;
            if ((P[ver] == to || P[to] == ver) && have[to] != V) {
                have[to] = V;
                st -= pr[to];
                st += p[to];
            }
        }
        cv -= p[ver];
        ce -= st * p[ver] * 2;
        p[ver] = np;
        cv += p[ver];
        ce += st * p[ver] * 2;
        printf("%.10f\n", cv - ce / 2);
    }
    return 0;
}