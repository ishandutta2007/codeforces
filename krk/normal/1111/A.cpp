#include <bits/stdc++.h>
using namespace std;

string vows = "aeiou";

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    if (s.size() != t.size()) { printf("No\n"); return 0; }
    for (int i = 0; i < s.length(); i++)
        if ((vows.find(s[i]) != string::npos) !=
            (vows.find(t[i]) != string::npos)) {
            printf("No\n"); return 0;
        }
    printf("Yes\n");
    return 0;
}