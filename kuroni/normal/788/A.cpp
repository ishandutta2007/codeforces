#include <iostream>
#include <stdio.h>

using namespace std;

long long n, i, cur, save, diff[100005], min_f[100005], max_f[100005], res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> save;
    for (i = 1; i < n; i++)
    {
        cin >> cur;
        diff[i] = abs(cur - save);
        save = cur;
    }
    min_f[1] = max_f[1] = res = diff[1];
    for (i = 2; i < n; i++)
    {
        min_f[i] = min(diff[i], diff[i] - max_f[i - 1]);
        max_f[i] = max(diff[i], diff[i] - min_f[i - 1]);
        res = max(res, max_f[i]);
    }
    cout << res;
}