#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int mod = 1000000007;

int n;
int X[Maxn], Y[Maxn];
ll S2;
ll sumX, sumY, sumZ;
int allX, allY, allZ;
int cnt;
int res;

ll getCross(int ind1, int ind2, int ind3)
{
    ll ax = X[ind2] - X[ind1], ay = Y[ind2] - Y[ind1];
    ll bx = X[ind3] - X[ind1], by = Y[ind3] - Y[ind1];
    return ax * by - ay * bx;
}

bool Eq(int ind0)
{
    return (ll(X[ind0]) * sumX + ll(Y[ind0]) * sumY + ll(sumZ)) * 2 == S2;
}

bool Add(int ind0)
{
    int ind1 = (ind0 + cnt + 1) % n;
    int ind2 = (ind0 + cnt + 2) % n;
    if (ll(X[ind0]) * (sumX + Y[ind1] - Y[ind2]) + ll(Y[ind0]) * (sumY + X[ind2] - X[ind1]) + ll(sumZ) + ll(X[ind1]) * Y[ind2] - ll(Y[ind1]) * X[ind2] > S2 / 2)
        return false;
    sumX += Y[ind1] - Y[ind2];
    sumY += X[ind2] - X[ind1];
    sumZ += ll(X[ind1]) * Y[ind2] - ll(Y[ind1]) * X[ind2];
    allX = (ll(allX) + sumX % mod + mod) % mod;
    allY = (ll(allY) + sumY % mod + mod) % mod;
    allZ = (ll(allZ) + sumZ % mod + mod) % mod;
    assert(allX >= 0 && allY >= 0 && allZ >= 0);
    cnt++;
    return true; 
}

void Remove(int ind0)
{
    if (cnt == 0) return;
    int ind1 = (ind0 + 1) % n;
    int ind2 = (ind0 + 2) % n;
    sumX -= (Y[ind1] - Y[ind2]);
    sumY -= (X[ind2] - X[ind1]);
    sumZ -= (ll(X[ind1]) * Y[ind2] - ll(Y[ind1]) * X[ind2]);
    allX = (ll(allX) - ll(Y[ind1] - Y[ind2]) * cnt % mod + mod) % mod;
    allY = (ll(allY) - ll(X[ind2] - X[ind1]) * cnt % mod + mod) % mod;
    allZ = (ll(allZ) - (ll(X[ind1]) * Y[ind2] - ll(Y[ind1]) * X[ind2]) % mod * cnt % mod + mod) % mod;
    assert(allX >= 0 && allY >= 0 && allZ >= 0);
    cnt--;
}

void Update(int ind0)
{
    int G2 = (ll(X[ind0]) * allX + ll(Y[ind0]) * allY + ll(allZ)) % mod;
    if (G2 < 0) G2 += mod;
    res = (res - 2 * G2 % mod + mod) % mod;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    reverse(X, X + n);
    reverse(Y, Y + n);
    for (int i = 1; i + 1 < n; i++)
        S2 += getCross(0, i, i + 1);
    res = ll(n) * (n - 3) / 2ll % mod * (S2 % mod) % mod;
    int e = 0;
    for (int i = 0; i < n; i++) {
        while (Add(i)) ;
        e += Eq(i);
        Update(i);
        Remove(i);
    }
    res = (res + ll(e / 2) * (S2 % mod)) % mod;
    cout << res << endl;
    return 0;
}