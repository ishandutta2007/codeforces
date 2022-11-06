#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 100 + 5;

int pref[N], suff[N], ans[N], dps[N], dpp[N];
string s;
int del[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cin >> s;
    for (char c = 'z'; c >= 'a'; c--) {
        for (int i = 0; i < s.size(); i++)
            del[i] = 0;
        for (int j = 1; j < s.size(); j++)
        if (s[j] == c){
            int cur = j;
            while (cur >= 0 && s[cur] == s[j])
                cur--;
            if (cur >= 0 && s[j] - 1 == s[cur])
                del[j] = 1;
        }
        for (int j = int(s.size()) - 2; j >= 0; j--)
        if (s[j] == c){
            int cur = j;
            while (cur < s.size() && s[cur] == s[j])
                cur++;
            if (cur < s.size() && s[j] - 1 == s[cur])
                del[j] = 1;
        }
        string t = "";
        for (int i = 0; i < s.size(); i++)
            if (!del[i])
                t += s[i];
        s = t;
    }
    cout << n - s.size();
    return 0;
}