#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
vector <int> res1, res2, res3;

void Apply(int i, int j, int k)
{
    int got = (a[i] ^ a[j] ^ a[k]);
    a[i] = a[j] = a[k] = got;
    res1.push_back(i + 1);
    res2.push_back(j + 1);
    res3.push_back(k + 1);
}

void Solve(int ind)
{
    if (ind + 1 == n) return;
    Apply(ind, ind + 1, ind + 2);
    Solve(ind + 2);
    Apply(ind, ind + 1, ind + 2);
}

int main()
{
    scanf("%d", &n);
    int xr = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        xr ^= a[i];
    }
    if (n % 2 == 0 && xr != 0) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    if (n % 2 == 0) n--;
    Solve(0);
    printf("%d\n", int(res1.size()));
    for (int i = 0; i < res1.size(); i++)
        printf("%d %d %d\n", res1[i], res2[i], res3[i]);
    return 0;
}