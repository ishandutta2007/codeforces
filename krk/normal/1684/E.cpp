#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, k;
int a[Maxn];
map <int, int> M;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        M.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            M[a]++;
        }
        int dif = M.size();
        multiset <int> S;
        int siz = 0;
        int res = 1000000000;
        for (int i = n; i > 0; i--) {
            while (!M.empty()) {
                auto it = M.end(); it--;
                if (it->first >= i) {
                    S.insert(it->second);
                    siz += it->second;
                    M.erase(it);
                    while (siz > k) {
                        auto it = S.end(); it--;
                        siz -= *it; S.erase(it);
                    }
                } else break;
            }
            if (i - int(M.size()) <= k)
                res = min(res, dif - int(M.size()) - int(S.size()));
        }
        res = min(res, max(1, dif - int(S.size())));
        printf("%d\n", res);
    }
    return 0;
}