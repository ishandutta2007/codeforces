#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, kol[3][3], k[3];
string s;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
            s[i] = 0;
        if (s[i] == 'R')
            s[i] = 1;
        if (s[i] == 'G')
            s[i] = 2;
    }
    int ans = 0;
    for (int i = 1; i < s.size(); i++)
    if (s[i] == s[i - 1])
    {
        for (int v = 0; v < 3; v++)
            if (s[i - 1] != v && (s.size() -1 == i || v != s[i + 1]))
            {
                s[i] = v;
                ans++;
                break;
            }
    }
    cout << ans << endl;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 0)
            cout << 'B';
        if (s[i] == 1)
            cout << 'R';
        if (s[i] == 2)
            cout << 'G';
    }
    return 0;
}