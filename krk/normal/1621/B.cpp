#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
map <int, int> L;
map <int, int> R;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        L.clear(); R.clear();
        int best = -1, bcost = 0;
        for (int i = 0; i < n; i++) {
            int l, r, c; scanf("%d %d %d", &l, &r, &c);
            if (r - l + 1 > best || r - l + 1 == best && c < bcost) {
                best = r - l + 1;
                bcost = c;
            }
            if (L.count(l)) L[l] = min(L[l], c);
            else L[l] = c;
            if (R.count(r)) R[r] = min(R[r], c);
            else R[r] = c;
            int len = R.rbegin()->first - L.begin()->first + 1;
            int cand = R.rbegin()->second + L.begin()->second;
            if (len > best || len == best && cand < bcost) {
                best = len;
                bcost = cand;
            }
            printf("%d\n", bcost);
        }
    }
    return 0;
}