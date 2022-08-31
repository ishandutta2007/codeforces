#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;

const int max_n = 400008;
int m[max_n];
int kolcon[max_n];
int kol[max_n];
ll sum[max_n];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        
        scanf("%d", m + i);
        kolcon[m[i]]++;
    }
    int k = 0;
    for(int i = 0; i < max_n; i++)
    {
        k += kolcon[i];
        kol[i] = k;
    }
    sort(m, m + n);
    ll maxans = 0;
    for(int i = 0; i < n; i++)
    {
        if (i && m[i] == m[i - 1]) continue;
        int cur = m[i];
        ll ans = 0;
        for(int j = cur + cur; j <= max_n; j+=cur)
        {
            ll k = kol[j - 1] - kol[j - cur - 1];
            ans += k * (j - cur);
        }
        maxans = max(ans,maxans);
    }
    cout << maxans;
    return 0;
}