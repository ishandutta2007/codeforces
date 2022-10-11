#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    reverse(s.begin(), s.end());
    int ans = (s.size() + 1) / 2 - (s.size() % 2);
    if (s.size() % 2 == 1)
        for (int i = 0; i < s.size() - 1; i++)
            if (s[i] == '1')
            {
                ans++;
                break;
            }
    cout << ans;
}