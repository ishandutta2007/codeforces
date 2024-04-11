#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 200005;

int N;
int tab[MaxN];

void input(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &tab[i]);
    }
}

int main(){
    input();

    for(int i = 0; i < N; i++){
        tab[i] += i;
    }

    sort(tab, tab+N);

    for(int i = 0; i < N; i++){
        tab[i] -= i;
    }

    for(int i = 0; i < N-1; i++){
        if(tab[i] > tab[i+1]){
            printf(":(\n");
            return 0;
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}