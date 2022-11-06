#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;

int a[N], n, l[N], r[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], r[a[i]] = i;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(a[i]), l[i] = s.size();
    long long ans = 0;
    for (int i = 2; i <= n; i++)
        if (i == r[a[i]])
            ans += l[i - 1];
    cout << ans;
    return 0;
}