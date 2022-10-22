#include <bits/stdc++.h>
using namespace std;

const int Maxd = 10;

int T;
char S[Maxd + 1];

int Solve(char a, char b)
{
    int lfta = 5, lftb = 5;
    int scorea = 0, scoreb = 0;
    for (int i = 0; i < Maxd; i++) {
        if (i % 2 == 0) {
            scorea += S[i] == '1' || S[i] == '?' && a == '1';
            lfta--;
        } else {
            scoreb += S[i] == '1' || S[i] == '?' && b == '1';
            lftb--;
        }
        if (scorea > scoreb + lftb || scorea + lfta < scoreb) return i + 1;
    }
    return Maxd;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", S);
        printf("%d\n", min(Solve('0', '1'), Solve('1', '0')));
    }
    return 0;
}