#include <bits/stdc++.h>
using namespace std;

const int Maxm = 40004;
const int mod = 1000000007;

int ways[Maxm];

bool Palindromic(int n)
{
    stringstream ss; ss << n;
    string s; ss >> s;
    int lef = 0, rig = int(s.length()) - 1;
    while (lef < rig) {
        if (s[lef] != s[rig]) return false;
        lef++; rig--;
    }
    return true;
}

int main()
{
    ways[0] = 1;
    for (int i = 1; i < Maxm; i++)
        if (Palindromic(i))
            for (int j = 0; j + i < Maxm; j++)
                ways[j + i] = (ways[j + i] + ways[j]) % mod;
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        printf("%d\n", ways[n]);
    }
    return 0;
}