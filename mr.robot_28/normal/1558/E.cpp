#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sz(a) (int)a.size()
#define X first
#define Y second
const int N = 1e3 + 100;

int n, m;
int a[N], b[N];
vector <int> g[N];
int p[N], dp[N];

bool go(int v, int v1, int midd){
    if(a[v1] >= midd){
        return false;
    }
    for(int i = 0; i < n; i++){
        p[i] = -1;
        dp[i] = 0;
    }
    dp[v1] = midd;
    vector <bool> used(n);
    queue <int> q;
    q.push(v1);
    p[v1] = v;
    used[v1] = 1;
    used[v] = 1;
    while(sz(q)){
        int cur = q.front();
        q.pop();
        for(auto to : g[cur]){
            if(used[to] && p[cur] != to){
                return true;
            }
            if(dp[cur] + b[cur] <= a[to]){
                continue;
            }
            if(p[cur] == to){
                continue;
            }
            assert(!used[to]);
            dp[to] = dp[cur] + b[cur];
            used[to] = 1;
            p[to] = cur;
            q.push(to);
        }
    }
    return false;
}

int genious(){
    map <pair <int, int>, int> mp;
    for(int v = 0; v < n; v++){
        for(auto to : g[v]){
            int l = -1, r = 1e9 + 1;
            while(r - l > 1){
                int midd = (r + l) / 2;
                if(go(v, to, midd)){
                    r = midd;
                }
                else{
                    l = midd;
                }
            }
            mp[{v, to}] = r;
  //          cout << v << " " << to << " ";
    //        cout << mp[{v, to}] << "\n";
        }
    }
    int l = -1, r = 1e9 + 1;
    while(r - l > 1){
        int midd = (r + l) / 2;
        vector <bool> used(n);
        priority_queue <pair <int, int> > q;
        q.push({0, 0});
        int sum = midd;
     //   cout << "A " << midd << "\n";
        while(sz(q)){
            pair <int, int> cur = q.top();
            q.pop();
            cur.X = -cur.X;
            if(cur.X > sum){
                break;
            }
            if(used[cur.Y]){
                continue;
            }
            sum += b[cur.Y];
            used[cur.Y] = 1;
             for(auto to : g[cur.Y]){
                if(used[to]){
                    continue;
                }
                q.push({-mp[{cur.Y, to}], to});
            }
        }
        bool flag = 1;
        for(int i = 0; i < n; i++){
            if(!used[i]){
                flag = 0;
            }
        }
        if(!flag){
            l = midd;
        }
        else{
            r = midd;
        }
    }
    return r;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i < n; i++){
            cin >> a[i];
        }
        for(int i = 1; i < n; i++){
            cin >> b[i];
        }
        map <pair <int, int>, int> have;
        for(int i = 0; i < m; i++){
            int from, to;
            cin >> from >> to;
            from--;
            to--;
            g[from].push_back(to);
            g[to].push_back(from);
        }
        cout << genious() << "\n";
        for(int i = 0; i < n; i++){
            g[i].clear();
        }
    }
    return 0;
}