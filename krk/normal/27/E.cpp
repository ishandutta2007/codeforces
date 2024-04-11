#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000005LL;
const int Maxn = 1005;

int n;
ll res[Maxn];
ll ans;

bool Least()
{
     for (int i = 1; i < n; i++)
         if (res[i] < ans) return false;
     return true;
}

bool Prime(int x)
{
     if (x == 2) return true;
     if (x % 2 == 0) return false;
     for (int i = 3; i * i <= x; i += 2)
         if (x % i == 0) return false;
     return true;
}

int main()
{
    cin >> n;
    fill(res, res + n + 1, Inf);
    res[1] = 1;
    ans = res[n];
    for (int i = 2; !Least(); i++) if (Prime(i)) {
        for (int j = n; j >= 0; j--) {
            ll pw = i;
            for (int l = 2; j * l <= n && res[j] <= Inf / pw; l++, pw *= i)
                res[j * l] = min(res[j * l], res[j] * pw);
            res[j] = Inf;
        }
        ans = min(ans, res[n]);
    }
    if (n == 1) ans = 1;
    cout << ans << endl;
    return 0;
}