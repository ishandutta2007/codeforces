#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int K, N;
int O;

void input(){
    scanf("%d%d", &N, &K);
    O = 0;
    for(int i = 0; i < N; i++){
        int v;
        scanf("%d", &v);
        if(v % 2 == 1) O++;
    }
}

void even(){
    printf("Daenerys\n");
    exit(0);
}

void odd(){
    printf("Stannis\n");
    exit(0);
}

int main(){
    input();

    int moves = N-K;
    int movesSt = (moves+1)/2,
        movesDa = (moves)/2;
    if(O == 0){
        even();
    }
    if(O == N){
        if(K % 2 == 0)
            even();
        else
            odd();
    }

    if(K == N){
        if(O % 2 == 0) even(); else odd();
    }

    if(O <= movesDa){
        even();
    }

    if(N-O <= movesSt && K % 2 == 1){
        odd();
    }

    if(N-O <= movesDa && K % 2 == 0){
        even();
    }


    if(moves % 2 == 0){
        even();
    } else {
        odd();
    }
}