#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n;
int a[Maxn];
ll spec, spec2;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i % 2 == 0) { spec += a[i] / 2, spec2 += (a[i] + 1) / 2; }
        else { spec += (a[i] + 1) / 2, spec2 += a[i] / 2; }
    }
    cout << min(spec, spec2) << endl;
    return 0;
}