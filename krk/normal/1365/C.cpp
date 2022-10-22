#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int ina[Maxn], inb[Maxn];
map <int, int> M;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        ina[a] = i;
    }
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        inb[a] = i;
        M[(ina[a] - inb[a] + n) % n]++;
    }
    int res = 0;
    for (map <int, int>::iterator it = M.begin(); it != M.end(); it++)
        res = max(res, it->second);
    printf("%d\n", res);
    return 0;
}