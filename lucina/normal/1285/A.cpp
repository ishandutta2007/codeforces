#include<bits/stdc++.h>
using namespace std;
int l, r;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n; i ++){
        char x;
        scanf(" %c", &x);
        if(x == 'L'){
            l --;
        }
        else r ++;
    }
    printf("%d\n", r - l + 1);
}