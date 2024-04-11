#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 30005,
          MaxN4 = MaxN*4,
          MaxN8 = MaxN*8;

int N;
int N4, N8;

int ruleA[MaxN4],
    ruleB[MaxN4],
    ruleC[MaxN4];

void input(){
    scanf("%d", &N);
    N4 = N*4;
    N8 = N*8;

    for(int i = 0; i < N4; i++){
        scanf("%d%d%d", &ruleA[i], &ruleB[i], &ruleC[i]);
    }
}

vector<int> revOrder;
int numUsed[MaxN];
vector<int> increasers[MaxN];

void state(){
    for(int i = 1; i <= N; i++){
        printf("%d ", numUsed[i]);
    }
    printf("\n");
}

int main(){
    input();
    fill(numUsed, numUsed+N+1, 8);

    for(int i = 0; i < N4; i++){
        if(ruleA[i] == ruleB[i] || ruleA[i] == ruleC[i]){
            // od razu uzywamy
//            printf("using %d\n", i+1);
            revOrder.push_back(i+1);
            numUsed[ruleA[i]]++;
            numUsed[ruleB[i]]--;
            numUsed[ruleC[i]]--;
        } else {
            increasers[ruleA[i]].push_back(i);
        }
    }
//    state();

    queue<int> currents;
    for(int i = 1; i <= N; i++){
        currents.push(i);
    }

    while(!currents.empty()){
//        printf("[%d]\n", currents.front());
        int x = currents.front();
        auto& vec = increasers[x];
        currents.pop();
        if(numUsed[x] == 9) continue;
        if(vec.size() == 0) continue;

        int increaser = *vec.rbegin();
        vec.pop_back();

        revOrder.push_back(increaser+1);
        int a = ruleA[increaser],
            b = ruleB[increaser],
            c = ruleC[increaser];
        numUsed[a]++;
        numUsed[b]--;
        numUsed[c]--;

        if(vec.size() >= 1 && numUsed[ruleA[increaser]] <= 9){
            currents.push(ruleA[increaser]);
        }
        if(numUsed[b] <= 9) currents.push(b);
        if(numUsed[c] <= 9) currents.push(c);
//        state();
    }

    assert((int)revOrder.size() == N4);

    reverse(revOrder.begin(), revOrder.end());
    printf("YES\n");
    for(int v : revOrder) printf("%d ", v);
    printf("\n");


}