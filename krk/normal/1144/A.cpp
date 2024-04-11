#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int freq[Maxl];
int n;
string s;

int main()
{
    cin >> n;
    while (n--) {
        cin >> s;
        fill(freq, freq + Maxl, 0);
        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;
        int cnt = 0, mn = Maxl, mx = -Maxl;
        bool ok = true;
        for (int i = 0; i < Maxl; i++)
            if (freq[i] > 0) {
                cnt++;
                mn = min(mn, i);
                mx = i;
                if (freq[i] > 1) ok = false;
            }
        printf("%s\n", ok && mx - mn + 1 == cnt? "Yes": "No");
    }
    return 0;
}