#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    vector<string> p;
    string s;
    int m = 0, n = 0;
    while (getline(cin, s))
    {
        if (cin.eof())
            break;
        m = max(m, (int)s.length());
        p.emplace_back(s);
    }
    cout << string(m + 2, '*') << '\n';
    for (auto i : p)
    {
        if (i.length() % 2 != m % 2)
            n++;
        if (n % 2)
            cout << '*' << string((m - i.length()) / 2, ' ') << i << string((m - i.length() + 1) / 2, ' ') << '*' << '\n';
        else
            cout << '*' << string((m - i.length() + 1) / 2, ' ') << i << string((m - i.length()) / 2, ' ') << '*' << '\n';
    }
    cout << string(m + 2, '*') << '\n';
}