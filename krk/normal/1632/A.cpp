#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        int zers = 0, ones = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '0') zers++;
            else ones++;
        if (ones >= 2 || zers >= 2) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}