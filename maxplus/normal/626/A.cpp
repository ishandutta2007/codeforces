#include <iostream>

using namespace std;

const int N = 202;
int r[N], c[N], ans, n;
char ch;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ch;
        r[i] = r[i - 1];
        c[i] = c[i - 1];
        if (ch == 'U')
            r[i]--;
        else if (ch == 'D')
            r[i]++;
        else if (ch == 'L')
            c[i]--;
        else
            c[i]++;
    }
    for (int i = 0; i <= n; ++i)
    for (int j = 0; j < i; ++j)
        if (r[i] == r[j] && c[i] == c[j])
            ans++;
    cout << ans;
    return 0;
}