#include <bits/stdc++.h>

using namespace std;
int l[5], r[5], s[5], p[5];
int main()
{
    for (int i = 0; i < 4; i++)
        cin >> l[i] >> s[i] >> r[i] >> p[i];
    int a, b, c;
    for (int i = 0; i < 4; i++)
        if (p[i] == 1)
        {
            if (l[i] || r[i] || s[i])
            {
                cout << "YES";
                return 0;
            }
            a = (i+1)%4;
            if (l[a])
            {
                cout << "YES";
                return 0;
            }
            b = (i+2)%4;
            if (s[b])
            {
                cout << "YES";
                return 0;
            }
            c = (i+3)%4;
            if (r[c])
            {
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
    return 0;
}