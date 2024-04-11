#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
using namespace std;

const int N = 5e5 + 100;
const int T = 350;
const int mod = 998244353;
int dsu[N], rang[N];
int pred(int a){
    if(a == dsu[a]) return a;
    return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b){
     a = pred(a);
     b = pred(b);
     if(rang[a] < rang[b]){
        swap(a, b);
     }
     if(rang[a] == rang[b]){
        rang[a]++;
     }
     dsu[b] = a;
}
signed main(){
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> c_all(k);
    for(int i = 0; i < n; i++){
        dsu[i] = i;
        rang[i] = 1;
    }
    vector <int> last(k, -1);
    vector <int> bad(k,0);
    vector <vector <int> > start(k);
    vector <vector <int> > v(n);
    vector <vector <int> > nxt(k), prv(k);
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        set <int> st;
        for(int j = 0; j < t; j++)
        {
            int x;
            cin >> x;
            x--;
            st.insert(x);
            c_all[x] = 1;
            v[i].push_back(x);
        }
        if(sz(st) != sz(v[i])){
            for(auto g : v[i]){
                bad[g] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < sz(v[i]) - 1; j++){
            nxt[v[i][j]].push_back(v[i][j + 1]);
            prv[v[i][j + 1]].push_back(v[i][j]);
        }
    }
    vector <int> sizes;
    vector <bool> used(k);
    for(int i = 0; i < k; i++)
    {
        sort(nxt[i].begin(), nxt[i].end());
        sort(prv[i].begin(), prv[i].end());
        nxt[i].resize(unique(nxt[i].begin(), nxt[i].end()) - nxt[i].begin());
        prv[i].resize(unique(prv[i].begin(), prv[i].end()) - prv[i].begin());
    }
    for(int i = 0; i < k; i++){
        if(used[i]){
            continue;
        }
        int st = i;
        queue <int> q1, q2;
        int fl = 1;
        q1.push(st);
        vector <int> cmp;
        while(sz(q1)){
            int v = q1.front();
            q1.pop();
            cmp.push_back(v);
            used[v] = 1;
            for(auto to : nxt[v]){
                if(!used[to]){
                    used[to] = 1;
                    q1.push(to);
                }
            }
            for(auto to : prv[v]){
                if(!used[to]){
                    used[to] =1;
                    q1.push(to);
                }
            }
        }
        int coun = 0;
        for(auto v : cmp){
            if(sz(prv[v]) == 0){
                coun++;
            }
            if(sz(prv[v]) > 1 || sz(nxt[v]) > 1 || bad[v]){
                fl = 0;
            }
        }
        used[i] = 1;
        if(fl && coun != 0){
            sizes.push_back(sz(cmp));
        }
    }
    sort(sizes.begin(), sizes.end());
    vector <pair <int, int> > sizes1;
    for(int i = 0; i < sz(sizes); i++){
        int j = i;
        while(j + 1 < sz(sizes) && sizes[j + 1] == sizes[i]){
            j++;
        }
        sizes1.push_back({sizes[i], j - i + 1});
        i = j;
    }
    vector <int> dp(m + 1);
    dp[0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < sz(sizes1); j++){
            if(sizes1[j].X + i > m){
                continue;
            }
            dp[i + sizes1[j].X] = (dp[i + sizes1[j].X] + 1LL * dp[i] * sizes1[j].Y) % mod;
        }
    }
    cout << dp[m];
    return 0;
}