#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int nil = 500001;

int pos[Maxn];
int l, r;

int main()
{
    l = nil + 1, r = nil;
    int q; scanf("%d", &q);
    while (q--) {
        char ch; scanf(" %c", &ch);
        int id; scanf("%d", &id);
        if (ch == 'L') pos[id] = --l;
        else if (ch == 'R') pos[id] = ++r;
        else printf("%d\n", min(pos[id] - l, r - pos[id]));
    }
    return 0;
}