#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define X first
#define Y second
#define pii pair<int, int>
using namespace std;

int a[50][50];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T --)
    {
        int n, k;
        memset(a, 0, sizeof(a));
        cin >> n >> k;
        int x = 0;
        for(int i = 1; i <= n; i += 2)
        {
            a[i][i] = 1;
            k --;
            if(k == 0) break;
        }
        if(k > 0) cout << -1 << endl;
        else
        {
            for(int i = 1; i <= n; i ++)
            {
                for(int j = 1; j <= n; j ++)
                {
                    if(a[i][j] == 1) cout << 'R';
                    else cout << '.';
                }
                cout << "\n";
            }
        }
    }

    return 0;
}