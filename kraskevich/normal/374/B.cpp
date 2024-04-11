#include <bits/stdc++.h>

using namespace std;

void foo()
{

}

int main()
{
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.length();
    long long res = 1;
    int old = -1;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = s[i] - '0';
        if (cur + old == 9)
            len++;
        if (cur + old != 9 || i == n - 1)
        {
            if (len > 1)
                res *= (len % 2 ? (len + 1) / 2 : 1);
            len = 1;
        }
        old = cur;
    }
    cout << res;

    return 0;
}