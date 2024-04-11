#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (a[i] != b[i]);
    cout << (cnt <= 2 ? "YES" : "NO");
}