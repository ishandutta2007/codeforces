#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 100;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector <vector <int> > fl(2, vector <int> (2));
        vector <string> s(n);
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
            for(int j = 0; j < m; j++)
            {
                if(s[i][j] == 'R')
                {
                    fl[0][(i + j) & 1] =1 ;
                }
                else if(s[i][j] == 'W')
                {
                    fl[1][(i + j) & 1] = 1;
                }
            }
        }
        vector <string> ans1(n), ans2(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((i + j) % 2 == 0)
                {
                    ans1[i] += 'R';
                    ans2[i] += 'W';
                }
                else
                {
                    ans1[i] += 'W';
                    ans2[i] += 'R';
                }
            }
        }
        bool fl1 = 1, fl2 = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s[i][j] != '.' && s[i][j] != ans1[i][j])
                {
                    fl1 = 0;
                }
                if(s[i][j] != '.' && s[i][j] != ans2[i][j])
                {
                    fl2 = 0;
                }
            }
        }
        if(fl1)
        {
            cout << "Yes\n";
            for(int i = 0;i < n; i++)
            {
                cout << ans1[i] << "\n";
            }
        }
        else if(fl2)
        {
            cout << "Yes\n";
            for(int i = 0; i < n; i++)
            {
                cout << ans2[i] << "\n";
            }
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}