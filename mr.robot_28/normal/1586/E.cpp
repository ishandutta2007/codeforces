#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;
int dsu[N];
int rang[N];
int weight[N];
vector <pair <int, int> > g[N];
int pred(int a){
    if(dsu[a] == a) return a;
    return dsu[a] = pred(dsu[a]);
}
int timer = 0;
int tin[N], tout[N];
void unite(int a, int b){
    a = pred(a);
    b = pred(b);
    if(rang[a] > rang[b]){
        swap(a, b);
    }
    dsu[a] = b;
    rang[b] += rang[a];
}
int up[N];
const int T = 20;
bool pred(int a, int b){
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
void dfs(int v, int p = -1){
    tin[v] = timer++;
    for(auto to : g[v]){
        if(to.X != p){
            up[to.X] = v;
            dfs(to.X, v);
        }
    }
    tout[v] = timer - 1;
}
int ans = 0;
int n, m;
void dfs1(int v, int a, int b, int p =- 1){
    for(int i = 0; i < sz(g[v]); i++){
        if(g[v][i].X == p){
            continue;
        }
        auto to = g[v][i];
        dfs1(to.X, a, b, v);
        if(pred(to.X, a) ^ pred(to.X, b)){
            g[v][i].Y++;
        }
    }
}
int dfs2(int v, int p = -1, int pw = 0){
    int c = 0;
    for(auto to : g[v]){
        if(to.X == p){
            continue;
        }
     //   cout << v << " " << to.X << " " << to.Y << "\n";
        c += dfs2(to.X, v, to.Y);
    }
    if(pw % 2 == 1){
        ans += c / 2;
        return 1;
    }
    else{
        ans += (c + 1) / 2;
        return 0;
    }
}
signed main() {
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        dsu[i] = i;
        rang[i] = 1;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(pred(a) != pred(b))
        {
            unite(a, b);
            g[a].push_back({b, 0});
            g[b].push_back({a, 0});
        }
    }
    dfs(0);
    int q;
    cin >> q;
    vector <pair <int, int> > queries1;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        dfs1(0, a, b);
        queries1.push_back({a, b});
    }
    ans += dfs2(0);
    if(ans != 0){
        cout << "NO\n";
        cout << ans;
    }
    else{
        cout << "YES\n";
        for(auto v : queries1){
            vector <int> vec1, vec2;
            while(!pred(v.X, v.Y)){
                vec1.push_back(v.X);
                v.X = up[v.X];
            }
            vec1.push_back(v.X);
            while(!pred(v.Y, v.X)){
                vec2.push_back(v.Y);
                v.Y = up[v.Y];
            }
            reverse(vec2.begin(), vec2.end());
            cout << sz(vec1) + sz(vec2) << "\n";
            for(auto v1 : vec1){
                cout << v1 + 1 << " ";
            }
            for(auto v1 : vec2){
                cout << v1 + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}