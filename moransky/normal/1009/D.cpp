#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 100010;
int n, m, tot = 0;
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
vector<int> G[N];

void gcd_prework(){
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(gcd(i, j) == 1){
                 ++tot; G[i].push_back(j);
                 if(tot >= m) return; 
            }   
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);

    if(m < n - 1)
        puts("Impossible");
    else{
        gcd_prework();
        if(tot < m) puts("Impossible");
        else{
            puts("Possible");
            for(int i = 1; i <= n; i++)
                for(int j = 0; j < G[i].size(); j++)
                    printf("%d %d\n", i, G[i][j]);
        }
    }
    return 0;
}