#include<bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int t = log2(m);
    if(n > t)
    {
        cout << m;
        return 0;
    }
    n = (1 << n);
    cout << m % n;
    return 0;
}