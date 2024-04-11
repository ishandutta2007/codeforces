#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

map<string, int> account;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (account[s] == 0)
        {
            cout << "OK\n";
        }
        else
        {
            cout << s << account[s] << '\n';
        }
        account[s]++;
    }
}