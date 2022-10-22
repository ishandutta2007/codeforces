#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;
const int Maxn = 200005;

int q;
int n;
char A[Maxn], B[Maxn];
int freqA[Maxl], freqB[Maxl];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        scanf("%s", A);
        scanf("%s", B);
        fill(freqA, freqA + Maxl, 0);
        fill(freqB, freqB + Maxl, 0);
        for (int i = 0; i < n; i++)
            freqA[A[i] - 'a']++;
        for (int i = 0; i < n; i++)
            freqB[B[i] - 'a']++;
        bool ok = true, was2 = false;
        for (int i = 0; i < Maxl; i++) {
            if (freqA[i] != freqB[i]) ok = false;
            if (freqA[i] > 1) was2 = true;
        }
        if (!ok) printf("NO\n");
        else if (was2) printf("YES\n");
        else {
            int revs = 0;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    revs += int(A[i] > A[j]) + int(B[i] > B[j]);
            printf("%s\n", revs % 2 == 0? "YES": "NO");
        }
    }
    return 0;
}