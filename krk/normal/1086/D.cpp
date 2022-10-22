#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxd = 3;
const string let = "RSP";

int n, q;
char str[Maxn];
int BIT[Maxd][Maxn];
set <int> S[Maxd];
int res;

int Get(int BIT[], int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void Update(int BIT[], int x, int delt)
{
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i] += delt;
}

int Count(int st)
{
    int av = (st + 1) % Maxd;
    int wh = (st - 1 + Maxd) % Maxd;
    if (S[st].empty()) return Get(BIT[av], n);
    if (S[wh].empty()) return 0;
    int lef = min(*S[st].begin(), *S[wh].begin()), rig = max(*S[st].rbegin(), *S[wh].rbegin());
    return Get(BIT[av], n) - Get(BIT[av], rig) +
           Get(BIT[av], *S[wh].rbegin()) - Get(BIT[av], *S[wh].begin()) +
           Get(BIT[av], lef);
}

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) {
        int st = let.find(str[i]);
        Update(BIT[st], i, 1);
        S[st].insert(i);
    }
    res = Count(0) + Count(1) + Count(2);
    printf("%d\n", res);
    for (int i = 1; i <= q; i++) {
        int p; char ch; scanf("%d %c", &p, &ch);
        if (str[p] == ch) { printf("%d\n", res); continue; }
        int old = let.find(str[p]);
        int nw = let.find(ch);
        Update(BIT[old], p, -1);
        S[old].erase(p);
        S[nw].insert(p);
        Update(BIT[nw], p, 1);
        str[p] = ch;
        res = Count(0) + Count(1) + Count(2);
        printf("%d\n", res);
    }
    return 0;
}