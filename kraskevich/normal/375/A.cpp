#include <bits/stdc++.h>

using namespace std;


int calc(string s)
{
    int mod = 0;
    for (char c : s)
        mod = mod * 10 + (c - '0') % 7, mod %= 7;
    return mod;
}

int calc(vector<int> v)
{
    int mod = 0;
    for (int c : v)
        mod = mod * 10 + c % 7, mod %= 7;
    return mod;
}

int main()
{
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(10, 0);
    for (auto c : s)
        cnt[c - '0']++;
    string res;
    cnt[1]--;
    cnt[6]--;
    cnt[8]--;
    cnt[9]--;
    for (int i = 1; i < 10; i++)
        for (int rep = 0; rep < cnt[i]; rep++)
            res += char('0' + i);
    int mod = calc(res);
    mod *= 10000;
    mod %= 7;
    int want = (7 - mod) % 7;
    vector<int> v = {1, 6, 8, 9};
    vector<int> rs;
    int c = calc(v);
    if (c == want)
        rs = v;
    while (next_permutation(v.begin(), v.end()))
    {
        c = calc(v);
        if (c == want)
            rs = v;
    }
    if (!rs.size())
    {
        cout << 0;
        return 0;
    }

    cout << res;
    for (int x : rs)
        cout << x;
    for (int i = 0; i < cnt[0]; i++)
        cout << 0;


    return 0;
}