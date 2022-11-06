#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 5e5 + 5;

int n, lcp[N];
string s[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i < n; i++)
    {
        int cur = 0;
        while (cur + 1 < min(s[i].size(), s[i + 1].size()) && s[i][cur + 1] == s[i + 1][cur + 1])
            cur++;
        lcp[i] = cur;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (lcp[i] + 1 > s[i].size()) {
            continue;
        }
        if (lcp[i] + 1 == s[i].size()) {
            continue;
        }
        if (lcp[i] + 1 == s[i + 1].size()) {
            s[i].resize(lcp[i] + 1);
            continue;
        }
        if (s[i][lcp[i] + 1] > s[i + 1][lcp[i] + 1])
            s[i].resize(lcp[i] + 1);
    }
    for (int i = n - 1; i > 0; i--)
        if (s[i].size() > s[i + 1].size() && s[i + 1].size() <= lcp[i] + 1)
            s[i].resize(s[i + 1].size());
    for (int i = 1; i <= n; i++)
        cout << s[i] << "\n";
    return 0;
}