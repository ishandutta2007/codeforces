#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

const int Maxm = 1005;

int n, m, h;
int s[Maxm], sum;
ld res;

int main()
{
    cin >> n >> m >> h;
    for (int i = 1; i <= m; i++) {
        cin >> s[i]; sum += s[i];
    }
    if (sum < n) cout << "-1\n";
    else if (sum - s[h] < n - 1) cout << "1\n";
    else {
         res = 1;
         for (int i = 1; i < n; i++)
            res *= ld(sum - s[h] - i + 1) / ld(sum - i);
         res = 1 - res;
         cout << fixed << setprecision(17) << res << endl;
    }
    return 0;
}