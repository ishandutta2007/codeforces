#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string c, s, t;
bool chk[26];
int n, i, j = -1;

int main()
{
    memset(chk, 0, sizeof(chk));
    ios_base::sync_with_stdio(); cin.tie(); cout.tie();
    cin >> c >> t >> n;
    for (i = 0; i < c.size(); i++)
        chk[c[i] - 'a'] = true;
    for (i = 0; i < t.size(); i++)
        if (t[i] == '*')
        {
            j = i;
            break;
        }
    while (n--)
    {
        bool cur = true;
        cin >> s;
        if (j == -1)
        {
            if (t.size() != s.size())
                cur = false;
            if (cur)
                for (i = 0; i < t.size(); i++)
                    if (!(s[i] == t[i] || (t[i] == '?' && chk[s[i] - 'a'])))
                    {
                        cur = false;
                        break;
                    }
        }
        else
        {
            if (s.size() < t.size() - 1)
                cur = false;
            for (i = 0; i < j; i++)
                if (!(s[i] == t[i] || (t[i] == '?' && chk[s[i] - 'a'])))
                {
                    cur = false;
                    break;
                }
            for (i = t.size() - 1; i > j; i--)
                if (s.empty() || !(s.back() == t[i] || (t[i] == '?' && chk[s.back() - 'a'])))
                {
                    cur = false;
                    break;
                }
                else s.pop_back();
            for (i = j; i < s.size(); i++)
                if (chk[s[i] - 'a'])
                {
                    cur = false;
                    break;
                }
        }
        if (!cur)
            cout << "NO\n";
        else cout << "YES\n";
    }
}