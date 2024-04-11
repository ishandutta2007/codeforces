#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int T;
string s;
int freq[Maxl];

int main()
{
    scanf("%d", &T);
    while (T--) {
        cin >> s;
        fill(freq, freq + Maxl, 0);
        for (int i = 0, j; i < s.length(); i = j) {
            j = i;
            while (j < s.length() && s[i] == s[j]) j++;
            if ((j - i) % 2) freq[s[i] - 'a']++;
        }
        for (int i = 0; i < Maxl; i++) if (freq[i] > 0)
            printf("%c", i + 'a');
        printf("\n");
    }
    return 0;
}