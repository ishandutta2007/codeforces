#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long long ans = (n - 1) * (n - 1);
        for(int j = 2; j <= n / 2; j++)
        {
            ans += 2 * (n - j) * (n - j);
        }
        if(n % 2 == 1)
        {
            ans += (n - (n + 1) / 2) * (n - (n + 1) / 2);
        }
        vector <int> p;
        p.push_back(n / 2 + 1);
        for(int i = 1; i < n / 2; i++)
        {
            p.push_back(i);
        }
        for(int i = n / 2 + 2; i <= n; i++)
        {
            p.push_back(i);
        }
        p.push_back(n / 2);
        vector <pair <int, int> > pans;
        if(n / 2 + 1 < n)
        {
        for(int i = n / 2 + 1; i < n; i++)
        {
            pans.push_back({i, 1});
        }
        }
        if(n / 2 > 1)
        {
        for(int i = n / 2; i > 1; i--)
        {
            pans.push_back({i, n});
        }
        }
        pans.push_back({1, n});
        cout << ans << "\n";
        for(int i = 0; i < n; i++)
        {
            cout << p[i] << " ";
        }
        cout << "\n";
        cout << pans.size() << "\n";
        for(int i = 0; i < pans.size(); i++)
        {
            cout << pans[i].first << " " << pans[i].second << "\n";
        }
    }
  	return 0;
}