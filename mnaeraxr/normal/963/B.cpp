#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

vector<int> adj[maxn];
int position[maxn];
int who[maxn];
int mark[maxn];
int deg[maxn];
int total;

void post(int s, int p=0){
    for (auto u : adj[s]){
        if (u == p)
            continue;
        post(u, s);
    }

    who[total] = s;
    position[s] = total;
    total++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 1; i <= n; ++i){
        int p;
        cin >> p;

        if (p == 0) continue;

        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    post(1);

    set<int> good;

    for (int i = 1; i <= n; ++i){
        deg[i] = ((int)adj[i].size()) & 1;
        if (deg[i] == 0)
            good.insert(position[i]);
    }

    vector<int> answer;

    while (!good.empty()){
        int p = *good.begin();
        good.erase(p);
        answer.push_back(who[p]);

        int u = who[p];
        mark[u] = true;

        for (auto v : adj[u]){
            if (mark[v]) continue;

            deg[v] ^= 1;

            if (deg[v] == 0)
                good.insert(position[v]);
            else
                good.erase(position[v]);
        }
    }

    if (answer.size() == n){
        cout << "YES" << endl;
        for (auto u : answer)
            cout << u << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}