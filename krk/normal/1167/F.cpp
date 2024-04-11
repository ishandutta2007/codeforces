#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxn = 500005;

int n;
int a[Maxn];
ii seq[Maxn];
int L[Maxn], R[Maxn];
vector <int> un;
int res;

void insertRight(int BIT[], int x, int s)
{
    x++;
    for (int i = x; i > 0; i -= i & -i)
        BIT[i] = (BIT[i] + s) % mod;
}

int getRight(int BIT[], int x)
{
    x++;
    int res = 0;
    for (int i = x; i <= n; i += i & -i)
        res = (res + BIT[i]) % mod;
    return res;
}

void insertLeft(int BIT[], int x, int s)
{
    x++;
    for (int i = x; i <= n; i += i & -i)
        BIT[i] = (BIT[i] + s) % mod;
}

int getLeft(int BIT[], int x)
{
    x++;
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res = (res + BIT[i]) % mod;
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        seq[i] = ii(a[i], i);
        insertLeft(L, i, ll(i + 1) * a[i] % mod);
        insertRight(R, i, ll(n - i) * a[i] % mod);
    }
    sort(seq, seq + n);
    for (int i = 0; i < n; i++) {
        int ind = seq[i].second;
        res = (res + ll(a[ind]) * (ind + 1) % mod * (n - ind)) % mod;
        res = (res + ll(getLeft(L, ind - 1)) * (n - ind)) % mod;
        res = (res + ll(getRight(R, ind + 1)) * (ind + 1)) % mod;
        insertLeft(L, ind, (mod - ll(ind + 1) * a[ind] % mod) % mod);
        insertRight(R, ind, (mod - ll(n - ind) * a[ind] % mod) % mod);
    }
    printf("%d\n", res);
    return 0;
}