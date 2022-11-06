#include <bits/stdc++.h>

using namespace std;
int a[100000], b[100000];
int main()
{
    string s;
    cin >> s;
    if (s.size() % 2 != 0)
    {
        cout << "-1";
        return 0;
    }
    int r = 0, l = 0, u = 0, d = 0;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == 'U')
            u++;
        if (s[i] == 'D')
            d++;
        if (s[i] == 'R')
            r++;
        if (s[i] == 'L')
            l++;
    }

    cout << (abs(r - l) + abs(u - d)) / 2 ;
    return 0;
}