#include <bits/stdc++.h>

using namespace std;


signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int u[n], v[n];
    for(int i = 0; i < n; i++)
    {
        cin >> u[i] >> v[i];
        if(u[i] > v[i])
            swap(u[i], v[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            ans += v[i] == u[j] || u[i] == u[j] || v[i] == v[j] || u[i] == v[j];
    cout << ans << "\n";
	return 0;
}