#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

int T;
char A[Maxn];
char B[Maxn];
int alen, blen;
vector <int> inds[2][Maxl];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", A);
        scanf("%s", B);
        alen = strlen(A);
        blen = strlen(B);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < Maxl; j++)
                inds[i][j].clear();
        for (int i = 0; i < alen; i++) {
            int ind = A[i] - 'a';
            int f = (alen - 1 - i) % 2;
            inds[f][ind].push_back(i);
        }
        int cur = 0;
        int lst = alen;
        for (int i = blen - 1; i >= 0; i--) {
            int ind = B[i] - 'a';
            lst = lower_bound(inds[cur][ind].begin(), inds[cur][ind].end(), lst) - inds[cur][ind].begin() - 1;
            if (lst < 0) break;
            lst = inds[cur][ind][lst];
            cur = 1 - cur;
        }
        printf("%s\n", lst >= 0? "YES": "NO");
    }
    return 0;
}