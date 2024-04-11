#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
int idx[4 * N];
vector <pair <int, int> > g[5 * N];
pair <int, int> funct(pair <int, int> a, pair <int, int> b){
    if(a.X < b.X){
        return a;
    }
    return b;
}
int a[N], b[N];
void build(int v, int l, int r){
    if(l != r){
        g[v].push_back({v * 2, 0});
        g[v].push_back({v * 2 + 1, 0});
        build(v * 2, l, (r + l) / 2);
        build(v * 2 + 1, (r + l) / 2 + 1, r);
    }
    else{
        idx[v] = l;
        g[v].push_back({4 * N + b[l] + l, 0});
    }
}
void add(int v, int l, int r, int al, int ar, int from){
    if(l >= al && r <= ar){
        g[from].push_back({v, 1});
        return;
    }
    if(l <= ar && r >= al){
        add(v * 2, l, (r + l) / 2, al, ar, from);
        add(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, from);
    }
}
int p[N * 5];
int dist[N * 5];

signed main() {
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];    
    }
    build(1, 0, n);
    for(int i = 1; i <= n; i++){
        add(1, 0, n, i - a[i], i, i + 4 * N);
    }
    deque <int> q;
    fill(dist, dist + 5 * N, 1e9);
    dist[n + 4 * N] = 0;
    q.push_back(n + 4 * N);
    while(sz(q)){
        int v = q.front();
        q.pop_front();
        for(auto to : g[v]){
            if(dist[to.X] > dist[v] + to.Y){
                p[to.X] = v;
                dist[to.X] = dist[v] + to.Y;
                if(to.Y == 0){
                    q.push_front(to.X);
                }
                else{
                    q.push_back(to.X);
                }
            }
        }
    }
    if(dist[4 * N] == 1e9){
        cout << -1;
        return 0;
    }
    vector <int> ans;
    int st = 4 * N;
    while(st != 4 * N + n){
        if(st == 4 * N){
            ans.push_back(st - 4 * N);
        }
        else if(st < 4 * N && idx[st] != 0){
            ans.push_back(idx[st]);
        }
        st = p[st];
    }
    cout << sz(ans) << "\n";
    reverse(ans.begin(), ans.end());
    for(auto v : ans){
        cout << v << " ";
    }
    return 0;
}