#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
/**
1
5 5
3 1 2 4 5
1 2 3 4 5
*/

int const nax = 3e5 + 10;
int n, m, a[nax], b[nax];
ll solve(){
    scanf("%d %d", &n ,&m);
    for(int i = 1; i <= n; i ++)
        scanf("%d", a + i);
    for(int i = 1; i <= m ;i ++)
        scanf("%d", b + i);
    set<int> s;
    ll ans = 0;
    int pt = 1;
    for(int i = 1; i <= m; i ++){
        if(s.count(b[i])){
            ans ++;
            s.erase(b[i]);
            continue;
        }
        ans += (int)s.size() * 2;
        while(pt <= n && a[pt] != b[i]){
            s.insert(a[pt ++]);
            ans += 2;
        }
        ans ++;
        pt ++;
    }
    return ans;
}

int main(){
    int T;
    for(cin >> T; T -- ; ){
        printf("%lld\n", solve());
    }
}
/**
    Good Luck
        -Lucina
*/