#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int n, m, k;
ii a[Maxn];
vector <int> seq;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }
    sort(a, a + n);
    ll res = 0;
    for (int i = 1; i <= m * k; i++) {
        res += a[n - i].first;
        seq.push_back(a[n - i].second);
    }
    printf("%I64d\n", res);
    sort(seq.begin(), seq.end());
    bool pr = false;
    for (int i = m - 1; i + 1 < seq.size(); i += m) {
        if (pr) printf(" ");
        else pr = true;
        printf("%d", seq[i]);
    }
    printf("\n");
    return 0;
}