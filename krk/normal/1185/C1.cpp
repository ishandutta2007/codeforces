#include <bits/stdc++.h>
using namespace std;

const int Maxm = 105;

int n, M;
int freq[Maxm];
int sum;

int main()
{
    scanf("%d %d", &n, &M);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        sum += a;
        int res = 0;
        if (sum > M) {
            int nd = sum - M;
            for (int j = Maxm - 1; j > 0 && nd > 0; j--) {
                int tk = min((nd - 1) / j + 1, freq[j]);
                res += tk; nd -= tk * j;
            }
        }
        printf("%d%c", res, i + 1 < n? ' ': '\n');
        freq[a]++;
    }
    return 0;
}