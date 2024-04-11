#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int k1, k2, k3;
int n;
int a[Maxn];

void Read(int k, int col)
{
    for (int i = 0; i < k; i++) {
        int x; scanf("%d", &x);
        a[x] = col;
    }
}

int main()
{
    scanf("%d %d %d", &k1, &k2, &k3);
    n = k1 + k2 + k3;
    Read(k1, 1);
    Read(k2, 2);
    Read(k3, 3);
    vector <int> res;
    for (int i = 1; i <= n; i++) {
        int ind = upper_bound(res.begin(), res.end(), a[i]) - res.begin();
        if (ind < res.size()) res[ind] = a[i];
        else res.push_back(a[i]);
    }
    printf("%d\n", n - int(res.size()));
    return 0;
}