#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int T;
int n, k;
int a[Maxn];

llll findL(int &l)
{
    ll mn = 0, tot = 0;
    while (l >= 1) {
        tot += a[l--];
        mn = min(mn, tot);
        if (tot >= 0) return llll(mn, tot);
    }
    return llll(mn, Inf);
}

llll findR(int &r)
{
    ll mn = 0, tot = 0;
    while (r <= n) {
        tot += a[r++];
        mn = min(mn, tot);
        if (tot >= 0) return llll(mn, tot);
    }
    return llll(mn, Inf);
}

bool Solve()
{
    ll cur = a[k];
    int l = k - 1, r = k + 1;
    llll gotl = findL(l);
    llll gotr = findR(r);
    while (true)
        if (gotl.first + cur >= 0)
            if (gotl.second == Inf) return true;
            else {
                cur += gotl.second;
                gotl = findL(l);
            }
        else if (gotr.first + cur >= 0)
            if (gotr.second == Inf) return true;
            else {
                cur += gotr.second;
                gotr = findR(r);
            }
        else return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}