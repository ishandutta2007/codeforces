#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    string s;
    ll result = 0;
    int left = 0,
        right = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'Q')
            right++;

    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'A')
            result += left * right;
        else if (s[i] == 'Q')
        {
            left++;
            right--;
        }
    cout << result;
}