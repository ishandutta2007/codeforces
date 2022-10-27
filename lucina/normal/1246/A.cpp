#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n,p;

int main(){
        scanf("%d %d", &n , &p);
        for(int k = 1 ; k <= 50 ; k++){
            int res = n - k * p;
            if(res < 0) break;
            int x = __builtin_popcount(res);
            int y = res;
            if(k >= x && k <= y)return !printf("%d\n", k);
        }
        printf("-1");

}
/*
    Good Luck
        -Lucina
*/