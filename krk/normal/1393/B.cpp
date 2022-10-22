#include <bits/stdc++.h>
using namespace std;

int n;
map <int, int> M;
int has4;
int sum;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        M[a]++;
    }
    for (auto p: M) {
        has4 += p.second >= 4;
        sum += p.second / 2;
    }
    int q; scanf("%d", &q);
    while (q--) {
        char typ;
        int a;
        scanf(" %c %d", &typ, &a);
        has4 -= M[a] >= 4;
        sum -= M[a] / 2;
        if (typ == '+') M[a]++;
        else M[a]--;
        has4 += M[a] >= 4;
        sum += M[a] / 2;
        printf("%s\n", has4 > 0 && sum >= 4? "YES": "NO");
    }
    return 0;
}