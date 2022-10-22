#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int mod = 1000000007;

int n, k;
int A[Maxn];
int L[Maxn], R[Maxn];
vector <int> S;
int res;

int Sum(int fir, int sec, int dif)
{
    return ll((fir + sec) % mod) * ll((sec - fir) / dif + 1) / 2 % mod;
}

int getFir(int lef)
{
    if (k >= lef) return k;
    return k + ((lef - k - 1) / (k - 1) + 1) * (k - 1);
}

int getLst(int rig)
{
    if (k > rig) return 0;
    return k + (rig - k) / (k - 1) * (k - 1);
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        while (!S.empty() && A[S.back()] < A[i]) {
            R[S.back()] = i; S.pop_back();
        }
        L[i] = S.empty()? -1: S.back();
        S.push_back(i);
    }
    while (!S.empty()) { R[S.back()] = n; S.pop_back(); }
    for (int i = 0; i < n; i++) {
        int a = i - L[i];
        int b = R[i] - i;
        if (a > b) swap(a, b);
        int tims = 0;
        int fir = getFir(1), lst = getLst(a);
        if (fir <= lst) tims = (tims + Sum(fir, lst, k - 1)) % mod;
        fir = getFir(a + 1), lst = getLst(b);
        if (fir <= lst) tims = (tims + ll(a) * ((lst - fir) / (k - 1) + 1)) % mod;
        fir = getFir(b + 1), lst = getLst(a + b - 1);
        if (fir <= lst) {
            fir = a + b - fir;
            lst = a + b - lst;
            tims = (tims + Sum(lst, fir, k - 1)) % mod;
        }
        res = (res + ll(tims) * A[i]) % mod;
    }
    printf("%d\n", res);
    return 0;
}