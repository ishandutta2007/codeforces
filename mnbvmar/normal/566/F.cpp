#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 1000005;

int N;
int tab[MaxN];
int res[MaxN];
int nCount[MaxN];

void input(){
    scanf("%d", &N);
    fill(nCount, nCount+1000001, -1);
    for(int i = 0; i < N; i++){
        int v;
        scanf("%d", &v);
        tab[i] = v;
        assert(nCount[v] == -1);
        nCount[v] = i;
    }
}

int main(){
    input();
    fill(res, res+N, 1);
    int M = 1000000;
    int total = 1;
    for(int i = 0; i < N; i++){
        int val = tab[i];
        for(int vval = val*2; vval <= M; vval += val){
            if(nCount[vval] == -1) continue;
            res[nCount[vval]] = max(res[nCount[vval]], res[i]+1);
            total = max(total, res[nCount[vval]]);
        }
    }
    printf("%d\n", total);
}