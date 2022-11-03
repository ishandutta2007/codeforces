#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
int a[maxn][maxn] , n , m;
vector<int> x , y;
void col()
{
    for(int j = 0; j < m; j++)
    {
        int mn = 1e5;
        for(int i = 0; i < n; i++)
            mn = min(mn , a[i][j]);
        ll k = mn;
        while(mn--)
        {
            x.pb(j);
        }
        for(int i = 0; i < n; i++)
            a[i][j] -= k;
    }
}
void row()
{
    for(int i = 0; i < n; i++)
    {
        int mn = 1e5;
        for(int j = 0; j < m; j++)
            mn = min(mn , a[i][j]);
        ll k = mn;
        while(mn--)
        {
            y.pb(i);
        }
        for(int j = 0; j < m; j++)
            a[i][j] -= k;
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    if(n < m)
    {
        row();
        col();
    }
    else
    {
        col();
        row();
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] != 0)
            {
                cout << -1;
                return 0;
            }
        }
    cout << x.size() + y.size() << endl;
    while(!x.empty())
    {
        cout << "col " << x.back() + 1 << endl;
        x.pop_back();
    }
    while(!y.empty())
    {
        cout << "row " << y.back() + 1 << endl;
        y.pop_back();
    }
}