#include<bits/stdc++.h>

using namespace std;

const int maxn = 100100;
vector <int> v[maxn];
long long dpD[maxn];
long long dpD2[maxn];
long long dpU[maxn];
int ind[maxn];
bool mark[maxn];

long long max(long long x, long long y)
{
    return (x > y ? x : y);
}

void dfsD(int x, int p)
{
    int mx = 0, mx2 = 0;
    for (int i = 0; i < v[x].size(); i++)
    {
        int u = v[x][i];
        if (p != u)
        {
            dfsD(u, x);
            if(mark[u])
            {
                if (1 > mx)
                {
                    mx2 = mx;
                    mx = 1;
                    ind[x] = u;
                }
                else if (1 > mx2)
                {
                    mx2 = 1;
                }
            }
            if (dpD[u] + 1 > mx && dpD[u])
            {
                mx2 = mx;
                mx = dpD[u] + 1;
                ind[x] = u;
            }
            else if (dpD[u] + 1 > mx2 && dpD[u])
            {
                mx2 = dpD[u] + 1;
            }
        }
    }
    if(mx)
        dpD[x] = mx;
    if(mx2)
        dpD2[x] = mx2;
}

void dfsU(int x, int p)
{
    if (x)
    {
        if(dpU[p])
            dpU[x] = dpU[p] + 1;
        if(mark[p])
            dpU[x] = max(dpU[x] , 1);
        if(ind[p] == x)
        {
            int t2 = dpD2[p];
            if (t2)
                dpU[x] = max(dpU[x], dpD2[p] + 1);
        }
        else
        {
            int t2 = dpD[p];
            if (t2)
                dpU[x] = max(dpU[x], dpD[p] + 1);
        }
    }
    for (int i = 0; i < v[x].size(); i++)
    {
        int u = v[x][i];
        if (u != p)
        {
            dfsU(u, x);
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        a--;
        mark[a] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        dpD[i] = 0;
        dpD2[i] = 0;
        ind[i] = -1;
    }
    dfsD(0, -1);
    dfsU(0, -1);
    for (int i = 0; i < n; i++)
    {
     //   cout << i + 1 << " " << dpU[i] << " " << dpD[i] << " " << endl;
        if (dpU[i] > d || dpD[i] > d)
        {
            ans++;
        }
    }
    cout << n - ans;
    return 0;
}