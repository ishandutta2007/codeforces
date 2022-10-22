#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int T;
int freq[Maxl];
string s;

int main()
{
    scanf("%d", &T);
    while (T--) {
        cin >> s;
        fill(freq, freq + Maxl, 0);
        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;
        string A, B;
        for (int i = 0; i < Maxl; i++)
            if (freq[i] == 1) A += string(1, 'a' + i);
            else if (freq[i] == 2) B += string(1, 'a' + i);
        A += B + B;
        cout << A << "\n";
    }
    return 0;
}