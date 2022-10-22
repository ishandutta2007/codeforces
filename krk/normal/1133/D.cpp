#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int a[Maxn], b[Maxn];
map <ii, int> M;
int any = 0;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (a[i] == 0) {
            if (b[i] == 0) any++;
        } else {
            if (a[i] < 0) { a[i] = -a[i]; b[i] = -b[i]; }
            int g = gcd(abs(a[i]), abs(b[i]));
            M[ii(a[i] / g, b[i] / g)]++;
        }
    }
    int res = 0;
    for (map <ii, int>::iterator it = M.begin(); it != M.end(); it++)
        res = max(res, it->second);
    res += any;
    cout << res << endl;
    return 0;
}