#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <set>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 1005;

int n, m;
int freq[3];
pii ans[MAXN][MAXN];
int sze[MAXN], num[MAXN], am[MAXN];
set<pii> st;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            char c1, c2;
            cin >> c1 >> c2;
            int a = c1 - '0', b = c2 - '0';
            if (!a && !b) freq[0] ++;
            else if (a && b) freq[2] ++;
            else freq[1] ++;
        }

    for (int i=0; i<m; i++) st.insert(pii(0, i));

    for (int i=0; i<freq[0]; i++) {
        pii p = *st.begin();
        st.erase(p);
        ans[sze[p.se]++][p.se] = pii(0, 0);
        am[p.se] += 2;
        st.insert(pii(am[p.se], p.se));
    }

    for (int i=0; i<freq[1]; i++) {
        pii p = *st.begin();
        st.erase(p);
        ans[sze[p.se]++][p.se] = num[p.se] ? pii(0, 1) : pii(1, 0);
        num[p.se] ^= 1;
        am[p.se] ++;
        st.insert(pii(am[p.se], p.se));
    }

    for (int j=0; j<m; j++)
        for (int i=sze[j]; i<n; i++)
            ans[i][j] = pii(1, 1);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cout << ans[i][j].fi << ans[i][j].se << ' ';
        cout << '\n';
    }

    return 0;
}