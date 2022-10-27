#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
const int N = 2e6;
vector <int> g[N], g1[N];
int tin1[N], tout1[N];
int Tree1[N * 4];
int c = 0;
int lens[N];
bool used[N];
const int T = 20;
int up[T][N];
struct node{
    int ind;
    int len;
    bool flag;
    node* suf;
    node* supersuf;
    node* go[26];
    node(){};
};
node* Tree;
void add_ver(node* &v)
{
    v = new node();
    v -> ind = c++;
    v -> flag = 0;
    v -> suf = v -> supersuf = Tree;
    for(int i = 0; i < 26; i++)
    {
        v -> go[i] = 0;
    }
}
string s[N];
void go_to(node* &v, int i, int j)
{
    lens[v -> ind] = v -> len;
    if(j == sz(s[i]))
    {
        v -> flag = 1;
        return;
    }
    if(!v -> go[s[i][j] - 'a'])
    {
        add_ver(v -> go[s[i][j] - 'a']);
    }
    v -> go[s[i][j] -'a'] -> len = v -> len + 1;
    go_to(v -> go[s[i][j] - 'a'], i, j + 1);
}
void update(int v, int l, int r, int idx, int val)
{
    Tree1[v] += val;
    if(l == r)
    {
        return;
    }
    if(idx <= (r + l) / 2)
    {
        update(v * 2, l, (r + l) / 2, idx, val);
    }
    else
    {
        update(v * 2 + 1, (r + l) / 2 + 1, r, idx, val);
    }
}
int ans(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return Tree1[v];
    }
    if(l <= ar && r >= al)
    {
        return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
    }
    return 0;
}
int timer = 0;
void dfs(int v, int p = -1)
{
    tin1[v] = timer++;
    for(auto to : g[v])
    {
        up[0][to] = v;
        dfs(to, v);
    }
    tout1[v] = timer - 1;
}
signed main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        cin >> s[i];
    }
    Tree = new node();
    Tree -> suf = Tree;
    Tree -> supersuf = Tree;
    Tree -> ind = c++;
    Tree -> flag = 0;
    Tree -> len = 0;
    for(int i = 0; i < 26; i++)
    {
        Tree -> go[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        go_to(Tree, i, 0);
    }
    queue <node*> q;
    for(int i = 0; i < 26; i++)
    {
        if(!Tree -> go[i])
        {
            Tree -> go[i] = Tree;
        }
        else
        {
            Tree -> go[i] -> suf = Tree -> go[i] -> supersuf = Tree;
            q.push(Tree -> go[i]);
        }
    }
    while(!q.empty())
    {
        node* v = q.front();
        q.pop();
    //    cout << v -> supersuf -> ind << " " << v -> ind << "\n";
        g[v -> supersuf -> ind].push_back(v -> ind);
        for(int i = 0; i < 26; i++)
        {
            if(!v -> go[i])
            {
                v -> go[i] = v -> suf -> go[i];
            }
            else
            {
                v -> go[i] -> suf = v -> suf -> go[i];
                if(v -> suf -> go[i] -> flag)
                {
                    v -> go[i] -> supersuf = v -> suf -> go[i];
                }
                else
                {
                    v -> go[i] -> supersuf = v -> suf -> go[i] -> supersuf;
                }
                q.push(v -> go[i]);
            }
        }
    }
  //  cout << "\n";
    dfs(0);
    for(int i = 1; i < T; i++)
    {
        for(int j = 0;j < n; j++)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    Tree -> flag = 0;
    int global_ans = 0;
    for(int i = 0; i < n; i++)
    {
        node* v = Tree;
        vector <int> maxleft(sz(s[i]));
        vector <int> indexes(sz(s[i]));
        for(int j = 0; j < sz(s[i]); j++)
        {
            v = v -> go[s[i][j] - 'a'];
            if(v -> flag && j != sz(s[i]) - 1)
            {
                maxleft[j] = v -> len;
                indexes[j] = v -> ind;
            }
            else
            {
                maxleft[j] = v -> supersuf -> len;
                indexes[j] = v -> supersuf -> ind;
            }
        }
        vector <int> updates;
        int minind = 1e9;
        for(int j = sz(s[i]) - 1; j >= 0; j--)
        {
            if(minind <= j)
            {
                int st = indexes[j];
                for(int k = T - 1; k >= 0; k--)
                {
                    if(lens[up[k][st]] > j - minind + 1)
                    {
                        st = up[k][st];
                    }
                }
                if(lens[st] > j - minind + 1)
                {
                    st = up[0][st];
                }
                update(1, 0, N - 1, tin1[st], 1);
                updates.push_back(st);
            }
            if(maxleft[j] != 0)
            {
                int st = up[0][indexes[j]];
                update(1, 0, N - 1, tin1[st], 1);
                updates.push_back(st);
            }
            minind = min(minind, j - maxleft[j] + 1);
        }
        for(int j = 0; j < sz(s[i]); j++)
        {
            if(indexes[j] != 0)
            {
                int t = ans(1, 0, N - 1, tin1[indexes[j]], tout1[indexes[j]]);
                if(t == 0 && !used[indexes[j]])
                {
                    used[indexes[j]] = 1;
                    global_ans++;
                }
            }
        }
        for(int j = 0; j < sz(s[i]); j++)
        {
            used[indexes[j]] = 0;
        }
        for(auto ind : updates)
        {
            update(1, 0, N - 1, tin1[ind], -1);
        }
    }
    cout << global_ans;
    return 0;
}