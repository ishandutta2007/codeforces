#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
#define ld long double

set <int> st1, st2;
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
        vector <vector <char> > a(n, vector<char> (m));
        vector <vector <char> > ans(n, vector <char> (m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                ans[i][j] = a[i][j];
            }
        }
        int st = 0;
        while(st + 3 < n)
        {
            for(int j = 0; j < m; j++)
            {
                cout << "X";
            }
            cout << "\n";
            int p = -1;
            for(int j = 0; j < m; j++)
            {
                if(a[st + 1][j] == 'X')
                {
                    p = j;
                }
            }
            if(p == -1)
            {
                cout << "X";
                for(int j = 1; j < m; j++)
                {
                    cout << ".";
                }
                cout << "\n";
                st += 2;
                continue;
            }
            for(int j = 0; j < m; j++)
            {
                cout << a[st + 1][j];
            }
            cout << "\n";
            for(int j = 0; j < m; j++)
            {
                if(j == p)
                {
                    cout << "X";
                }
                else
                {
                    cout << a[st + 2][j];
                }
            }
            cout << "\n";
            st += 3;
        }
        if(st != n)
        {
            for(int j = 0; j< m; j++)
            {
                cout << "X";
            }
            cout << "\n";
            st++;
        }
        if(st == n - 2)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[st][j] == 'X' || a[st + 1][j] == 'X')
                    {
                        cout << "X";
                    }
                    else
                    {
                        cout << ".";
                    }
            }
            cout << "\n";
            st++;
        }
        if(st == n - 1)
        {
            for(int j = 0; j < m; j++)
            {
                cout << a[st][j];
            }
            cout << "\n";
        }
    }
    return 0;
}