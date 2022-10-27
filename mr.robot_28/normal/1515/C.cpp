#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
const int mod = 1e9 + 7;
const int N = 2e5+ 100;


signed main()
{
  //  ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, x;
        cin >> n >> m>> x;
        vector <int> h(n);
        priority_queue <pair <int, int> > q;
        vector <int> index(n);
        for(int i = 0; i < m; i++)
        {
            q.push({0, i});
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++)
        {
            cin >> h[i];
            int t = q.top().Y;
            int f = -q.top().X;
            q.pop();
            cout << t + 1 << " ";
            q.push({-(f + h[i]), t});
        }
        cout << "\n";
    }
    return 0;
}