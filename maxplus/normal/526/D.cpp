#include <iostream>
#include <string>

using namespace std;

int n, k, op[1000001], z[1000001], cop;
string s;

void z_func()
{
    int l = 0, r = 1;
    z[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        z[i] = min(z[i - l], max(r - i, 0));
        while (z[i] + i < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (z[i] + i > r)
            r = z[i] + i, l = i;
    }
}

int main()
{
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cin >> s;
    z_func();
    for (int l = 1; l <= n; ++l)
    {
        int pos = 0;
        for (int am = 0; am < k && (pos += l) <= n; ++am)
        {
            if (am == k - 1)
                op[pos - 1]++, op[pos + min(z[pos], l)]--;
            if (z[pos] < l)
                break;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cop += op[i];
        cout << !!cop;
    }
    return 0;
}