#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n, r;
vector <ii> pos, neg;

int main()
{
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (b >= 0) pos.push_back(ii(a, b));
        else neg.push_back(ii(a + b, -b));
    }
    sort(pos.begin(), pos.end());
    for (int i = 0; i < pos.size(); i++)
        if (r < pos[i].first) { printf("NO\n"); return 0; }
        else r += pos[i].second;
    int mn = 0;
    sort(neg.begin(), neg.end());
    for (int i = 0; i < neg.size(); i++) {
        if (mn < neg[i].first) mn = neg[i].first;
        mn += neg[i].second;
    }
    printf("%s\n", r >= mn? "YES": "NO");
    return 0;
}