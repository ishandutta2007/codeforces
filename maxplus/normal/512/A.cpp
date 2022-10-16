#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

bool p[256][256];
int am[256];
queue<char> ans;
bool u[256];

void out()
{
    cout << "Impossible";
    exit(0);
}

int main()
{
    int n;
    string s, s2;
    cin >> n;
    cin >> s;
    while (--n)
    {
        cin >> s2;
        int i = 0;
        while (i < min(s.size(), s2.size()) && s[i] == s2[i])   i++;
        if (i == s2.size())
            out();
        if (i != s.size())
            if (!p[s2[i]][s[i]])
                p[s2[i]][s[i]] = 1, am[s2[i]]++;
        s = s2;
    }
    for (int i = 'a'; i <= 'z'; ++i)
    {
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (!u[i] && !am[i])
            {
                ans.push(i);
                u[i] = 1;
                for (int j = 'a'; j <= 'z'; ++j)
                    if (p[j][i])
                        p[j][i] = 0, am[j]--;
                goto end_cyc;
            }
        }
        out();
        end_cyc:;
    }
    while (!ans.empty())
    {
        cout << ans.front();
        ans.pop();
    }
    return 0;
}