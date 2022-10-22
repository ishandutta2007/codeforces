#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 32;
const int Maxm = 1024;

int n, k;
int B[Maxn][Maxn];
ii my[Maxm];

int main()
{
    vector <int> seq;
    seq.push_back(0);
    for (int i = 0; i < 5; i++) {
        vector <int> seq2 = seq;
        reverse(seq2.begin(), seq2.end());
        for (int j = 0; j < seq2.size(); j++)
            seq.push_back(seq2[j] | 1 << i);
    }
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < Maxn; j++) {
            for (int l = 0; l < 10; l++)
                B[i][j] |= bool((l % 2? seq[j]: seq[i]) & 1 << (l / 2)) << l;
            my[B[i][j]] = ii(i, j);
        }
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            printf("%d%c", (B[i][j] ^ B[i][j + 1]), j + 1 < n - 1? ' ': '\n');
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", (B[i][j] ^ B[i + 1][j]), j + 1 < n? ' ': '\n');
    fflush(stdout);
    int cur = 0;
    for (int i = 0; i < k; i++) {
        int num; scanf("%d", &num);
        cur ^= num;
        printf("%d %d\n", my[cur].first + 1, my[cur].second + 1);
        fflush(stdout);
    }
    return 0;
}