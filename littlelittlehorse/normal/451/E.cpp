#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int P = 1000000007;
long long sum, a[21];
int n;

long long rp(long long now, int k){
    long long will = 1;
    for (; k; k >>= 1, now *= now, now %= P)
        if (k & 1) will *= now, will %= P;
    return will;
}

int main(){
    //freopen("a.in", "r", stdin);
    scanf("%d%I64d", &n, &sum);
    for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    long long ans = 0, D = 1;
    for (int i = 2; i < n; i++) D *= i, D %= P;
    D = rp(D, P - 2);
    for (int i = 0; i < 1 << n; i++)
    {
        int cnt = 0;        long long Left = sum;
    //  cout << Left << endl;
        for (int j = 0; j < n; j++)
            if (i & (1 << j)) ++cnt, Left -= a[j + 1] + 1;
        if (Left < 0) continue;
        long long value = D;
    //  cout << Left << " " << value << endl;
        for (long long j = Left + 1; j <= n - 1 + Left; j++)
            value *= j % P, value %= P;
    //  cout << value << endl;
        if (cnt & 1) ans -= value, ans += P, ans %= P;
        else ans += value, ans %= P;
    }
    printf("%I64d\n", ans);
}