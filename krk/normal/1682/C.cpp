#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
vector <int> un, cnt;
int L[Maxn], R[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        un.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            un.push_back(a[i]);
        }
        sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
        cnt.clear();
        cnt.resize(un.size(), 0);
        for (int i = 0; i < n; i++) {
            int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
            cnt[ind]++;
        }
        L[0] = 0;
        for (int i = 0; i < un.size(); i++)
            L[i + 1] = L[i] + min(2, cnt[i]);
        R[int(un.size()) + 1] = 0;
        for (int i = int(un.size()) - 1; i >= 0; i--)
            R[i + 1] = R[i + 2] + min(2, cnt[i]);
        int res = R[1] / 2;
        for (int i = 0; i < un.size(); i++)
            res = max(res, 1 + (L[i] + R[i + 2]) / 2);
        printf("%d\n", res);
    }
    return 0;
}