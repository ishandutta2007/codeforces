#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < 95)
            s[i] += 32;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
            s[i] = 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != 0)
            cout << '.' << s[i];
    }
    cout << '\n';
}