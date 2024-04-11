#include <bits/stdc++.h>
using namespace std;

typedef pair <string, int> si;

const int Maxl = 1000005;

int n;
char A[Maxl], B[Maxl];
map <si, vector <int> > M;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s %s", &A, &B);
        int mask = 0;
        int alen = strlen(A), blen = strlen(B);
        for (int j = 0; j < blen; j++)
            mask |= 1 << int(B[j] - 'a');
        while (alen > 0 && bool(mask & 1 << int(A[alen - 1] - 'a')))
            alen--;
        A[alen] = '\0';
        M[si(A, mask)].push_back(i);
    }
    printf("%d\n", int(M.size()));
    for (map <si, vector <int> >::iterator it = M.begin(); it != M.end(); it++) {
        printf("%d", int(it->second.size()));
        for (int i = 0; i < it->second.size(); i++)
            printf(" %d", it->second[i]);
        printf("\n");
    }
    return 0;
}