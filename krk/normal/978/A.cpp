#include <bits/stdc++.h>
using namespace std;

const int Maxm = 10005;

bool was[Maxm];
int n;
int a[Maxm];
vector <int> res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; i--) {
        if (!was[a[i]]) res.push_back(a[i]);
        was[a[i]] = true;
    }
    reverse(res.begin(), res.end());
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}