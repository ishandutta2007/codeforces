#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, ans = 0, cur = 0, a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        cur = max(cur, a);
        if (cur == i)
            ans++;
    }
    cout << ans << '\n';
}