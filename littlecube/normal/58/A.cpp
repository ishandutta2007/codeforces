#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    string s1, s2 = "hello";
    cin >> s1;
    for (int i = 0, j = 0; i < s1.length(); i++)
    {
        if (s1[i] == s2[j])
            j++;
        if (j >= 5)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}