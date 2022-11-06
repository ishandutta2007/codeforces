#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
const int N = 100005;
int pod[N];
int n, m, a[N], b[N];
int c[N];
vector<pair<int, int> >V[N];
bool odw[N];
int czw[N], czas;
void DFS(int w)
{
    czw[w] = ++czas;
    odw[w] = true;
    pod[w] = 1;
    for(int i = 0; i < V[w].size(); i++)
    {
        int u = V[w][i].first;
        int weight = c[V[w][i].second];
        if(!odw[u])
        {
            DFS(u);
            pod[w] += pod[u];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        V[a[i]].push_back(make_pair(b[i], i));
        V[b[i]].push_back(make_pair(a[i], i));
    }   
    DFS(1);
    for(int i = 1; i <= n; i++)
        odw[i] = 0;
    long long suma = 0;
    for(int i = 1; i < n; i++)
    {
        if(czw[a[i]] < czw[b[i]])
            swap(a[i], b[i]);
        long long x = pod[a[i]];
        long long y = n - pod[a[i]];
        suma += (long long)c[i] * (x * y + x * y);      
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int in, nw;
        cin >> in >> nw;
        long long x = pod[a[in]];
        long long y = n - pod[a[in]];
        suma -= (long long)(c[in] - nw) * (x * y + x * y);
        cout << fixed << setprecision(9) << (long double)(suma) / ((long double)n / (long double)3) / (long double) (n - 1)  << "\n";
        c[in] = nw;
        
    }
    return 0;
}