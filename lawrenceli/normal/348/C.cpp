#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100100;
const int MAXSQ = 500;

int n, m, q, d, e;
ll ar[MAXN], sum[MAXN], add[MAXN];
vector<int> s[MAXN];
int big[MAXSQ], rev[MAXN], cnt;
int inter[MAXSQ][MAXN];
bool in[MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &q);
    d = sqrt(n); e = sqrt(q);
    for (int i=0; i<n; i++) scanf("%I64d", &ar[i]);
    memset(rev, -1, sizeof(rev));
    for (int i=0; i<m; i++) {
        int k; scanf("%d", &k);
        s[i].resize(k);
        for (int j=0; j<k; j++) {
            scanf("%d", &s[i][j]);
            s[i][j]--;
            sum[i] += ar[s[i][j]];
        }
        if (k > d) big[cnt] = i, rev[i] = cnt, cnt++;
    }

    for (int i=0; i<cnt; i++) {
        memset(in, 0, sizeof(in));
        int x = big[i];
        for (int j=0; j<s[x].size(); j++)
            in[s[x][j]] = 1;
        for (int j=0; j<m; j++)
            for (int k=0; k<s[j].size(); k++)
                if (in[s[j][k]])
                    inter[i][j]++;
    }

    scanf("\n");
    for (int i=0, j; i<q; i=j) {
        vector<pii> v1, v2;
        for (j=i; j<q && j/e == i/e; j++) {
            char type; scanf("%c", &type);
            if (type == '?') {
                int ind;
                scanf("%d\n", &ind);
                ind--;
                if (rev[ind] != -1) {
                    ll ans = sum[ind];
                    for (int k=0; k<v1.size(); k++)
                        ans += ll(inter[rev[ind]][v1[k].fi])*v1[k].se;
                    printf("%I64d\n", ans);
                } else {
                    ll ans = 0;
                    for (int k=0; k<s[ind].size(); k++)
                        ans += ar[s[ind][k]];
                    for (int k=0; k<v2.size(); k++)
                        ans += ll(inter[rev[v2[k].fi]][ind])*v2[k].se;
                    printf("%I64d\n", ans);
                }
            } else {
                int ind, x;
                scanf("%d %d\n", &ind, &x);
                ind--;
                v1.push_back(pii(ind, x));
                if (rev[ind] != -1) {
                    v2.push_back(pii(ind, x));
                } else {
                    for (int k=0; k<s[ind].size(); k++)
                        ar[s[ind][k]] += x;
                }
            }
        }
        memset(add, 0, sizeof(add));
        for (int k=0; k<v2.size(); k++)
            add[v2[k].fi] += v2[k].se;
        for (int k=0; k<cnt; k++) {
            int x = big[k];
            for (int i1=0; i1<s[x].size(); i1++)
                ar[s[x][i1]] += add[x];
        }

        for (int k=0; k<m; k++) {
            sum[k] = 0;
            for (int i1=0; i1<s[k].size(); i1++)
                sum[k] += ar[s[k][i1]];
        }
    }
    return 0;
}