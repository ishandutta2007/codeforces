#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int c(int x, int v){
    return (x - 1) / v + 1;
}

int main(){
    int T;
    for(cin >> T; T -- ;){
        int n, d;
        scanf("%d %d", &n, &d);
        int q = sqrt(d);
        auto solve = [&]() -> bool{
        for(int j = q ; j >= 1 ; j --){
            if(d % j) continue;
            int u = j, v =q / j;
            /// x + 1 = u
            int res = u - 1 + c(d, u);
            if(res <= n) return true;
            res = v - 1 + c(d , v);
            if(res <= n) return true;
        }
        return false;
        };
        puts(solve() ?"YES" : "NO");
    }

}
/*
    Good Luck
        -Lucina
*/