#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;

bool T1()
{
    for (int i = 0; i < n; i++)
        if (s[i] >= s[n + i]) return false;
    return true;
}

bool T2()
{
    for (int i = 0; i < n; i++)
        if (s[i] <= s[n + i]) return false;
    return true;
}

int main()
{
    cin >> n >> s;
    sort(s.begin(), s.begin() + n); sort(s.begin() + n, s.end());
    if (T1() || T2()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}