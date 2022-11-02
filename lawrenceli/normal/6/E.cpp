#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100010;

int n, k;
int h[MAXN];
int lo, hi, best;
set<pii> st;
pii ans[MAXN];
int cnt;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &h[i]);
    if (n==1) {
        printf("1 1\n1 1\n");
        return 0;
    }
    hi = 1; st.insert(pii(h[0], 0));
    while (hi < n) {
        while (hi < n && st.rbegin()->first - st.begin()->first <= k) {
            st.insert(pii(h[hi], hi)); hi++;
        }
        if (st.rbegin()->first - st.begin()->first <= k) best = max(best, hi - lo);
        else best = max(best, hi - lo - 1);
        while (st.rbegin()->first - st.begin()->first > k) {
            st.erase(pii(h[lo], lo)); lo++;
        }
        if (st.rbegin()->first - st.begin()->first <= k) best = max(best, hi - lo);
    }
    st.clear();
    lo = 0; hi = 1; st.insert(pii(h[0], 0));
    while (hi < n) {
        while (hi < n && st.rbegin()->first - st.begin()->first <= k) {
            st.insert(pii(h[hi], hi)); hi++;
        }
        int len;
        if (st.rbegin()->first - st.begin()->first <= k) {
            len = hi - lo;
            if (len == best && (cnt == 0 || lo != ans[cnt-1].first)) ans[cnt++] = pii(lo, lo + len - 1);
        }
        else {
            len = hi - lo - 1;
            if (len == best && (cnt == 0 || lo != ans[cnt-1].first)) ans[cnt++] = pii(lo, lo + len - 1);
        }
        while (st.rbegin()->first - st.begin()->first > k) {
            st.erase(pii(h[lo], lo)); lo++;
        }
        len = hi - lo;
        if (len == best && (cnt == 0 || lo != ans[cnt-1].first)) {
            ans[cnt++] = pii(lo, lo + len - 1);
        }
    }
    printf("%d %d\n", best, cnt);
    for (int i=0; i<cnt; i++) printf("%d %d\n", ans[i].first+1, ans[i].second+1);
}