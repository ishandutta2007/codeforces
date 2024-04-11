#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n, k;
int a[Maxn];
ll res;
vector <ll> seq;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    ll cur = 0;
    for (int i = n - 1; i > 0; i--) {
        cur += a[i];
        seq.push_back(cur);
    }
    cur += a[0];
    res += cur; k--;
    sort(seq.rbegin(), seq.rend());
    for (int i = 0; i < k; i++)
        res += seq[i];
    cout << res << endl;
    return 0;
}