#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, a[nax];

void solve(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", a + i);
        a[i] -= i;
    }
    for(int i = 2 ; i <= n ;i ++){
        if(a[i] >= a[i - 1] + 1){
            printf("YES\n");
            printf("%d %d\n", i - 1 , i);
            return ;
        }
    }
    for(int i = 1 ;i <= n; i ++){
        a[i] += 2 * i;
    }
    for(int i = 2 ; i <= n ;i ++){
        if(a[i] + 1 <= a[i - 1]){
            printf("YES\n");
            printf("%d %d\n", i - 1 , i);
            return ;
        }
    }
    printf("NO\n");
}

int main(){
    int t;
    for(cin >> t ; t -- ; solve()){


    }
}
/*
    Good Luck
        -Lucina
*/