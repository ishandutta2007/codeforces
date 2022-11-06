#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const long long inf = 2e18;
const int N = 1e5+5;

bool is(char c)
{
    return (c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'o');
}

int main()
{

    string s;
    cin >> s;
    for (int i = 0; i+1 < s.size(); i++)
        if (s[i] != 'n')
        {
            if (!is(s[i]) && !is(s[i+1]))
            {
                cout << "No";
                return 0;
            }
        }
    if (s[s.size()-1] != 'n' && !is(s[s.size()-1]))
    {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}