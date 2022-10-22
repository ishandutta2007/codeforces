#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
const int Maxm = 3000000;

int n;
multiset <int> B;
int mn[Maxm];
int ind[Maxm];

int main()
{
    int nxt = 1;
    for (int i = 2; i < Maxm; i++) if (mn[i] == 0) {
        ind[i] = nxt++;
        for (int j = i; j < Maxm; j += i) if (mn[j] == 0)
            mn[j] = i;
    }
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        int x; scanf("%d", &x);
        B.insert(x);
    }
    for (int i = 0; i < n; i++) {
        multiset <int>::iterator it = B.end(); it--;
        int x = *it; B.erase(it);
        int res;
        if (mn[x] == x) { res = ind[x]; it = B.find(ind[x]); B.erase(it); }
        else { res = x; it = B.find(x / mn[x]); B.erase(it); }
        printf("%d%c", res, i + 1 < n? ' ': '\n');
    }
    return 0;
}