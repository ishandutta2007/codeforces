#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll k, x;
ll a[Maxn];

int main()
{
    scanf("%d %I64d %I64d", &n, &k, &x);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    vector <ll> seq;
    int res = 0;
    for (int i = 0, j; i < n; i = j) {
        j = i + 1;
        while (j < n && a[j] - a[i] <= x) j++;
        res++;
        if (j < n) seq.push_back((a[j] - a[j - 1] - 1) / x);
    }
    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size() && seq[i] <= k; i++) {
        res--;
        k -= seq[i];
    }
    cout << res << endl;
    return 0;
}