#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int czapa = 2 * 131072;
const int INF = 1e9 + 7;
queue<int> Q;
int position[N];
int n;
int psize[2];
int tab[N][4], wsp[N][4];
pair<int, pair<int, int> > przen[2][N];
pair<int, int> tree[2 * czapa];
int prz[N];
vector<pair<int, int> > V[N];
int odl[N];
bool odw[N];

void treeInsert(int pos, pair<int, int> x) {
    pos += czapa;
    tree[pos] = x;
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
        pos /= 2;
    }
}

pair<int, int> treeQuery(int posa, int posb) {
    posa += czapa;
    posb += czapa;
    pair<int, int> ret = min(tree[posa], tree[posb]);
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret = min(ret, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            ret = min(ret, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &tab[i][j]);
            wsp[i][j] = tab[i][j];
            przen[j % 2][++psize[j % 2]] = {tab[i][j], {i, j}};
        }
    }
    
    sort(przen[0] + 1, przen[0] + psize[0] + 1);
    sort(przen[1] + 1, przen[1] + psize[1] + 1);
    int MAX_X = 0;
    for (int j = 0; j < 2; j++) {
        int in = 0;
        for (int i = 1; i <= psize[j]; i++) {
            if (przen[j][i].first != przen[j][i - 1].first) {
                in++;
            }
            tab[przen[j][i].second.first][przen[j][i].second.second] = in;
        }
        MAX_X = max(MAX_X, in);
    }
    
    
    for (int i = 1; i < 2 * czapa; i++) {
        tree[i] = {INF, 0};
    }
    
    for (int i = 1; i <= n; i++) {
        V[tab[i][0]].push_back({tab[i][1], i});
    }
    
    for (int i = 0; i <= MAX_X; i++) {
        sort(V[i].begin(), V[i].end());
        position[i] = 0;
        if (V[i].size() > 0) {
            treeInsert(i, {V[i][0].first, V[i][0].second});
        }
    }
    
    for (int i = 1; i <= n; i++) {
        odl[i] = INF;
    }
    
    for (int i = 1; i <= n; i++) {
        if (wsp[i][0] == 0 && wsp[i][1] == 0) {
            odw[i] = true;
            odl[i] = 1;
            Q.push(i);
        }
    }
    while(!Q.empty()) {
        int w = Q.front();
        Q.pop();
        while (treeQuery(0, tab[w][2]).first <= tab[w][3]) {
            int x = treeQuery(0, tab[w][2]).second;
            if (!odw[x]) {
                odw[x] = true;
                prz[x] = w;
                odl[x] = odl[w] + 1;
                Q.push(x);
            }
            if (position[tab[x][0]] < V[tab[x][0]].size() - 1) {
                position[tab[x][0]]++;
                treeInsert(tab[x][0], {V[tab[x][0]][position[tab[x][0]]].first, V[tab[x][0]][position[tab[x][0]]].second});
            } else {
                treeInsert(tab[x][0], {INF, 0});
            }
        }
    }
    
    printf("%d\n", odl[n] == INF? -1: odl[n]);
    if (odl[n] != INF) {
        vector<int> ans;
        while(n != 0) {
            ans.push_back(n);
            n = prz[n];
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            printf("%d ", ans[i]);
        }
    }
    return 0;
}