// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, q, a[N], s[N], d[N], t, ps[N], sf[N], pr[N], L[N], R[N], sm[N][2], so[N][2];

char g[N];

set<int> st;

int main() {
    read(n), read(q);
    scanf("%s", g + 1);
    for (int i = 1; i <= n; i++) a[i] = g[i] - '0';
    for (int i = 2; i < n; i++) {
        if (a[i] != a[i - 1] && a[i] != a[i + 1]) {
            st.insert(i);
            d[++t] = i;
            ps[i] = t;
            R[i] = L[i] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!L[i]) L[i] = L[i - 1];
    }
    for (int i = n; i; i--) {
        if (!R[i]) R[i] = R[i + 1];
    }
    d[t + 1] = n + 1;
    for (int i = 0; i <= t; i++) {
        int A = d[i], B = d[i + 1];
        int c[2] = { 0, 0 };
        for (int j = A + 1; j < B; j++) {
            if (j > A + 1 && a[j] == a[j - 1]) 
                c[a[j]]++;
            sf[j] = max(c[0], c[1]);
         //   cout << A << " " << B << "??" << j << "?" << sf[j] << endl;
        }
        c[0] = c[1] = 0;
        for (int j = B - 1; j > A; j--) {
            if (j < B - 1 && a[j] == a[j + 1]) 
                c[a[j]]++;
            pr[j] = max(c[0], c[1]);
        //    cout << A << " " << B <<"??" << j << " " << pr[j] << endl;
        }
    }
    for (int i = 1; i <= t; i++) s[i] += s[i - 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++)
            so[i][j] = so[i - 1][j], sm[i][j] = sm[i - 1][j];
        so[i][a[i]]++;
        if (i == 1 || a[i] != a[i - 1]) sm[i][a[i]]++;
    }
    while (q--) {
    	int l, r; read(l), read(r);
        int x = R[l], y = L[r];
        int c[2] = { 0, 0 };
        if (1) {
            for (int i = 0; i < 2; i++) {
                c[i] = so[r][i] - so[l - 1][i];
                c[i] -= sm[r][i] - sm[l][i];
                if (a[l] == i) c[i]--;
            }
            printf("%d\n", max(c[0], c[1]) + 1);
        } else {
            int ans = s[ps[y]] - s[ps[x]] + 1;
            if (x > l) ans += pr[l];
            if (y < r) ans += sf[r];
            printf("%d\n", ans);
        }
    }
    return 0;
}