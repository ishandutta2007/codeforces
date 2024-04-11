#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int a[20];
LL dp[20][5];
LL dfs(int pos, int st, bool limit){
    if(pos == -1) return 1;
    if((!limit) && dp[pos][st]) return dp[pos][st];
    int up = limit ? a[pos] : 9;
    LL res = 0;
    for(int i = 0; i <= up; i++){
        if(!i) res += dfs(pos - 1, st, limit && i == a[pos]);
        else if(st != 3) res += dfs(pos - 1, st + 1, limit && a[pos] == i);
    }

    if(!limit) dp[pos][st] = res;
    return res;
}
LL work(LL x){
    int tot = 0;
    while(x) a[tot++] = x % 10, x /= 10;
    return dfs(tot - 1, 0, true);
}
int main(){
    int T; scanf("%d", &T);
    while(T--){
        LL l, r; cin >> l >> r;
        cout << work(r) - work(l - 1) << endl;
    }
    return 0;
}