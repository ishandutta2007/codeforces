#include<bits/stdc++.h>
using namespace std;
#define maxn 5000010
int wynik[maxn], pi[maxn], n, w[maxn];
long long pref[maxn];
void sito()
{
    for (int i=1; i<maxn; ++i) w[i] = i;
    for (int i=2; i<maxn; ++i)
    if (pi[i] == 0)
      for (int j=i; j<maxn; j+=i) 
        while (w[j] % i == 0) wynik[j]++, w[j] /= i, pi[j] = 1;
    for (int i=2; i<maxn; ++i) pref[i] = pref[i-1] + wynik[i];
}

int main()
{
    sito();
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%I64d\n", pref[a] - pref[b]);
    }
}