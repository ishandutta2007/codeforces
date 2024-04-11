#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main()
{
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> s;
    n = s.length();
    vector<char> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(s[i]);
        while (v.size() >= 2 && v[v.size() - 1] == v[v.size() - 2])
        {
            v.pop_back();
            v.pop_back();
        }
    }
    if (v.size() == 0)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}