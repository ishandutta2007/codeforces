#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

bool F(ll a, ll b)
{
    if (b % 2) return a % 2 == 0;
    ll lst = b / 2;
    if (lst < a) return a % 2 == 1;
    lst = lst / 2;
    if (lst < a) return true;
    return F(a, lst);
}

bool canWin(ll a, ll b) { return F(a, b); }

bool canLose(ll a, ll b)
{
    ll lst = b / 2;
    if (lst < a) return true;
    return F(a, lst);
}

int n;
ll s[Maxn], e[Maxn];
bool w1[Maxn], w2[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d %I64d", &s[i], &e[i]);
    w1[n - 1] = canWin(s[n - 1], e[n - 1]);
    w2[n - 1] = canLose(s[n - 1], e[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        if (canWin(s[i], e[i])) {
            if (!w1[i + 1]) w1[i] = true;
            if (!w2[i + 1]) w2[i] = true;
        }
        if (canLose(s[i], e[i])) {
            if (w1[i + 1]) w1[i] = true;
            if (w2[i + 1]) w2[i] = true;
        }
    }
    printf("%d %d\n", int(w1[0]), int(w2[0]));
    return 0;
}