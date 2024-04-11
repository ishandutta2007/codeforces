#include <iostream>
#include <cstdio>
using namespace std;

int n, cnt = 0;
string s;

int main()
{
    cin >> n >> s;
    for (int i = 0; i <= n - 11; i++)
        cnt += (s[i] == '8');
    if (cnt > (n - 11) / 2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}