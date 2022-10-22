#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
ii A[Maxn];
int q;
vector <ii> S;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i].first);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int typ, a, b; scanf("%d %d", &typ, &a);
        if (typ == 1) {
            scanf("%d", &b);
            A[a] = ii(b, i);
        } else {
            ii my = ii(a, i);
            while (!S.empty() && S.back().first <= my.first)
                S.pop_back();
            S.push_back(my);
        }
    }
    for (int i = 1; i <= n; i++) {
        int lef = 0, rig = int(S.size()) - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (A[i].second < S[mid].second) rig = mid - 1;
            else lef = mid + 1;
        }
        int res = rig + 1;
        if (res >= S.size() || A[i].first >= S[res].first) ;
        else A[i].first = S[res].first;
        printf("%d%c", A[i].first, i + 1 <= n? ' ': '\n');
    }
    return 0;
}