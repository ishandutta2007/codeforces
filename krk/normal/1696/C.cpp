#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, ll> ill;

const int Maxn = 500005;

int T;
int n, m;
int a[Maxn];
int k;
int b[Maxn];

vector <ill> Get(int a[], int n)
{
    vector <ill> res;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        ll cnt = 1;
        while (x % m == 0) {
            x /= m;
            cnt *= m;
        }
        if (res.empty() || res.back().first != x)
            res.push_back(ill(x, cnt));
        else res.back().second += cnt;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
            scanf("%d", &b[i]);
        if (Get(a, n) == Get(b, k))
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}