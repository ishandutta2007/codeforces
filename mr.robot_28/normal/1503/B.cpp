#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

signed main()
{
    int n;
    cin >> n;
    int t = n * n;
    vector <vector <int> > col(n, vector <int> (n, 0));
    int cnt1 = (n * n + 1) / 2;
    int cnt2 = n * n - cnt1;
    while(t)
    {
        int a;
        cin >> a;
        if(a != 1 && cnt1 > 0)
        {
            cnt1--;
            bool flag = 0;
            for(int x = 0; x < n; x++)
            {
                for(int y = x % 2; y < n; y += 2)
                {
                    if(col[x][y] == 0 && !flag)
                    {
                        col[x][y] = 1;
                        flag = 1;
                        cout << 1 << " " << x + 1 << " " << y + 1 << endl;
                    }
                }
            }
        }
        else if(a != 2 && cnt2 > 0)
        {
            cnt2--;
            bool flag = 0;
            for(int x = 0; x < n; x++)
            {
                for(int y = 1 - x % 2; y < n; y += 2)
                {
                    if(col[x][y] == 0 && !flag)
                    {
                        col[x][y] = 2;
                        flag = 1;
                        cout << 2 << " " << x + 1 << " " << y + 1 << endl;
                    }
                }
            }
        }
        else
        {
            bool flag = 0;
            for(int x = 0; x < n; x++)
            {
                for(int y = 0; y < n; y++)
                {
                    if(col[x][y] == 0 && !flag)
                    {
                        flag = 1;
                        col[x][y] = 3;
                        cout << 3 << " " << x + 1 << " " << y + 1 << endl;
                        if((x + y) % 2 == 0)
                        {
                            cnt1--;
                        }
                        else
                        {
                            cnt2--;
                        }
                    }
                }
            }
        }
        t--;
    }
    return 0;
}