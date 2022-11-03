#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int a[1111];
int d[1111][333];
int rt[1111][1111];
int nxt[1111];
int lst[9];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);   
    int mxk = (n + 7) / 8 + 31;
    mxk = min(mxk, n);
    
    memset(rt, -1, sizeof(int) * 1111 * 1111);
    memset(nxt, -1, sizeof(nxt));
    memset(lst, -1, sizeof(lst));
    
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        rt[i][1] = i + 1;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        int x = a[i];
        if (lst[x] != -1) {
            nxt[i] = lst[x];
        }
        lst[x] = i;
    }
    
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        if (lst[i] != -1) {
            ans++;
        }
    }
    
    for (int k = 2; k <= mxk; k++) {
        for (int i = 0; i < n; i++) {
            if (nxt[i] != -1) {
                rt[i][k] = rt[nxt[i]][k - 1];
            }
        }
    }
    
    for (int k = 2; k <= mxk; k++) {
        memset(d, -1, sizeof(int) * 1111 * 333);
        d[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int msk = 0; msk < (1 << 8); msk++) {
                if (d[i][msk] == -1) {
                    continue;
                }
                d[i + 1][msk] = max(d[i + 1][msk], d[i][msk]);
                int x = a[i] - 1;
                if ((msk >> x) & 1) {
                    continue;
                }
                if (rt[i][k] != -1) {
                    d[rt[i][k]][msk | (1 << x)] = max(d[rt[i][k]][msk | (1 << x)], d[i][msk] + k);
                }
                if (rt[i][k - 1] != -1) {
                    d[rt[i][k - 1]][msk | (1 << x)] = max(d[rt[i][k - 1]][msk | (1 << x)], d[i][msk] + k - 1);
                }
            }
        }
        ans = max(ans, d[n][(1 << 8) - 1]);
    }
    
    cout << ans;
    

    return 0;
}