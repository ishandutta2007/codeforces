#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int T;
int n, k;
string s;
int freq[Maxl];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> s;
        fill(freq, freq + Maxl, 0);
        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;
        for (int i = n; i > 0; i--) {
            int tk = i / gcd(i, k);
            int nd = i / tk;
            for (int j = 0; j < Maxl; j++)
                nd -= freq[j] / tk;
            if (nd <= 0) { printf("%d\n", i); break; }
        }
    }
    return 0;
}