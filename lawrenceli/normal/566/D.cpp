#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int maxn = 200100;

int n, q;
int par[maxn], nxt[maxn];
bool used[maxn];

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
void merge(int a, int b) { par[getpar(a)] = getpar(b); }

int getnxt(int a) { return nxt[a] == a ? a : nxt[a] = getnxt(nxt[a]); }
void mergen(int a) { nxt[getnxt(a)] = getnxt(a+1); }

int main() {
    scanf("%d %d", &n, &q);
    for (int i=1; i<=n+1; i++) par[i] = nxt[i] = i;

    for (int i=0; i<q; i++) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        if (t == 1) merge(x, y);
        else if (t == 2) {
            int cur = x;
            while (cur <= y) {
                merge(cur, x);
                if (cur<y) {
                    merge(cur+1, x);
                    if (!used[cur]) mergen(cur);
                    used[cur] = 1;
                } else break;
                    
                cur = getnxt(cur);
            }
        } else {
            if (getpar(x) == getpar(y)) printf("YES\n");
            else printf("NO\n");
        }
    }
}