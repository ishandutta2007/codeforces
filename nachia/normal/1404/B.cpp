#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int A, B;
int dA, dB;
vector<int> E[100000];
int P[100000];
int Dep[100000];
int D[100000];
int diameter;

void dfs(int p) {
    Dep[p] = 0;
    for (int e : E[p]) {
        if (P[p] == e) continue;
        P[e] = p;
        D[e] = D[p] + 1;
        dfs(e);
        diameter = max(diameter, Dep[p] + Dep[e] + 1);
        Dep[p] = max(Dep[p], Dep[e] + 1);
    }
}

void loop() {
    scanf("%d", &N);
    scanf("%d%d", &A, &B); A--; B--;
    scanf("%d%d", &dA, &dB);
    rep(i, N - 1) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    if (dA * 2 >= dB) { printf("Alice\n"); return; }

    rep(i, N) P[i] = -1;
    diameter = 0;
    D[A] = 0;
    dfs(A);
    if (D[B] <= dA) { printf("Alice\n"); return; }
    if (diameter > dA * 2) { printf("Bob\n"); return; }
    printf("Alice\n");
}

int main() {
    int T; scanf("%d", &T);
    rep(t, T) {
        loop();
        rep(i, N) E[i].clear();
    }
    return 0;
}