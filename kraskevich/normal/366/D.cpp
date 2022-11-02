#include <bits/stdc++.h>

using namespace std;

const int N = 1111;

vector<vector<int> > g(N);
vector<vector<int> > L(N);
vector<vector<int> > R(N);
vector<vector<int> > curL;
vector<vector<int> > curR;
int n, m;

bool bfs(int value)
{
    queue<int> q;
    q.push(0);
    vector<int> dist(n, N);
    dist[0] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++)
        {
            int to = g[v][i];
            if (curL[v][i] <= value && value <= curR[v][i])
            {
                if (dist[to] > dist[v] + 1)
                {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
    }
    return dist.back() < N;
}

bool check(int value)
{
    if (!value)
        return true;
    curL = L;
    curR = R;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < curL[i].size(); j++)
            curL[i][j] += value - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < curL[i].size(); j++)
            if (bfs(curL[i][j]))
                return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, low, high;
        cin >> a >> b >> low >> high;
        if (a == b)
            continue;
        --low;
        --high;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
        L[a].push_back(low);
        L[b].push_back(low);
        R[a].push_back(high);
        R[b].push_back(high);
    }
    int low = 0;
    int high = 1000 * 1000;
    while (low < high)
    {
        int mid = (low + high + 1) / 2;
        if (check(mid))
            low = mid;
        else
            high = mid - 1;
    }
    if (low)
        cout << low;
    else
        cout << "Nice work, Dima!";

}