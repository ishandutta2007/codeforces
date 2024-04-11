#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    map<char, int> cnt;
    for (int i = 0; i < s.length(); i++)
        ++cnt[s[i]];
    string res;
    for (char c = '1'; c <= '3'; c++)
        for (int j = 0; j < cnt[c]; j++)
        {
            res += c;
            res += '+';
        }
    res.erase(res.length() - 1, 1);
    cout << res;

    return 0;
}