#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int nil = Maxn;
const int Maxm = 2 * nil + 5;
const int Maxk = 105;

int n;
int a[Maxn];
int cnt[Maxk];
int res;
vector <int> my[Maxk];
int all[Maxk];
int M[Maxk][Maxm];

void Add(const ii &key, int val, bool ok)
{
    if (M[key.first][key.second] == -1)
        M[key.first][key.second] = val;
    else if (ok) res = max(res, val - M[key.first][key.second]);
}

void Clear(int a, int b) { M[a][b] = -1; }

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        int best = 0, bi, bcnt = 0;
        for (int j = 1; j < Maxk; j++) {
            if (cnt[j] > best) {
                best = cnt[j];
                bcnt = 0;
            }
            if (cnt[j] == best) {
                bi = j;
                bcnt++;
            }
        }
        if (bcnt > 1) res = max(res, i);
        else my[bi].push_back(i);
    }
    fill((int*)M, (int*)M + Maxk * Maxm, -1);
    for (int j = 1; j < Maxk; j++) {
        fill(all, all + Maxk, nil);
        for (int l = 1; l < Maxk; l++) if (j != l) {
            all[l] = nil;
            M[l][all[l]] = 0;
        }
        int pnt = 0;
        for (int i = 1; i <= n && pnt < my[j].size(); i++) {
            bool ok = my[j][pnt] == i;
            if (ok) pnt++;
            if (a[i] == j) {
                for (int l = 1; l < Maxk; l++) if (j != l) {
                    all[l]++;
                    Add(ii(l, all[l]), i, ok);
                }
            } else if (ok) {
                for (int l = 1; l < Maxk; l++) if (j != l) {
                    if (l == a[i]) all[l]--;
                    Add(ii(l, all[l]), i, ok);
                } 
            } else {
                all[a[i]]--;
                Add(ii(a[i], all[a[i]]), i, ok);
            }
        }
        for (int l = 1; l < Maxk; l++) if (j != l) {
            all[l] = nil;
            Clear(l, all[l]);
        }
        pnt = 0;
        for (int i = 1; i <= n && pnt < my[j].size(); i++) {
            if (my[j][pnt] == i) pnt++;
            if (a[i] == j) {
                for (int l = 1; l < Maxk; l++) if (j != l) {
                    all[l]++;
                    Clear(l, all[l]);
                }
            } else {
                all[a[i]]--;
                Clear(a[i], all[a[i]]);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}