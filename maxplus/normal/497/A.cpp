#include <iostream>
#define N 100

using namespace std;

string s[N];
int n, m, ans;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int c = 0; c < m; ++c)
    {
        for (int i = 1; i < n; ++i)
            if (s[i].substr(0, c + 1) < s[i - 1].substr(0, c + 1))
            {
                for (int i = 0; i < n; ++i)
                    s[i] = s[i].substr(0, c) + s[i].substr(c + 1, s[i].size());
                --m, --c, ++ans;
                break;
            }
    }
    cout << ans;
    return 0;
}