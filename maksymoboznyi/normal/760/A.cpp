#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> k >> n;
    if (k == 1 || k == 3 || k == 5 || k == 7 || k == 8 || k == 10 || k == 12)
        k = 31;
    else
        if (k == 2)
            k = 28;
        else
            k = 30;
    int ans = 1;
    k -= (7 - n + 1);
    ans += (k-1)/ 7 + 1;
    cout << ans;
    return 0;
}