#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n;
int a[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    ll twos = 0;
    for (int i = n - 1; i >= 0; i--) {
        twos += a[i] / 2;
        if (a[i] % 2 == 1 && twos > 0) {
            res++; twos--;
        }
    }
    res += 2 * (twos / 3);
    twos %= 3;
    if (twos == 2) res++;
    cout << res << endl;
    return 0;
}