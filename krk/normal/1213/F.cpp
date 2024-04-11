#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, k;
int P[Maxn];
int Q[Maxn], inQ[Maxn];
vector <ii> seq;
int res[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &P[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &Q[i]);
        inQ[Q[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        ii cur = ii(i, inQ[P[i]]);
        while (!seq.empty() && inQ[P[i]] < seq.back().second) {
            cur.second = max(cur.second, seq.back().second);
            cur.first = seq.back().first;
            seq.pop_back();
        }
        seq.push_back(cur);
    }
    if (seq.size() < k) { printf("NO\n"); return 0; }
    printf("YES\n");
    int pnt = 0;
    for (int i = 1; i <= n; i++) {
        if (pnt < seq.size() && seq[pnt].first == i) pnt++;
        res[P[i]] = pnt - 1;
    }
    for (int i = 1; i <= n; i++) {
        res[i] = min(res[i], 25);
        printf("%c", res[i] + 'a');
    }
    printf("\n");
    return 0;
}