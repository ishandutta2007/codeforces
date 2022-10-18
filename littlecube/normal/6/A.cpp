#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int s[4];
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    sort(s, s + 4);
    if (s[3] > s[1] + s[2] && s[2] > s[1] + s[0])
        cout << "IMPOSSIBLE\n";
    else if (s[3] < s[2] + s[1] || s[2] < s[1] + s[0])
         cout << "TRIANGLE\n";
    else
       cout << "SEGMENT\n";
}