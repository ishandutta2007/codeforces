#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
int f[maxn] , m , g[maxn] , h[maxn];
vector<int> v;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> f[i];
        if(f[i] == i)
            m++ , v.pb(i);
    }
    if(m == 0)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        if(f[f[i]] != f[i])
        {
            cout << -1;
            return 0;
        }
    }
    for(int i = 0; i < v.size(); i++)
    {
        int a = v[i];
        g[a] = i + 1;
        h[i + 1] = a;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!g[f[i]])
        {
            cout << -1;
            return 0;
        }
        g[i] = g[f[i]];
    }
    cout << m << endl;
    for(int i = 0; i < n; i++)
        cout << g[i + 1] << " ";
    cout << endl;
    for(int i = 0; i < m; i++)
        cout << h[i + 1] << " ";
}