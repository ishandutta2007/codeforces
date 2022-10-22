#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 200005;
const int Maxl = 26;

int n;
string a, b;
ll all;
ll l[Maxn][Maxl], r[Maxn][Maxl];
ld res;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> a >> b;
    for (int i = 1; i <= n; i++) all += ll(i) * ll(i);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < Maxl; j++) {
            l[i][j] = l[i + 1][j];
            r[i][j] = r[i + 1][j];
        }
        l[i][a[i] - 'A'] += n - i;
        r[i][b[i] - 'A'] += n - i;
    }
    for (int i = 0; i < n; i++)
        res += ld(i + 1) * ld(r[i][a[i] - 'A'] + l[i + 1][b[i] - 'A']) / ld(all);
    cout << fixed << setprecision(9) << res << endl;
    return 0;
}