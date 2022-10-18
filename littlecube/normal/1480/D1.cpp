#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int n, arr[100005] = {}, last[100005], next[100005], cur[2] = {0, 0}, ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        next[i] = 1e6;
        next[last[arr[i]]] = i;
        last[arr[i]] = i;
    }
    next[0] = 1e6;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] != arr[cur[0]] && arr[i] == arr[cur[1]])
            ans++, cur[0] = cur[1] = i;
        else if (arr[i] != arr[cur[1]] && arr[i] == arr[cur[0]])
            ans++, cur[0] = cur[1] = i;
        else if (arr[i] == arr[cur[1]] && arr[i] == arr[cur[0]])
            cur[0] = cur[1] = i;
        else if (next[cur[0]] <= next[cur[1]])
            ans++, cur[0] = i;
        else
            ans++, cur[1] = i;
    }
    cout << ans << '\n';
}