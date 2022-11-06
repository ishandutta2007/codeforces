#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
const int N = 1e5;

string s;

bool iss(char x)
{
    return (x == 'a' || x == 'e' || x == 'u' || x == 'o' || x == 'i');
}

int main()
{
    cin >> s;
    bool is = true;
    if (s.size() < 3)
    {
        cout << s;
        return 0;
    }
    ll kol = 0;
    cout << s[0] << s[1];
    if (!iss(s[1]))
        if (!iss(s[0]))
        {
            is = (s[1] == s[0]);
            kol = 2;
        }
        else
            kol = 1;
    for (int i = 2; i < s.size(); i++)
    {
        if (!iss(s[i]))
            if (kol >= 2)
                if (s[i] == s[i-1] && s[i-1] == s[i-2])
                {
                    cout << s[i];
                    kol++;
                }
                else
                {
                    cout << ' ' << s[i];
                    kol = 1;
                }
            else
            {
                kol++;
                cout << s[i];
            }
        else
        {
            kol = 0;
            cout << s[i];
        }
    }
    return 0;
}