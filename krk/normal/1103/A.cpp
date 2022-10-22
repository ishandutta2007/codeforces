#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    int cur1 = 0, cur2 = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0') {
            printf("2 %d\n", cur1 + 1);
            cur1 = (cur1 + 1) % 4;
        } else {
            printf("4 %d\n", cur2 + 1);
            cur2 = (cur2 + 2) % 4;
        }
    return 0;
}