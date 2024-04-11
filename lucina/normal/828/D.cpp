#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int x = (n + k - 2) / k ;
    int y = (n + k - 3) / k;
    printf("%d\n", x + y);
    for(int i = 2; i <= n; i++){
        if(i <=k + 1)printf("1 %d\n", i);
        else printf("%d %d\n", i - k, i);
    }
}