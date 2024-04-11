#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    map <int, int> W;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        W[a - i] += a;
    }
    int ans = 0;
    map <int, int>  :: iterator it;
    for(it = W.begin(); it != W.end(); it++)
    {
        ans = max(ans, it -> second);
    }
    cout << ans;
    return 0;
}