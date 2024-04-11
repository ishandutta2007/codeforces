#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;

int T;
int n;
int a[Maxn];
int b[Maxn];
vector <ii> res, res2;
int hasA[Maxn], hasB[Maxn];

void Reverse(int l, int r)
{
    res.push_back(ii(l, r));
    while (l < r) {
        swap(a[l], a[r]);
        l++; r--;
    }
}

void reverseB(int l, int r)
{
    res2.push_back(ii(l, r));
    while (l < r) {
        swap(b[l], b[r]);
        l++; r--;
    }
}

bool oneStep(int ind)
{
    for (int i = 0; i <= n; i++)
        hasA[i] = hasB[i] = 0;
    for (int i = ind + 2; i <= n; i++) {
        if (a[i] == a[ind]) hasA[a[i - 1]] = i;
        if (b[i] == b[ind]) hasB[b[i - 1]] = i;
    }
    for (int i = 0; i <= n; i++)
        if (hasA[i] && hasB[i]) {
            Reverse(ind, hasA[i]);
            reverseB(ind, hasB[i]);
            return true;
        }
    if (hasA[b[ind + 1]]) {
        Reverse(ind, hasA[b[ind + 1]]);
        return true;
    }
    if (hasB[a[ind + 1]]) {
        reverseB(ind, hasB[a[ind + 1]]);
        return true;
    }
    return false;
}

bool Solve()
{
    res.clear(); res2.clear();
    if (a[1] != b[1]) return false;
    for (int i = 1; i < n; i++)
        if (a[i + 1] != b[i + 1])
            if (!oneStep(i)) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        if (Solve()) {
            printf("YES\n");
            printf("%d\n", int(res.size()) + int(res2.size()));
            for (int i = 0; i < res.size(); i++)
                printf("%d %d\n", res[i].first, res[i].second);
            for (int i = int(res2.size()) - 1; i >= 0; i--)
                printf("%d %d\n", res2[i].first, res2[i].second);
        } else printf("NO\n");
    }
    return 0;
}