#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 300100;

int n, m, ans[MAXN];
set<int> st;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) st.insert(i);
    for (int i=0; i<m; i++) {
        int l, r, x; scanf("%d %d %d", &l, &r, &x);
        typeof(st.begin()) it = st.lower_bound(l);
        while (it != st.end() && *it <= r) {
            if (*it != x) {
                ans[*it] = x;
                typeof(st.begin()) it2 = it; it2++;
                st.erase(it);
                it = it2;
            } else it++;
        }
    }
    for (int i=1; i<=n; i++) printf("%d ", ans[i]);
    return 0;
}