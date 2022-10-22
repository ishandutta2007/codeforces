#include <bits/stdc++.h>
using namespace std;

const int Maxd = 3;

int T;
int seq[Maxd];

int main()
{
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < Maxd; i++)
            scanf("%d", &seq[i]);
        sort(seq, seq + Maxd);
        bool ans;
        if (seq[2] > seq[1]) ans = seq[0] + seq[1] == seq[2] || seq[0] == seq[1] && seq[2] % 2 == 0;
        else ans = seq[0] % 2 == 0;
        printf("%s\n", ans? "YES": "NO");
    }
    return 0;
}