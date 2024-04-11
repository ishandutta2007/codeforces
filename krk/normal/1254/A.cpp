#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int r, c, k;
char B[Maxn][Maxn];
char R[Maxn][Maxn];

char Get(int ind)
{
    if (ind < 26) return ind + 'a';
    if (ind < 52) return (ind - 26) + 'A';
    return (ind - 52) + '0';
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &r, &c, &k);
        int rice = 0;
        for (int i = 0; i < r; i++) {
            scanf("%s", B[i]);
            for (int j = 0; j < c; j++)
                rice += B[i][j] == 'R';
        }
        vector <int> seq;
        for (int i = 1; i <= k; i++) {
            int g = rice / (k + 1 - i);
            seq.push_back(g);
            rice -= g;
        }
        int pnt = 0;
        for (int i = 0; i < r; i++)
            if (i % 2 == 0)
                for (int j = 0; j < c; j++) {
                    R[i][j] = Get(pnt);
                    seq.back() -= int(B[i][j] == 'R');
                    if (seq.back() == 0 && seq.size() > 1) { seq.pop_back(); pnt++; }
                }
            else for (int j = c - 1; j >= 0; j--) {
                R[i][j] = Get(pnt);
                seq.back() -= int(B[i][j] == 'R');
                if (seq.back() == 0 && seq.size() > 1) { seq.pop_back(); pnt++; }
            }
        for (int i = 0; i < r; i++) {
            R[i][c] = '\0';
            printf("%s\n", R[i]);
        }
    }
    return 0;
}