#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

char tmp[Maxn];
string S, T;
int freq[2];
int Z[Maxn];
int best;
char res[Maxn];
int rlen;

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

int main()
{
    Read(S);
    Read(T);
    for (int i = 0; i < S.length(); i++)
        freq[S[i] - '0']++;
    int l = -1, r = -1;
    for (int i = 1; i < T.length(); i++) {
        if (i <= r) Z[i] = min(r - i, Z[i - l]);
        while (i + Z[i] < T.length() && T[Z[i]] == T[i + Z[i]]) Z[i]++;
        if (i + Z[i] - 1 > r) {
            l = i, r = i + Z[i] - 1;
            if (i + Z[i] == T.length()) best = Z[i];
        }
    }
    int p = 0;
    while (rlen < S.length())
        if (freq[T[p] - '0'] > 0) {
            res[rlen++] = T[p];
            freq[T[p] - '0']--;
            if (++p == T.length()) p = best;
        } else if (freq[0] > 0) {
            res[rlen++] = '0';
            freq[0]--;
        } else {
            res[rlen++] = '1';
            freq[1]--;
        }
    res[rlen] = '\0';
    printf("%s\n", res);
    return 0;
}