#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 500100;
const int maxa = 10000100;
const int mem = 31000000;

int n;
int num[maxa];
int pw2[maxn];
int primes[mem];
int numd[maxa];

void init() {
    for (int i = 2; i < maxa; i++)
        if (numd[i] == 0)
            for (int j = i; j < maxa; j += i)
                numd[j]++;

    pw2[0] = 1;
    for (int i = 0; i < maxn-1; i++)
        pw2[i+1] = ll(pw2[i]) * 2 % mod;
}

int v[maxn], sze;

void dfs(int i, int p) {
    if (i == sze) num[p]++;
    else {
        dfs(i+1, p);
        dfs(i+1, p*v[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sze = 0;
        int k = 2;
        while (k * k <= a && a > 1) {
            if (a%k == 0) {
                v[sze++] = k;
                while (a%k == 0) a /= k;
            } else k++;
        }
        if (a > 1) v[sze++] = a;
        dfs(0, 1);
    }

    int ans = 0, tot = 0;
    for (int i = 2; i < maxa; i++)
        if (num[i]) {
            ans = (ll(ans) + mod + (numd[i]%2 ? 1 : -1) * (ll(pw2[num[i] - 1] - 1) * num[i] % mod)) % mod;

            tot = (ll(tot) + mod + (numd[i]%2 ? 1 : -1) * ((pw2[num[i]] - 1) % mod)) % mod;
        }

    cout << (ll(tot + mod - 1) % mod * n % mod + mod - (2 * ans % mod)) % mod << '\n';
}