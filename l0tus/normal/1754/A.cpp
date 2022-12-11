#include <bits/stdc++.h>

using namespace std;

using str = string;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)

#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        str s;
        cin >> s;
        int num = 0;
        F0R(i, n)
        {
            if (s[i] == 'Q')
                num++;
            else
                num = max(0, num - 1);
        }
        if (num > 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}