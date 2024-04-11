#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    int n = s.length();
    if (n == 2)
    {
        cout << 1;
        return 0;
    }
    vector<int> p;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int b = (i + 1) % n;
        if (s[i] != s[b])
            p.push_back(i);
    }
    if (p.size() == 0)
    {
        cout << 1;
        return 0;
    }
        vector<int> pos = p;
        bool old = false;
        int st = pos[1] - pos[0];
        int t = 0;
        for (int i = 0; i < pos.size(); i++)
        {
            int to = pos[(i + 1) % pos.size()];
            int v = pos[i];
            if (to <= v)
                to += n;
            if (to - v == 1)
            {
                if (!old && (i != pos.size() - 1 || st == 1))
                {
                    old = true;
                    t++;
                }
                else
                {
                    old = false;
                }
            }
            else
            {
                if (!old)
                    t++;
                old = false;
            }
        }
        res = max(res, t);
    cout << res;


    return 0;
}