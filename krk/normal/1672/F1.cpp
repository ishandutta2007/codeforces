#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
vector <int> inds[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            inds[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            inds[a[i]].push_back(i);
        }
        set <int> S;
        for (int i = 1; i <= n; i++)
            S.insert(i);
        for (int i = 0; !S.empty(); i++) {
            int fir = -1, lst = -1;
            for (auto it = S.begin(); it != S.end(); )
                if (i >= inds[*it].size()) S.erase(it++);
                else {
                    int ind = inds[*it][i];
                    res[ind] = a[lst];
                    if (fir == -1) fir = ind;
                    lst = ind;
                    it++;
                }
            if (fir != -1) res[fir] = a[lst];
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}