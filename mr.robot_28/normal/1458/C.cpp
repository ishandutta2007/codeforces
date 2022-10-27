#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector <vector <int> > coor;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int a;
                cin >> a;
                a--;
                coor.push_back({i, j, a});
            }
        }
        vector <int> add(3, 0);
        vector <int> order(3);
        for(int i = 0; i < 3; i++)
        {
            order[i] = i;
        }
        for(int i = 0; i < m; i++)
        {
            char t;
            cin >> t;
            if(t == 'R')
            {
                add[1] = (add[1] + 1) % n;
            }
            else if(t == 'L')
            {
                add[1] = (add[1] + n - 1) % n;
            }
            else if(t == 'D')
            {
                add[0] = (add[0] + 1) % n;
            }
            else if(t == 'U')
            {
                add[0] = (add[0] + n - 1) % n;
            }
            else if(t == 'I')
            {
                swap(order[1], order[2]);
                swap(add[1], add[2]);
            }
            else
            {
                swap(order[0], order[2]);
                swap(add[0], add[2]);
            }
        }
        int ans[n][n];
        for(int i = 0; i < coor.size(); i++)
        {
            int x = coor[i][order[0]];
            int y = coor[i][order[1]];
            int z = coor[i][order[2]];
            int dx = (x + add[0]) % n;
            int dy = (y + add[1]) % n;
            ans[dx][dy] = (z + add[2]) % n;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << ans[i][j] + 1 << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}