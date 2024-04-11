#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;

const int max_n = 100008;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    char cur = 'a';
    for (int i = 0; i < s.length(); i++)
    {
        ans += min(abs(s[i] - cur), 26 - abs(s[i] - cur));
        cur = s[i];
    }
    cout << ans;
    return 0;
}