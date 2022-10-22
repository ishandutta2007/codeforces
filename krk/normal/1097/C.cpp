#include <bits/stdc++.h>
using namespace std;

const int Maxm = 1000015;
const int nil = 500005;

multiset <int> my[Maxm];
int n;
char tmp[Maxm];
int tlen;
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        tlen = strlen(tmp);
        int cur = 0, mn = 0;
        for (int i = 0; i < tlen; i++) {
            if (tmp[i] == '(') cur++;
            else cur--;
            mn = min(mn, cur);
        }
        my[nil + cur].insert(mn);
    }
    for (int i = Maxm - 1; i > nil; i--) if (!my[i].empty()) {
        int j = nil - (i - nil);
        if (j < 0) continue;
        int a = 0, b = 0;
        for (multiset <int>::iterator it = my[i].begin(); it != my[i].end(); it++)
            if (*it >= 0) a++;
        for (multiset <int>::iterator it = my[j].begin(); it != my[j].end(); it++)
            if (*it >= -(i - nil)) b++;
        res += min(a, b);
    }
    int a = 0;
    for (multiset <int>::iterator it = my[nil].begin(); it != my[nil].end(); it++)
        if (*it >= 0) a++;
    res += a / 2;
    printf("%d\n", res);
    return 0;
}