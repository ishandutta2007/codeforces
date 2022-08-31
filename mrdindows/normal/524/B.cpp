#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int w[n], h[n];
    for(int i = 0; i < n; i++)
        cin >> w[i] >> h[i];
    int ans = 2e9;
    for(int i = 0; i < 1007; i++)
    {
        int mh = i;
        int sw = 0;
        for(int j = 0; j < n; j++)
            {
                int t = min(h[j], w[j]);
                if(t > mh)
                    goto nxt;
                if(h[j] <= mh && w[j] <= mh)
                    sw += t;
                else if(h[j] <= mh)
                    sw += w[j];
                else
                    sw += h[j];
            }
        ans = min(ans, sw * mh);
        nxt:;
    }
    cout << ans << endl;
    return 0;
}