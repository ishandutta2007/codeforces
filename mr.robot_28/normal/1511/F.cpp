#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int mod = 998244353;
const int K = 161;
const int Alph = 26;
struct node{
    int nxt[Alph];
    bool term;
    node(){
        term = 0;
        fill(nxt, nxt + Alph, -1);
    };

};
vector <node> trie;
int tot = 0;
void add(string s)
{
    int st = 0;
    int d = 1;
    for(int i = 0; i < sz(s); i++)
    {
        ++d;
        if(trie[st].nxt[s[i] - 'a'] == -1)
        {
            trie[st].nxt[s[i] - 'a'] = sz(trie);
            trie.push_back(node());
            tot += d;
        }
        st = trie[st].nxt[s[i] - 'a'];
    }
    trie[st].term = 1;
}
void add(int &a, int b)
{
    a += b;
    if(a >= mod)
    {
        a -= mod;
    }
}
int mul(int a, int b)
{
    return 1LL * a * b % mod;
}
vector <vector <int> > operator*(const vector <vector <int> > &a, const vector <vector<int> > &b)
{
    vector <vector <int> > c(K, vector <int> (K, 0));
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < K; j++)
        {
            for(int k = 0; k < K; k++)
            {
                add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}
vector <vector <int> > binpow(vector <vector <int> > a, int m)
{
    vector <vector <int> > res(K, vector <int> (K));
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < K; j++)
        {
            res[i][j] = (i == j);
        }
    }
    while(m > 0)
    {
        if(m & 1)
        {
            res = res * a;
        }
        a = a * a;
        m /= 2;
    }
    return res;
}
map <pair <int, int>, int> num;
queue <pair <int, int> > q;
int get(int u, int v)
{
    if(v > u)
    {
        swap(v, u);
    }
    if(!num.count({v, u}))
    {
        int k = sz(num);
        num[{v, u}] = k;
        q.push({v, u});
    }
    return num[{v, u}];
}
signed main()
{
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n, m;
    cin >> n >> m;
    trie = vector <node> (1, node());
    tot = 1;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        add(s);
    }
    q.push({0, 0});
    num[q.front()] = 0;
    vector <vector <int> > init(K, vector <int> (K, 0));
    while(!q.empty())
    {
        int u = q.front().X;
        int v = q.front().Y;
        q.pop();
        int t = get(u, v);
        for(int c = 0; c < Alph; c++)
        {
            if(trie[u].nxt[c] == -1 || trie[v].nxt[c] == -1)
            {
                continue;
            }
            int a = trie[u].nxt[c];
            int b = trie[v].nxt[c];
            ++init[t][get(a, b)];
            if(trie[a].term)
            {
                ++init[t][get(0, b)];
            }
            if(trie[b].term)
            {
                ++init[t][get(a, 0)];
            }
            if(trie[a].term && trie[b].term)
            {
                ++init[t][get(0, 0)];
            }
        }
    }/*
    cout << sz(num) << "\n";
    for(int i = 0; i < sz(num); i++)
    {
        for(int j = 0; j < sz(num); j++)
        {
            cout << init[i][j] << " ";
        }
        cout << "\n";
    }*/
    init = binpow(init, m);
    cout << init[0][0];
    return 0;
}