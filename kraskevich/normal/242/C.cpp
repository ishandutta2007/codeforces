#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define pii pair<int, int>
const int inf = 1000 * 1000 * 1000 * 2 + 1;

int dx[3] = {-1, 0, 1};
int dy[3] = {-1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(0);
    
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    
    int n;
    cin >> n;
    
    map<pii, int> dist;
    
    for (int i = 0; i < n; ++i)
    {
        int r, a, b;
        cin >> r >> a >> b;
        
        for (int j = a; j <= b; ++j)
            dist[pii(r, j)] = inf;
    }
    
    dist[pii(x0, y0)] = 0;
    queue<pii> q;
    q.push(pii(x0, y0));
    
    while (!q.empty())
    {
        pii v = q.front();
        q.pop();
        
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                pii to = pii(v.first + dx[i], v.second + dy[j]);
                if (dist.count(to) && dist[to] > dist[v] + 1)
                {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
    }
    
    if (dist[pii(x1, y1)] == inf)
        dist[pii(x1, y1)] = -1;
    
    cout << dist[pii(x1, y1)];
    
    //cin >> n;
    
    return 0;
}