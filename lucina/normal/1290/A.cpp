#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int const inf = 1e9 + 7;
int n, m, a[nax], k;
int solve(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1 ; i <= n; i ++){
        scanf("%d", a + i);
    }
    if(m <= k){
        k = m - 1;
    }
    int ans = 0;
    for(int j = 0 ; j <= k; j ++){
        int res = m - k - 1;
        int first = j + 1;
        int last = n - k + j;
        if(first > last) continue;
     //   fprintf(stderr, "first = %d Last = %d\n", first, last);
        int now = inf;
        for(int v = 0 ; v <= res ; v ++){
            if(first + v <= last - (res - v)){
                now = min(now, max(a[first + v], a[last - (res - v)]));
            }
        }
    //    fprintf(stderr, "now = %d\n", now);
        if(now != inf)
        ans = max(ans, now);
    }
    return ans;
}


int main(){
    int t;
    for(cin >> t ; t --; ){
        printf("%d\n", solve());

    }
}
/*
    Good Luck
        -Lucina
*/