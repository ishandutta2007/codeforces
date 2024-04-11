#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 101010;

string s, srev;
int m;
string word;
int Z1[Maxn], Z2[Maxn];
int res;

void Z(const string &s, int Z[], int delta)
{
    int l = 0, r = 0;
    Z[0] = 0;
    for (int i = 1; i < s.length(); i++) {
        Z[i] = 0;
        if (i <= r) Z[i] = min(Z[i - l], r - i);
        while (i + Z[i] < s.length() && s[i + Z[i]] == s[Z[i]]) Z[i]++;
        if (Z[i]) { l = i; r = i + Z[i] - 1; }
    }
    for (int i = 0; i + delta < s.length(); i++) Z[i] = Z[i + delta];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> srev; s = srev; reverse(srev.begin(), srev.end());
    cin >> m;
    while (m--) {
        cin >> word;
        if (word.length() == 1) continue;
        Z(word + "#" + s, Z1, word.length() + 1);
        reverse(word.begin(), word.end());
        Z(word + "#" + srev, Z2, word.length() + 1);
        for (int i = 1; i < s.length(); i++) Z2[i] = max(Z2[i], Z2[i - 1]);
        int i;
        for (i = 0; i + word.length() <= s.length(); i++)
            if (word.length() - Z1[i] <= Z2[s.length() - i - word.length()]) break;
        res += i + word.length() <= s.length();
    }
    printf("%d\n", res);
    return 0;
}