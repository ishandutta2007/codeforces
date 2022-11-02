#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cassert>
#include <ios>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int maxn = 200100;

int n, m, MO[9][9], M[9][9], num[9];
int pw10[9];
pii ans[maxn]; int anscnt;

int cap[99][99];
int flow[99], from[99];

//use max flow to find match
void process2() {
    memset(cap, 0, sizeof(cap));
    int vs = 97, vt = 98;
    int cnt = m;
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++) {
            cap[vs][cnt] = cap[cnt][i] = cap[cnt][j] = M[i][j];
            cnt++;
        }

    int wantf = 0;
    for (int i = 0; i < m; i++)
        cap[i][vt] = num[i] - 1, wantf += num[i] - 1;
    
    int totf = 0;
    while (1) {
        queue<piii> Q;
        Q.emplace(pii(vs, -1), 1e9);
        memset(flow, -1, sizeof(flow));

        while (!Q.empty()) {
            int v = Q.front().A.A, p = Q.front().A.B, f = Q.front().B;
            Q.pop();
            if (flow[v] != -1) continue;
            flow[v] = f;
            from[v] = p;
            if (v == vt) break;
            for (int i = 0; i < 99; i++)
                if (cap[v][i])
                    Q.emplace(pii(i, v), min(f, cap[v][i]));
        }

        if (flow[vt] == -1) break;

        totf += flow[vt];
        int v = vt;
        while (v != vs) {
            int w = from[v];
            cap[w][v] -= flow[vt];
            cap[v][w] += flow[vt];
            v = w;
        }
    }

    //cout << totf << endl;

    if (totf != wantf) return;

    cnt = m;
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++) {
            int a = cap[i][cnt], b = cap[j][cnt];
            assert(a + b == M[i][j]);
            for (int k = 0; k < a; k++)
                ans[anscnt++] = pii(pw10[i] + num[i] - 1, pw10[j]), num[i]--;
            for (int k = 0; k < b; k++)
                ans[anscnt++] = pii(pw10[j] + num[j] - 1, pw10[i]), num[j]--;
            cnt++;
        }

    assert(anscnt == n - 1);
    for (int i = 0; i < anscnt; i++)
        cout << ans[i].A << ' ' << ans[i].B << '\n';

    exit(0);
}

int T[9];
int sts[9], occ[9];

//process encoded spanning tree
void process() {
    int anscnto = anscnt;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            M[i][j] = MO[i][j];

    if (m == 2) {
        M[0][1]--;
        ans[anscnt++] = pii(1, 10);
    } else if (m > 2) {
        for (int i = 0; i < m; i++) sts[i] = 1;
        memset(occ, 0, sizeof(occ));
        for (int i = 0; i < m - 2; i++) sts[T[i]] = 0, occ[T[i]]++;
        
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < m; j++)
                if (sts[j]) {
                    M[min(j, T[i])][max(j, T[i])]--;
                    ans[anscnt++] = pii(pw10[j], pw10[T[i]]);
                    occ[T[i]]--;
                    if (occ[T[i]] == 0) sts[T[i]] = 1;
                    sts[j] = 0;
                    break;
                }
        }

        int x = -1;
        for (int i = 0; i < m; i++) {
            if (sts[i]) {
                if (x == -1) x = i;
                else M[x][i]--, ans[anscnt++] = pii(pw10[x], pw10[i]);
            }
        }
    }

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (M[i][j] < 0) {
                anscnt = anscnto;
                return;
            }

    process2();
    anscnt = anscnto;
}

void search(int x) {
    if (x >= m - 2) {
        process();
    } else {
        for (int i = 0; i < m; i++) {
            T[x] = i;
            search(x + 1);
        }
    }
}

int dig(int x) { int ret = -1; while (x) ret++, x /= 10; return ret; }

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        num[dig(i)]++, m = max(m, dig(i) + 1);

    pw10[0] = 1;
    for (int i = 1; i < 9; i++) pw10[i] = pw10[i - 1] * 10;

    for (int i = 0; i < n - 1; i++) {
        string a, b;
        cin >> a >> b;
        int x = a.length() - 1, y = b.length() - 1;
        if (x == y) {
            if (num[x] == 1) {
                cout << "-1\n";
                return 0;
            } else ans[anscnt++] = pii(pw10[x], pw10[x] + num[x] - 1), num[x]--;
        } else MO[min(x, y)][max(x, y)]++;
    }
/*
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cout << MO[i][j] << ' ';

    cout << num[0] << ' ' << num[1] << ' ';
*/
    search(0);
    
    cout << "-1\n";
}