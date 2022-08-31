#include <bits/stdc++.h>
 
#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const int max_n = 300111, inf = 1000111222;
 
int n, m;
vector<int> v[max_n];
int sz[max_n];
bool vis[max_n];
//map<pair<int, int>, int> ee;
vector<pair<int, pair<int, int>>> e;
set<pair<int, int>> s;
 
void clr() {
    for (int i = 0; i < n; ++i) {
        v[i].clear();
        vis[i] = 0;
        sz[i] = 0;
    }
    e.clear();
    s.clear();
}
 
bool comp(int a, int b) {
    return v[a].size() < v[b].size();
}
 
void del(int cur) {
    s.erase(s.find(MP(sz[cur], cur)));
    vis[cur] = 1;
    for (int to : v[cur]) {
        if (vis[to]) continue;
        s.erase(MP(sz[to], to));
        sz[to]--;
        s.insert(MP(sz[to], to));
    }
}
 
vector<int> find_is() {
    for (int i = 0; i < n; ++i) {
        s.insert(MP(v[i].size(), i));
    }
    vector<int> inds;
    while (!s.empty()) {
        int cur = s.begin()->S;
        del(cur);
        for (int to : v[cur]) {
            if (!vis[to]) {
                del(to);
            }
        }
        inds.push_back(cur);
        if (inds.size() == n / 3) {
            return inds;
        }
    }
    return vector<int>();
}
 
vector<int> find_mat() {
    while(true) {
        for (int i = 0; i < n; ++i) {
            vis[i] = 0;
        }
        vector<int> mat;
        random_shuffle(e.begin(), e.end());
        for (int i = 0; i < e.size(); ++i) {
            int ind = e[i].F, a = e[i].S.F, b = e[i].S.S;
            if (vis[a] || vis[b]) continue;
            mat.PB(ind);
            vis[a] = vis[b] = 1;
            if (mat.size() == n / 3) {
                return mat;
            }
        }
    }
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        scanf("%d%d", &n, &m);
        n *= 3;
        clr();
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            if (a > b) {
                swap(a, b);
            }
            --a, --b;
            v[a].PB(b);
            v[b].PB(a);
            ++sz[a];
            ++sz[b];
            //ee[MP(a, b)] = i;
            e.PB(MP(i, MP(a, b)));
        }
        vector<int> is = find_is();
        if (is.empty()) {
            vector<int> mat = find_mat();
            if (mat.empty()) {
                exit(228);
            }
            printf("Matching\n");/*
            for (pair<int, int> p : mat) {
                if (p.F > p.S) {
                    swap(p.F, p.S);
                }
                printf("%d ", ee[p] + 1);
            }*/
            for (int p : mat) {
                printf("%d ", p + 1);
            }
        } else {
            printf("IndSet\n");
            for (int p : is) {
                printf("%d ", p + 1);
            }
        }
        printf("\n");
    }
    return 0;
}