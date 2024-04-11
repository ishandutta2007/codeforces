#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)

#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

const int MN = (int)2e5 + 5;

int cnt[MN << 2];
int main()
{
    FAST_IO;
    int n, x;
    cin >> n >> x;
    F0R(i, n)
    {
        int num;
        cin >> num;
        cnt[num]++;
    }
    FOR(i, 1, x)
    {
        if (cnt[i] % (i + 1))
        {
            cout << "No\n";
            return 0;
        }
        cnt[i + 1] += cnt[i] / (i + 1);
    }
    cout << "Yes\n";
}