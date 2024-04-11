#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }
    vector <int> S;
    for (int i = 0; i < n; i++)
        if (a[i] == mx) {
            if (!S.empty()) { printf("NO\n"); return 0; }
        } else if (!S.empty() && S.back() < a[i]) { printf("NO\n"); return 0; }
          else if (!S.empty() && S.back() == a[i]) S.pop_back();
          else S.push_back(a[i]);
    if (!S.empty()) printf("NO\n");
    else printf("YES\n");
    return 0;
}