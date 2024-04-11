#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int N = 1e6 + 100;
const int M =  2e5;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <vector <int> > r(n, vector <int> (5));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cin >> r[i][j];
            }
        }
        int x = 0;
        for(int i = 1; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < 5; j++)
            {
                cnt += (r[x][j] > r[i][j]);
            }
            if(cnt >= 3)
            {
                x = i;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(x == i)
            {
                continue;
            }
            int cnt = 0;
            for(int j = 0; j < 5; j++)
            {
                cnt += (r[x][j] > r[i][j]);
            }
            if(cnt >= 3)
            {
                x = -2;
                break;
            }
        }
        cout << x + 1 << "\n";
    }
    return 0;
}