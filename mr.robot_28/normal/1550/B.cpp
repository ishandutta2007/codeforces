#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5;

signed main()
{
//  ios_base::sync_with_stdio(0);
//  cin.tie(0);
//  cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int sum = n * a;
        if(b > 0)
        {
            sum += n * b;
        }
        else
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(i == 0 || s[i] != s[i - 1])
                {
                    cnt++;
                }
            }
            if(cnt <= 2)
            {
                sum += cnt * b;
            }
            else if(cnt % 2 == 0)
            {
                sum += (cnt - 2) / 2 * b + b * 2;
            }
            else
            {
                sum += (cnt - 1) / 2 * b + b;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}