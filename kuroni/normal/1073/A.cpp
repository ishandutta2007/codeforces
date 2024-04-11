#include <iostream>
#include <cstdio>
using namespace std;

int n;
string s;

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++)
        if (s[i] != s[i + 1])
        {
            cout << "YES\n" << s[i] << s[i + 1];
            return 0;
        }
    cout << "NO\n";
}