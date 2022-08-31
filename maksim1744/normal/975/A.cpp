#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

string root(string s)
{
    vector< bool > has(26, false);
    for (int i = 0; i < s.length(); ++i)
    {
        has[s[i] - 'a'] = true;
    }
    string ans = "";
    for (int i = 0; i < 26; ++i)
    {
        if (has[i]) {
            ans += 'a' + i;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t = 2;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        int n;
        cin >> n;
        string s;
        vector< string > v;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            v.push_back(root(s));
        }
        sort(v.begin(), v.end());
        int ans = 1;
        for (int i = 1; i < v.size(); ++i)
        {
            if (v[i] != v[i - 1]) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    fclose(stdout);
    return 0;
}