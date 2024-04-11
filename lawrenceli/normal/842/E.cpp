#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 300100;
const int maxlg = 20;

int n;
int par[maxn];
vector<int> adj[maxn];

int dep[maxn], jump[maxn][maxlg];

void initlca() {
    for (int k = 0; k + 1 < maxlg; k++)
        for (int i = 1; i <= n; i++)
            jump[i][k + 1] = jump[jump[i][k]][k];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k = maxlg - 1; k >= 0; k--)
        if (dep[jump[b][k]] >= dep[a])
            b = jump[b][k];
    if (a == b) return a;
    for (int k = maxlg - 1; k >= 0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return jump[a][0];
}

int anc(int a, int d) {
    for (int k = maxlg - 1; k >= 0; k--)
        if (d & 1 << k)
            a = jump[a][k];
    return a;
}

//directional vertex of b from a
int dirv(int a, int b) {
    if (a == b) return a;
    int c = lca(a, b);
    if (c != a) return par[a];
    assert(dep[b] > dep[a]);
    return anc(b, dep[b] - dep[a] - 1);
}

int dist(int a, int b) {
    int c = lca(a, b);
    return dep[a] + dep[b] - 2 * dep[c];
}


//v1 and v2 are centers of tree, v2 = -1 if only 1 center
//di = diameter / 2
int di;
int v1, v2;
map<int, int> adj1, adj2;
int sum1, sum2;

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    n++;

    dep[1] = 0;
    jump[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        adj[par[i]].push_back(i);
        jump[i][0] = par[i];
        dep[i] = dep[par[i]] + 1;
    }

    initlca();

    di = 0;
    v1 = 1, v2 = -1;
    adj1[1] = 1, sum1 = 1;

    for (int i = 2; i <= n; i++) {
        //only 1 center
        if (v2 == -1) {
            int d = dist(v1, i);
            int va = dirv(v1, i);
            if (d == di) adj1[va]++, sum1++;
            else if (d > di) {
                assert(d == di + 1);
                if (va == par[v1]) {
                    v2 = va;
                    sum1 -= adj1[va];
                    adj1[va] = 0;
                    int vb = dirv(v2, i);
                    adj2[vb] = 1;
                    sum2 = 1;
                } else {
                    v2 = v1;
                    v1 = va;
                    assert(par[v1] == v2);
                    swap(adj1, adj2);
                    swap(sum1, sum2);
                    sum2 -= adj2[va];
                    adj2[va] = 0;
                    int vb = dirv(v1, i);
                    adj1[vb] = 1;
                    sum1 = 1;
                }
            }
        } else {
            int c = lca(v1, i);
            if (c == v1) { //i in subtree of v1
                int d = dist(v1, i);
                int va = dirv(v1, i);
                if (d == di) adj1[va]++, sum1++;
                else if (d > di) {
                    assert(d == di + 1);
                    di++;
                    v2 = -1;
                    adj1.clear();
                    adj1[va] = 1;
                    sum1 = 1;
                    adj1[par[v1]] = sum2;
                    sum1 += sum2;
                    adj2.clear();
                    sum2 = 0;
                }
            } else {
                int d = dist(v2, i);
                int va = dirv(v2, i);
                if (d == di) adj2[va]++, sum2++;
                else if (d > di) {
                    assert(d == di + 1);
                    di++;
                    int v1b = v1;
                    v1 = v2;
                    v2 = -1;
                    swap(adj1, adj2);
                    swap(sum1, sum2);
                    adj1.clear();
                    adj1[va] = 1;
                    sum1 = 1;
                    adj1[v1b] = sum2;
                    sum1 += sum2;
                    adj2.clear();
                    sum2 = 0;
                }
            }
        }

        cout << sum1 + sum2 << '\n';
    }
}