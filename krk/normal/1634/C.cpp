#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        vector <int> ev, od;
        for (int i = 1; i <= n * k; i++)
            if (i % 2) od.push_back(i);
            else ev.push_back(i);
        if (od.size() % k) { printf("NO\n"); continue; }
        printf("YES\n");
        while (!od.empty() || !ev.empty()) {
            if (od.empty()) { od = ev; ev.clear(); }
            for (int j = 0; j < k; j++) {
                printf("%d%c", od.back(), j + 1 < k? ' ': '\n');
                od.pop_back();
            }
        }
    }
    return 0;
}