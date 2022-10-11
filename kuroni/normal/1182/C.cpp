#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
const string S = "aeiou";

int n, dic[26];
string u, sa[MX][5];
vector<pair<string, string>> fi, se;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 5; i++)
        dic[S[i] - 'a'] = i;
    while (n--)
    {
        cin >> u;
        int cnt = 0, lst = 0;
        for (char &c : u)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                cnt++;
                lst = dic[c - 'a'];
            }
        if (sa[cnt][lst] == "")
            sa[cnt][lst] = u;
        else
        {
            se.emplace_back(sa[cnt][lst], u);
            sa[cnt][lst] = "";
        }
    }
    for (int i = 1; i < MX; i++)
    {
        string cur = "";
        for (int j = 0; j < 5; j++)
            if (sa[i][j] != "")
            {
                if (cur == "")
                    cur = sa[i][j];
                else
                {
                    fi.emplace_back(sa[i][j], cur);
                    cur = "";
                }
            }
    }
    int sf = fi.size(), ss = se.size();
    int m = min(sf, ss) + max(0, (ss - sf) / 2);
    cout << m << '\n';
    while (!fi.empty() && !se.empty())
    {
        pair<string, string> u = fi.back(), v = se.back();
        fi.pop_back(); se.pop_back();
        cout << u.first << " " << v.first << '\n' << u.second << " " << v.second << '\n';
    }
    while (se.size() >= 2)
    {
        pair<string, string> u = se.back();
        se.pop_back();
        pair<string, string> v = se.back();
        se.pop_back();
        cout << u.first << " " << v.first << '\n' << u.second << " " << v.second << '\n';
    }
}