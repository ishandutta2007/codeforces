#include <iostream>
#include <cstdio>
using namespace std;

int t, n;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        int ans = n - 1;
        for (int i = 0; i < n; i++)
            if (s[i] == '>')
            {
                ans = i;
                break;
            }
        for (int i = n - 1; i >= 0; i--)
            if (s[i] == '<')
            {
                ans = min(ans, n - 1 - i);
                break;
            }
        cout << ans << '\n';
    }
}