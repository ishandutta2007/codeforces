#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()

const int T = 22;
const int N = 6e5 + 100;
int n;
string s;
vector <int> g[N];
int _sz[N];
int tin[N], tout[N];
int timer = 0;
int up[T][N];
void dfs(int v, int p = -1)
{
    _sz[v] = 1;
    tin[v] = timer++;
    for(auto to : g[v])
    {
        if(to != p)
        {
            up[0][to] = v;
            dfs(to, v);
            _sz[v] += _sz[to];
        }
    }
    tout[v] = timer++;
}
bool pred(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
vector <int> paths[N];
int pathcount = 1;
void dfs1(int v, int it = 0, int p = -1)
{
    paths[it].push_back(v);
    int x = -1;
    for(auto to : g[v])
    {
        if(to == p)
        {
            continue;
        }
        if(x == -1 || _sz[to] > _sz[x])
        {
            x = to;
        }
    }
    if(x == -1)
    {
        return;
    }
    dfs1(x, it, v);
    for(auto to : g[v])
    {
        if(to != p && to != x)
        {
            dfs1(to, pathcount++, v);
        }
    }
}
char res[N];
int it = 0;
int down_id[N], up_id[N];
int id_path[N], id_path1[N];
int lcp[T][N];
int index[N];
int index1[N];
int cnt[N], start[N], color[N];
int new_index[N], new_color[N];
int maxright[T][N];

void build()
{
    res[it++] = '#';
    for(int i = 0; i < it; i++)
    {
        cnt[max(0, res[i] - 'a' + 1)]++;
    }
    for(int i = 1; i < N; i++)
    {
        start[i] = start[i - 1] + cnt[i - 1];
    }
    for(int i = 0; i < it; i++)
    {
        index1[i] = start[max(0, res[i] - 'a' + 1)];
        index[start[max(0, res[i] - 'a' + 1)]++] = i;
    }
    int stcolor = 0;
    for(int i = 0; i < it; i++)
    {
        if(i != 0 && res[index[i - 1]] != res[index[i]])
        {
            stcolor++;
        }
        color[index[i]] = stcolor;
    }
    for(int z = 0; (1 << z) <= it; z++)
    {
        for(int i = 0; i < it; i++)
        {
            cnt[i] = 0;
            start[i] = 0;
        }
        for(int i = 0; i < it; i++)
        {
            cnt[color[i]]++;
        }
        for(int i = 1; i < it; i++)
        {
            start[i] = start[i - 1] + cnt[i - 1];
        }
        for(int i = 0; i < it; i++)
        {
            int x = index[i];
            int y = (x - (1 << z) + it) % it;
            new_index[start[color[y]]++] = y;
        }
        stcolor = 0;
        for(int i = 0; i < it; i++)
        {
            if(i != 0)
            {
                int x1 = new_index[i - 1];
                int x2 = new_index[i];
                int y1 = (x1 + (1 << z)) % it;
                int y2 = (x2 + (1 << z)) % it;
                if(color[x1] != color[x2] || color[y1] != color[y2])
                {
                    stcolor++;
                }
            }
            new_color[new_index[i]] = stcolor;
        }
        for(int i = 0; i < it; i++)
        {
            color[i] = new_color[i];
            index[i] = new_index[i];
        }
    }
    for(int i = 0; i < it; i++)
    {
        index1[index[i]] = i;
    }
    maxright[0][it - 1] = it - 1;
    for(int i = it - 2; i >= 0; i--)
    {
        if(res[index[i]] == res[index[i + 1]])
        {
            maxright[0][i] = maxright[0][i + 1];
        }
        else
        {
            maxright[0][i] = i;
        }
    }
    for(int z = 1; (1 << z) <= it; z++)
    {
        maxright[z][it - 1] = it - 1;
        for(int i = it - 2; i >= 0; i--)
        {
            int x = (index[i] + (1 << (z - 1))) % it;
            int y = (index[i + 1] + (1 << (z - 1))) % it;
            if(maxright[z - 1][i] == i)
            {
                maxright[z][i] = i;
                continue;
            }
            x = index1[x];
            y = index1[y];
            if(x > y)
            {
                swap(x, y);
            }
            if(maxright[z - 1][x] >= y)
            {
                maxright[z][i] = maxright[z][i + 1];
            }
            else
            {
                maxright[z][i] = i;
            }
        }
    }
    for(int i = 0; i < it - 1; i++)
    {
        int x = index[i];
        int y = index[i + 1];
        for(int p = T - 1; p >= 0; p--)
        {
            int a = index1[x];
            int b = index1[y];
            if(a > b)
            {
                swap(a, b);
            }
            if(maxright[p][a] >= b)
            {
                lcp[0][i] += (1 << p);
                x += (1 << p);
                y += (1 << p);
                x %= it;
                y %= it;
            }
        }
    }
    for(int z = 1; (1 << z) <= it - 1; z++)
    {
        for(int i = 0; i + (1 << z) <= it - 1; i++)
        {
            lcp[z][i] =  min(lcp[z - 1][i], lcp[z - 1][i + (1 << (z - 1))]);
        }
    }
}
int get_lcp(int x, int y)
{
    x = index1[x];
    y = index1[y];
    if(x > y)
    {
        swap(x, y);
    }
    if(x == y)
    {
        return 1e9;
    }
    y--;
    int t = log2(y - x + 1);
    return min(lcp[t][x], lcp[t][y - (1 << t) + 1]);
}
int lca(int x, int y)
{
    if(pred(x, y))
    {
        return x;
    }
    for(int j = T - 1; j >= 0; j--)
    {
        if(!pred(up[j][x], y))
        {
            x = up[j][x];
        }
    }
    return up[0][x];
}
vector <pair <int, int> > way1;
void get_way(int a, int b, vector <pair <int, int> > &way)
{
    int ab = lca(a, b);
    while(1)
    {
        int x = id_path1[a];
        if(!pred(paths[x][0], b))
        {
            way.push_back({up_id[a], up_id[paths[x][0]]});
            a = up[0][paths[x][0]];
        }
        else
        {
            way.push_back({up_id[a], up_id[ab]});
            break;
        }
    }
    while(1)
    {
   //     cout << b << " ";
        int x = id_path1[b];
     //   cout << x << " " << paths[x][0] << "\n";
        if(!pred(paths[x][0], a))
        {
            way1.push_back({down_id[paths[x][0]], down_id[b]});
            b = up[0][paths[x][0]];
        }
        else if(!pred(b, a))
        {
            way1.push_back({down_id[paths[x][id_path[ab] + 1]], down_id[b]});
            break;
        }
        else
        {
            break;
        }
    }
    while(sz(way1))
    {
        way.push_back(way1.back());
        way1.pop_back();
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	cout.tie(NULL);
  	cin >> n;
  	cin >> s;
  	for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    dfs1(0);
    for(int i = 0; i < pathcount; i++)
    {
        for(int j = 0; j < sz(paths[i]); j++)
        {
            int v = paths[i][j];
            id_path[v] = j;
            id_path1[v] = i;
            down_id[v] = it;
            res[it++] = s[v];
        }
        for(int j = sz(paths[i]) - 1; j >= 0; j--)
        {
            int v = paths[i][j];
            up_id[v] = it;
            res[it++] = s[v];
        }
    }
    for(int i = 1; i < T; i++)
    {
        for(int j = 0; j < n; j++)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    build();
    int q;
    cin >> q;
    vector <pair <int, int> > way_ab, way_cd;
    while(q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        way_ab.clear();
        way_cd.clear();
        get_way(a, b, way_ab);
    //    cout << "X\n";
        get_way(c, d, way_cd);
        int i = 0, j = 0, add1 = 0, add2 = 0;
        int sum = 0;
        while(i != sz(way_ab) && j != sz(way_cd))
        {
            int u = get_lcp(way_ab[i].X + add1, way_cd[j].X + add2);
         //   cout << u << "\n";
            u = min(u, way_ab[i].Y - (add1 + way_ab[i].X) + 1);
            u = min(u, way_cd[j].Y - (add2 + way_cd[j].X) + 1);
     //       cout << way1[i].X + add1 << " " << way2[j].X + add2 << " ";
       //     cout << u << "\n";
            add1 += u;
            add2 += u;
            sum += u;
            if(u == 0)
            {
                break;
            }
            if(add1 + way_ab[i].X == way_ab[i].Y + 1)
            {
                add1 = 0;
                i++;
            }
            if(add2 + way_cd[j].X == way_cd[j].Y + 1)
            {
                add2 = 0;
                j++;
            }
        }
        q--;
        cout << sum << "\n";
    }
    return 0;
}