#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 205;
int dist[N][N];
signed main()
{
//    ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    //cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = 1e9;
            }
        }
    }
    vector <pair <int, int> > vec(m);
    vector <int> wei(m);
    for(int i = 0; i < m; i++)
    {
        cin >> vec[i].first >> vec[i].second >> wei[i];
        vec[i].first--;
        vec[i].second--;
        dist[vec[i].first][vec[i].second] = 1;
        dist[vec[i].second][vec[i].first] = (wei[i] == 0 ? 1 : -1);
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j= 0; j < n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                if(dist[i][j] < -1e9)
                {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    pair <int, int> par = {-1, -1};
    for(int i = 0; i <n; i++)
    {
        if(dist[i][i] < 0)
        {
            cout << "NO";
            return 0;
        }
        for(int j = 0; j < n; j++)
        {
            if(par.second == -1 || par.first < dist[i][j])
            {
                par.first = dist[i][j];
                par.second = i;
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(dist[par.second][vec[i].first] == dist[par.second][vec[i].second])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    cout << par.first << "\n";
    for(int i = 0; i < n; i++)
    {
        cout<< dist[par.second][i] << " ";
    }
    return 0;
}