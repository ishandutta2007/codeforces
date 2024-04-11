#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, a[nax];
int solve(){
    scanf("%d", &n);
    for(int i = 1 ;i <= n * 2 ; i++){
        scanf("%d", a + i );
    }
    map<int, int> bal;
    int cur = 0, ans = 2 * n;
    bal[0] = n;
    for(int i = 1 ;i <= n; i ++ ){
        cur += a[i] == 1 ? 1 : -1;
        bal[cur] = n - i;
    //    printf("%d ", cur);
    }
    //printf("\n");
    cur = 0;
    if(bal.count(0)){
        ans = min(ans, bal[0] + 2 * n + 1 - n - 1);
    }
    for(int i = 2 * n ;i > n ;i  --){
        cur += a[i] == 1 ? 1 : -1;
        if(bal.count(-cur)){
            ans = min(ans, bal[-cur] + i - n - 1);
        }
    }
    return ans;

}

int main(){
    int T;
    for(scanf("%d", &T) ; T -- ; ){
        printf("%d\n", solve());
    }

}