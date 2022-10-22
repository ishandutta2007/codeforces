#include <bits/stdc++.h>

using namespace std;

namespace Ernest {
vector< vector < int > > g;
void dfs(int x, vector< bool > & us, vector< bool >  &cur, vector< int > & tmp, bool &f)
{
    us[x] = 1;
    cur[x] = 1;
    for (int it : g[x])
    {
        if (cur[it]) f = 1;
        if (!f && !us[it]) dfs(it, us, cur, tmp, f);
    }
    cur[x] = 0;
    tmp.push_back(x);
}
vector< int >  solve()
{
    freopen("input.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int > tl;
    g.assign(n, tl);
    vector< int > course(k);
    for (int i(0); i < k; i++)
    {
        int x; scanf("%d", &x); x--;
        course[i] = x;
    }
    for (int i(0); i < n; i++)
    {
        int s;
        scanf("%d", &s);
        for (int j(0); j < s; j++)
        {
            int x; scanf("%d", &x); x--;
            g[i].push_back(x);
        }
    }
    vector< bool > us(n), cur(n);
    vector<int > ans;
    bool f(0);
    vector< int > er = { -1 };
    for (int i(0); i < k; i++)
    {
        cur.assign(n, 0);
        if (!us[course[i]]) dfs(course[i], us, cur, ans, f);
        if (f) return er;
    }
    for (int i(0); i < ans.size(); i++)
    {
        ans[i]++;
    }
    return ans;

}
}

namespace My {
    int n, k;
    vector< char > important;
    vector< vector< int > > g, gr;
    vector< int > tops;
    vector< char > used;
    vector< int > pos;

    void dfs1(int v) {
        used[v] = 1;
        for(int to : g[v]) {
            if(!used[to]) {
                dfs1(to);
            }
        }
        tops.push_back(v);
    }

    void dfs2(int v, int & cnt, int & have) {
        used[v] = 1;
        cnt++;
        if(important[v]) have = 1;
        for(int to : gr[v]) {
            if(!used[to]) {
                dfs2(to, cnt, have);
            }
        }
    }

    bool check_cycle() {
        used.assign(n + 1, 0);
        for(int i = 1;i <= n;i++) {
            if(!used[i]) {
                dfs1(i);
            }
        }
        reverse(tops.begin(), tops.end());
//        for(int to : tops) cout << to << " ";
//        cout << "ok\n";
        used.assign(n + 1, 0);
        for(int v : tops) {
            if(used[v]) continue;
            int cnt = 0;
            int have = 0;
            dfs2(v, cnt, have);
//            cout << cnt << " " << have << "\n";
            if(cnt > 1 && have) return 1;
        }
        pos.resize(n + 1);
        for(int i = 0;i < (int)tops.size();i++) {
            pos[tops[i]] = i;
        }
        return 0;
    }

    vector< int > dist;

    int const inf = 1000 * 1000 * 1000;

    void bfs() {
        dist.assign(n + 1, inf);
        queue< int > q;
        for(int i = 1;i <= n;i++) {
            if(important[i]) {
                dist[i] = 0;
                q.push(i);
            }
        }
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int to : g[v]) {
                if(dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
    }

    bool cmp(int i, int j) {
        return pos[i] > pos[j];
    }

    vector< int > solve() {
        n = k = 0;
        important.clear();
        g.clear();
        gr.clear();
        tops.clear();
        used.clear();
        dist.clear();
        pos.clear();
//        freopen("input.txt", "r", stdin);
//        ifstream fin("input.txt");
        scanf("%d %d", &n, &k);
//        fin >> n >> k;
        important.resize(n + 1);
        for(int x, i = 1;i <= k;i++) {
            scanf("%d", &x);
//            fin >> x;
            important[x] = 1;
        }
        g.resize(n + 1);
        gr.resize(n + 1);
        for(int sz, i = 1;i <= n;i++) {
            scanf("%d", &sz);
//            fin >> sz;
            g[i].resize(sz);
            for(int & to : g[i]) {
                scanf("%d", &to);
//                fin >> to;
                gr[to].push_back(i);
            }
        }
        bfs();
        vector< int > res;
        for(int i = 1;i <= n;i++) {
            if(dist[i] != inf) {
                res.push_back(i);
                important[i] = 1;
            }
        }
        if(check_cycle()) return vector< int >(1, -1);
        sort(res.begin(), res.end(), cmp);
//        fin.close();
        return res;
    }
}

void print(vector< int > a) {
    if(a.size() == 1 && a[0] == -1) {
        puts("-1");
        return;
    }
    printf("%d\n", (int)a.size());
    for(int x : a) printf("%d ", x);
    printf("\n");
}

void stress1() { // if -1 => ignore else check correct (without minimizing)
    cout << "\nstress1 begin...\n";
    srand(time(NULL));
    for(int n = 1;n <= 100;n++) {
        vector< int > perm;
        for(int i = 1;i <= n;i++) perm.push_back(i);
        int tot = min(n * (n - 1) / 2 / 2, 2 * n);
        for(int m = 0;m <= tot;m++) {
            set< pair< int, int > > edges;
            vector< vector< int > > g(n + 1);
            for(int iter = 0;iter < m;iter++) {
                int u = rand() % n + 1, v;
                while(1) {
                    v = rand() % n + 1;
                    if(u == v || edges.count( make_pair(u, v) )) continue;
                    else break;
                }
                edges.insert( make_pair(u, v) );
                g[v].push_back(u);
            }

            for(int k = 1;k <= n;k++) {
                for(int iter = 0;iter < 10;iter++) {
                    random_shuffle(perm.begin(), perm.end());

                    {
                        ofstream fout("input.txt");
                        fout << n << " " << k << "\n";
                        for(int i = 0;i < k;i++) fout << perm[i] << " ";
                        fout << "\n";
                        for(int i = 1;i <= n;i++) {
                            fout << (int)g[i].size() << " ";
                            for(int j : g[i]) fout << j << " ";
                            fout << "\n";
                        }
                        fout.close();
                    }

                    {
//                        vector< int > result = Ernest::solve();
                        vector< int > result = My::solve();

                        if(result.size() == 1 && result[0] == -1) continue;

                        vector< char > know(n + 1);
                        int ok = 1;

                        for(int x : result) {
                            if(x == -1) { cout << "minus one\n"; ok = 0; break; }
                            if(know[x]) { cout << "already know\n"; k = 0; break; }
                            for(int y : g[x]) {
                                if(!know[y]) { cout << "not know " << y << "\n"; ok = 0; break; }
                            }
                            if(!ok) break;
                            know[x] = 1;
                        }

                        if(!ok) {
                            cout << "Wrong Answer!\n";
                            cout << "input : \n";
                            cout << n << " " << m << " " << k << "\n";
                            for(int i = 0;i < k;i++) cout << perm[i] << " ";
                            cout << "\n";
                            for(int i = 1;i <= n;i++) {
                                cout << (int)g[i].size() << " ";
                                for(int j : g[i]) cout << j << " ";
                                cout << "\n";
                            }
                            cout << "\nYour output : ";
                            for(int x : result) cout << x << " ";
                            cout << "\n";
                            return;
                        }else {
                            cout << "OK " << n << " " << m << " " << k << "\n";
                        }
                    }
                }
            }
        }
    }
}

int main() {

//    stress1();
//    print(Ernest::solve());
    print(My::solve());

    return 0;
}