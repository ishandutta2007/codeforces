#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        int n; cin >> n;
        cin >> s;
        int ones = 0, zers = 0;
        for (int i = 1; i < n; i++)
            if (s[i - 1] == s[i])
                if (s[i] == '1') ones++;
                else zers++;
        printf("%d\n", max(ones, zers));
    }
    return 0;
}