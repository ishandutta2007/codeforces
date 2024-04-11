#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1005;
const int Maxk = 7;

int k, n;
ii tp[Maxk];
ii p[Maxn];
int nxt[Maxk][Maxn];
bool tk[Maxk];
int seq[Maxk], slen;
int res;

ii Sub(const ii &a, const ii &b) { return ii(a.first - b.first, a.second - b.second); }

ll Cross(const ii &a, const ii &b) { return ll(a.first) * b.second - ll(a.second) * b.first; }

ll Dot(const ii &a, const ii &b) { return ll(a.first) * b.first + ll(a.second) * b.second; }

ll Len(const ii &a) { return ll(a.first) * a.first + ll(a.second) * a.second; }

bool canAdd(int x)
{
    for (int i = 0; i < slen; i++)
        if (seq[i] == x) return false;
    return true;
}

bool canAddAll(int i, int j)
{
    while (nxt[i][j] != -1) {
        if (canAdd(nxt[i][j])) {
            if (slen >= k) return false;
            seq[slen++] = nxt[i][j];
        }
        j = nxt[i][j];
    }
    return true;
}

bool Check(int lvl)
{
    if (slen <= lvl) return true;
    int lim = slen;
    for (int i = 0; i < k; i++) if (!tk[i]) {
        slen = lim;
        tk[i] = true;
        if (canAddAll(i, seq[lvl]))
            if (Check(lvl + 1)) return true;
        tk[i] = false;
    }
    return false;
}

int main()
{
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++)
        scanf("%d %d", &tp[i].first, &tp[i].second);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i].first, &p[i].second);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++) {
            nxt[i][j] = -1;
            ll len = 0;
            for (int l = 0; l < n; l++) if (l != j) {
                ii A = Sub(tp[i], p[l]), B = Sub(p[j], p[l]);
                if (Cross(A, B) == 0 && Dot(A, B) < 0) {
                    ll cand = Len(A);
                    if (cand > len) {
                        len = cand;
                        nxt[i][j] = l;
                    }
                }
            }
        }
    for (int i = 0; i < n; i++) {
        slen = 0;
        seq[slen++] = i;
        fill(tk, tk + k, false);
        if (Check(0)) res++;
    }
    cout << res << endl;
    return 0;
}