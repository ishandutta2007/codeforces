#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111;

int main()
{
    int m, d;
    cin >> m >> d;
    int kd = 31;
    if (m == 2) kd = 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) kd = 30;
    int ans = 1;
    kd -= (7 - d + 1);
    ans += (kd / 7);
    if (kd % 7) ans++;
    cout << ans;
}