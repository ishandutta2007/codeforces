#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)

#define rep(a) F0R(_, a)

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
        int k = n / 2;
        int num = (n - 1) % k + 1;
        rep(n)
        {
            cout << num << ' ';
            num += k;
            if (num > n)
                num = (num - 2) % k + 1;
        }
        cout << '\n';
    }
}