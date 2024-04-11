#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N, M;

void input(){
	scanf("%d%d", &N, &M);
}

int main(){
	input();
    if(N > M) swap(N, M);

    if(N == 1){
        printf("%d\n", M);
    } else if(N == 2){
        printf("%d\n", 2*(2*((M+2)/4)+(M%4==1)));
    } else {
        printf("%d\n", (M*N+1)/2);
    }
}