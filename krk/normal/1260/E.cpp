#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1 << 18;

int n;
int a[Maxn];
priority_queue <ii> Q;
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int pnt = n;
    int sub = n;
    while (pnt > 0) {
        pnt--; sub /= 2;
        if (a[pnt] == -1) { printf("%I64d\n", res); return 0; }
        Q.push(ii(-a[pnt], pnt));
        res += -Q.top().first; Q.pop();
        for (int i = 0; i < sub - 1; i++) {
            pnt--;
            if (a[pnt] == -1) { printf("%I64d\n", res); return 0; }
            Q.push(ii(-a[pnt], pnt));
        }
    }
    return 0;
}