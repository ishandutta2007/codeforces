#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
char adj[105][105];
int pred[105];
int ppred[105];

void input(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s", adj[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &pred[i]);
}


bool taken[105];

int main(){
    input();

    bool change;

    do {
        for(int i = 0; i < N; i++)
            ppred[i] = pred[i];

        change = false;
        for(int i = 0; i < N; i++){
            if(!taken[i] && ppred[i] == 0){
                taken[i] = true;
                change = true;
                for(int j = 0; j < N; j++){
                    if(adj[i][j] == '1') pred[j]--;
                }
            }
        }

    } while(change);

    int result = 0;
    for(int i = 0; i < N; i++)
        if(taken[i]) result++;

    printf("%d\n", result);
    for(int i = 0; i < N; i++){
        if(taken[i])
            printf("%d ", i+1);
    }
    printf("\n");
}