#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 5;
const int Maxs = 32;
const int Maxk = 4000000;
const int Inf = 2000000007;

struct arr {
    int el[Maxm];
    int len;
    arr(): len(0) {}
    bool operator<(const arr &u) const {
        if (len != u.len) return len < u.len;
        for (int i = 0; i < len; i++)
            if (el[i] != u.el[i]) return el[i] < u.el[i];
        return false;
    }
};

map <arr, int> M;
int n, m;
int a[Maxn][Maxm], w[Maxn];
ii my[Maxn][Maxs];
int mlen[Maxn];
vector <ii> seq;
int has[Maxk];
int res = Inf;

int getId(const arr &key)
{
    int val = M.size();
    auto it = M.insert(make_pair(key, val));
    if (it.second) return val;
    else return it.first->second;
}

int Get(int v)
{
    int res = 0;
    for (int i = 0; i < mlen[v]; i++)
        res += has[my[v][i].first] * my[v][i].second;
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
        sort(a[i], a[i] + m);
        for (int j = 0; j < 1 << m; j++) {
            arr A;
            int add = 1;
            for (int k = 0; k < m; k++) if (j & 1 << k) {
                A.el[A.len++] = a[i][k];
                add = -add;
            }
            my[i][mlen[i]++] = ii(getId(A), add);
        }
        scanf("%d", &w[i]);
        seq.push_back(ii(w[i], i));
    }
    sort(seq.begin(), seq.end());
    int ind = 0;
    while (ind < seq.size()) {
        int v = seq[ind].second;
        for (int i = 0; i < mlen[v]; i++)
            has[my[v][i].first]++;
        if (Get(v) > 0) break;
        ind++;
    }
    int pnt = ind;
    while (ind < seq.size()) {
        int v = seq[ind].second;
        while (Get(v) > 0) {
            res = min(res, w[v] + seq[pnt].first);
            int u = seq[pnt].second;
            for (int i = 0; i < mlen[u]; i++)
                has[my[u][i].first]--;
            pnt--;
        }
        ind++;
    }
    printf("%d\n", res >= Inf? -1: res);
    return 0;
}