#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 200005;
vector<int> adj[MaxN];
int R[MaxN], L[MaxN], RS[MaxN], LS[MaxN], SZ[MaxN];
int N;

void input(){
	scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int v, int pnt){
    bool isLeaf = (v != 1 && adj[v].size() == 1);
    if(isLeaf){
        R[v] = L[v] = RS[v] = LS[v] = SZ[v] = 1;
        return;
    }

    int totalSize = 0;
    int numChld   = 0;

    for(int s: adj[v]){
        if(s == pnt) continue;
        dfs(s, v);
        totalSize += SZ[s];
        numChld++;
    }

    LS[v] = 1e9;

    for(int s: adj[v]){
        if(s == pnt) continue;
        R[v] = max(R[v], totalSize - SZ[s] + RS[s]);
        RS[v] += R[s];
        L[v] += LS[s];
        LS[v] = min(LS[v], L[s]);
        SZ[v] += SZ[s];
    }

    RS[v] -= (numChld-1);

//    printf("v=%d, tot=%d, chld=%d\n", v, totalSize, numChld);
//    printf("v=%d, R=%d, RS=%d, L=%d, LS=%d\n",
//            v, R[v], RS[v], L[v], LS[v]);
}

int main(){
	input();
    if(N == 1){
        printf("1 1\n");
        return 0;
    }

    dfs(1, 1);
    printf("%d %d\n", R[1], L[1]);
}