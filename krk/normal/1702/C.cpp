#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int T;
int n, k;
map <int, ii> M;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        M.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (M.find(a) == M.end())
                M.insert(make_pair(a, ii(i, i)));
            else M[a].second = i;
        }
        while (k--) {
            int a, b; scanf("%d %d", &a, &b);
            auto ita = M.find(a);
            auto itb = M.find(b);
            if (ita == M.end() || itb == M.end() || ita->second.first > itb->second.second)
                printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}