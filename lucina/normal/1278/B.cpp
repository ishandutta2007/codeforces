#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int solve(){
    int a, b ;
    scanf("%d %d", &a, &b);
    if(a > b) swap(a, b);
    int dif = b - a;
    int step = 0, cur = 0;
    for(int i  = 1 ;cur < dif ;i  ++){
        cur += i;
        step ++ ;
    }
    if((cur - dif) % 2 == 0) return step;
    cur += (++ step);
    if((cur - dif) % 2 == 0) return step;
    return step + 1;
}

int main(){
    int T;
    for(cin >> T; T -- ; ){
        printf("%d\n", solve());
    }
}