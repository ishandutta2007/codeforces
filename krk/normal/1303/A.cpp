#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--) {
        cin >> s;
        int l = 0;
        while (l < s.length() && s[l] != '1') l++;
        if (l >= s.length()) printf("0\n");
        else {
            int r = int(s.length()) - 1;
            while (s[r] != '1') r--;
            int res = 0;
            for (int i = l; i <= r; i++)
                if (s[i] == '0') res++;
            printf("%d\n", res);
        }
    }
    return 0;
}