#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

string s;
int ans = 0, i;
bool check[105];

int main()
{
    memset(check, 0, sizeof(check));
    cin >> s;
    for (i = 0; i < s.size() - 1; i++)
        if (s[i] == 'V' && s[i + 1] == 'K')
    {
        ans++;
        check[i] = check[i + 1] = 1;
    }
    for (i = 0; i < s.size() - 1; i++)
        if (!check[i] && s[i + 1] == 'K')
    {
        cout << ans + 1;
        return 0;
    }
    for (i = 1; i < s.size(); i++)
        if (!check[i] && s[i - 1] == 'V')
    {
        cout << ans + 1;
        return 0;
    }
    cout << ans;
}