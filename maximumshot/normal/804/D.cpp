#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;
int const SQRT = 320;

int n, m, q;
vec< int > g[N];

void readGraph() {
    scanf("%d %d %d", &n, &m, &q);
    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

bool isTree[N];
int cid[N];
bool used[N];
int mx[N];
int dn[N];
int cntv[N];
vec< int > arr[N];
vec< ll > pref[N];
int cur = 1;

void go1(int v, int par = -1) {
    dn[v] = 0;
    for(int to : g[v]) {
        if(to == par) continue;
        go1(to, v);
        dn[v] = max(dn[v], dn[to] + 1);
    }
}

void go2(int v, int up = 0, int par = -1) {
    int mx1 = -10;
    int mx2 = -10;
    mx[v] = max(up, dn[v]);
    for(int to : g[v]) {
        if(to == par) continue;
        if(mx1 < dn[to]) {
            mx2 = mx1;
            mx1 = dn[to];
        }else if(mx2 < dn[to]) {
            mx2 = dn[to];
        }
    }
    for(int to : g[v]) {
        if(to == par) continue;
        int tmp = up;
        if(mx1 == dn[to]) tmp = max(tmp, mx2 + 1);
        else tmp = max(tmp, mx1 + 1);
        go2(to, tmp + 1, v);
    }
}

void buildComponents() {
    for(int i = 1;i <= n;i++) {
        used[i] = 0;
    }
    queue< int> que;
    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        que.push(i);
        used[i] = 1;
        cid[i] = cur;
        cntv[cur] = 1;
        int cnte = (int)g[i].size();
        vec< int > List;
        List.push_back(i);
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            for(int to : g[v]) {
                if(!used[to]) {
                    used[to] = 1;
                    cid[to] = cur;
                    que.push(to);
                    cntv[cur]++;
                    cnte += (int)g[to].size();
                    List.push_back(to);
                }
            }
        }
//        cout << cur << " : ";
//        for(int x : List) {
//            cout << x << " ";
//        }
//        cout << "\n";
        cnte /= 2;
        isTree[cur] = cnte == cntv[cur] - 1;
        if(isTree[cur]) {
//            cout << "Tree !\n";
            go1(i);
            go2(i);
            ll cur_pref = 0;
            for(int v : List) {
                arr[cur].push_back(mx[v]);
            }
            sort(ALL(arr[cur]));
            for(int x : arr[cur]) {
                cur_pref += x;
                pref[cur].push_back(cur_pref);
            }
//            for(int x : arr[cur]) cout << x << " ";
//            cout << " | ";
//            for(int x : pref[cur]) cout << x << " ";
//            cout << "\n";
        }
        cur++;
    }
}

bool alreadyAns[N];
double answer[N];
vec< pii > query[N];

void readQuestions() {
    for(int v, u, iter = 0;iter < q;iter++) {
        scanf("%d %d", &u, &v);
        if(cid[u] == cid[v]) {
            alreadyAns[iter] = 1;
            answer[iter] = -1.0;
        }else if(!isTree[cid[u]] || !isTree[cid[v]]) {
            alreadyAns[iter] = 1;
            answer[iter] = -1.0;
        }else {
            if(cntv[cid[u]] > cntv[cid[v]]) swap(u, v);
            query[cid[u]].push_back(make_pair(cid[v], iter));
//            vec< int > & arr1 = arr[cid[u]];
//            vec< int > & arr2 = arr[cid[v]];

//            ll tot_sum = 0;
//            ll tot_cnt = 1ll * arr1.size() * arr2.size();

//            int D = max(arr1.back(), arr2.back());

//            for(int m1 : arr1) {
//                for(int m2 : arr2) {
//                    tot_sum += max(D, m1 + m2 + 1);
//                }
//            }

//            answer[iter] = 1.0 * tot_sum / tot_cnt;
        }
    }
    for(int i = 1;i <= n;i++) {
        sort(ALL(query[i]));
    }
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    readGraph();
    buildComponents();
    readQuestions();

//    for(int iter = 1;iter < cur;iter++) {
//        cout << iter << " : ";
//        for(pii x : query[iter]) {
//            cout << "{ " << x.first << ", " << x.second << "} ";
//        }
//        cout << "\n";
//    }

    for(int iter = 1;iter < cur;iter++) {
        if(cntv[iter] < SQRT) {
            for(int j = 0;j < (int)query[iter].size();j++) {
                int t = j;
                while(t < (int)query[iter].size() && query[iter][j].first == query[iter][t].first) t++;
                t--;
                vec< int > & arr1 = arr[iter];
                vec< int > & arr2 = arr[query[iter][j].first];

//                cout << iter << " v " << query[iter][j].first << " ??\n";
//                for(int x : arr1) cout << x << " ";
//                cout << " | ";
//                for(int x : arr2) cout << x << " ";
//                cout << "\n";

                int D = max(arr1.back(), arr2.back());
                ll tot = 0;
                ll tot_cnt = 0;
                for(int m1 : arr1) {
                    int id = upper_bound(ALL(arr2), D - 1 - m1) - arr2.begin();
                    // id .. end
//                    cout << m1 << " * " << id << "\n";
                    if(id < (int)arr2.size()) {
                        tot += pref[query[iter][j].first].back() -
                                (id > 0 ? pref[query[iter][j].first][id - 1] : 0ll);
                        tot += 1ll * (m1 + 1) * ((int)arr2.size() - id);
                        tot_cnt += (int)arr2.size() - id;
                    }
                }
//                cout << tot << "  " << tot_cnt << " !!\n";
                tot += 1ll * (1ll * (int)arr1.size() * (int)arr2.size() - tot_cnt) * D;
                double cur_ans = 1.0 * tot / (1.0 * (int)arr1.size() * (int)arr2.size());
                for(int qid, it = j;it <= t;it++) {
                    qid = query[iter][it].second;
                    alreadyAns[qid] = 1;
                    answer[qid] = cur_ans;
                }

                j = t;
            }
        }else {
            for(int j = 0;j < (int)query[iter].size();j++) {
                int t = j;
                while(t < (int)query[iter].size() && query[iter][j].first ==
                      query[iter][t].first) t++;
                t--;
                vec< int > & arr1 = arr[iter];
                vec< int > & arr2 = arr[query[iter][j].first];

                int D = max(arr1.back(), arr2.back());
                ll tot = 0;
                ll tot_cnt = 0;

//                cout << iter << " v " << query[iter][j].first << " ??\n";
//                for(int x : arr1) cout << x << " ";
//                cout << " | ";
//                for(int x : arr2) cout << x << " ";
//                cout << "\n";

                for(int m2 : arr2) {
                    int id = upper_bound(ALL(arr1), D - 1 - m2) - arr1.begin();
                    if(id < (int)arr1.size()) {
                        tot += pref[iter].back() - (id > 0 ? pref[iter][id - 1] : 0);
                        tot += 1ll * (m2 + 1) * ((int)arr1.size() - id);
                        tot_cnt += (int)arr1.size() - id;
                    }
                }
                tot += 1ll * (1ll * (int)arr1.size() * (int)arr2.size() - tot_cnt) * D;
                double cur_ans = 1.0 * tot / (1.0 * (int)arr1.size() * (int)arr2.size());
                for(int qid, it = j;it <= t;it++) {
                    qid = query[iter][it].second;
                    alreadyAns[qid] = 1;
                    answer[qid] = cur_ans;
                }

                j = t;
            }
        }
    }

    for(int i = 0;i < q;i++) {
        printf("%.10lf\n", answer[i]);
    }

    return 0;
}