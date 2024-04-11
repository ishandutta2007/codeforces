#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, m, c[nax];
vector<int> a[nax];

int main(){
    scanf("%d %d", &n ,&m);

    for(int i = 1; i <= n;i ++){
        for(int j = 1;j <= m; j ++){
            int x;
            scanf("%d", &x);
            a[j].emplace_back(x - j);
        }
    }
    int ans = 0;
    for(int col = 1 ; col <= m ; col++){
        fill(c , c + n, 0);
        int cost = 0, now = 0;
        int ma = 0;
        for(int i = 0 ; i < n;i  ++)
            c[i] = -i;
        for(int i : a[col]){
            if(i % m == 0 && i >= 0 && i <= (n - 1) * m + 1)
            {
                int dist = now - i / m ;
                dist %= n;
                dist = (dist + n) % n;
                c[dist] ++ ;
                ma = max(ma, c[dist]);
            }
            ++ now;
        }
        ans += (n - ma);
       // cerr << ans << endl;
    }
    printf("%d\n", min(n * m, ans));
}
/*
    Good Luck
        -Lucina
*/