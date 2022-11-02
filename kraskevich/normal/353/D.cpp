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
        int pos = 0;
        int boys = 0;
        int wait = 0;
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'M')
            {
                boys++;
                continue;
            }
            if (pos == i)
            {
                pos++;
                continue;
            }
            wait = max(0, wait - boys + 1);
            t = i - pos + wait;
            pos++;
            boys = 0;
        }
        cout << t;


    return 0;
}