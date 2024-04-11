#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] %= 2;
    }
    vector <int> S;
    for (int i = 0; i < n; i++)
        if (S.empty() || S.back() != a[i])
            S.push_back(a[i]);
        else S.pop_back();
    if (S.size() > 1) printf("NO\n");
    else printf("YES\n");
    return 0;
}