#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
string s;
bool ok[Maxn];
int res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    cin >> n;
    cin >> s;
    ok[0] = true;
    for (int i = 0; i < n && ok[0]; i++)
        ok[0] = s[i] == '0';
    for (int i = 1; i <= n; i++) if (n % i == 0) {
        ok[i] = true;
        for (int j = 0; j < i && ok[i]; j++) {
            int my = 0;
            for (int k = j; k < n; k += i)
                my += s[k] - '0';
            ok[i] = my % 2 == 0;
        }
    }
    res = ok[0];
    for (int i = 1; i < n; i++)
        res += ok[gcd(i, n)];
    printf("%d\n", res);
    return 0;
}