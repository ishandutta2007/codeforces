#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 1000005;
const int nil = 200002;
const int Maxn = 2 * nil + 10;

int n;
ll a[Maxm];
int best = Maxm;
bool prime[Maxm];
vector <ll> pr;
ll my[Maxn];
int mlen;

void Try(ll x)
{
    ll cur = 0;
    for (int i = 0; i < n && cur < best; i++)
        if (a[i] < x) cur += x - a[i];
        else {
            ll my = a[i] % x;
            cur += min(my, x - my);
        }
    if (cur < best) best = cur;
}

int main()
{
    fill(prime + 2, prime + Maxm, true);
    for (int i = 2; i < Maxm; i++) if (prime[i]) {
        pr.push_back(i);
        for (int j = i + i; j < Maxm; j += i)
            prime[j] = false;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    for (int i = -200000; i <= 200000; i++)
        if (a[0] + i > 1) my[mlen++] = a[0] + i;
    ll sav = my[0];
    for (int i = 0; i < pr.size(); i++) {
        int md = (pr[i] - sav % pr[i]) % pr[i];
        for (int j = md; j < mlen; j += pr[i])
            while (my[j] % pr[i] == 0) my[j] /= pr[i];
    }
    for (int i = 0; i < mlen; i++)
        if (my[i] > 1) pr.push_back(my[i]);
    sort(pr.begin(), pr.end()); pr.erase(unique(pr.begin(), pr.end()), pr.end());
    for (int i = 0; i < pr.size(); i++)
        Try(pr[i]);
    printf("%d\n", best);
    return 0;
}