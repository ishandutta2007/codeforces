#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int a[nax], n, p, k;

void solve(){
    scanf("%d %d %d", &n, &p, &k);
    for(int i = 1; i <= n ;i ++)
        scanf("%d", a + i);
    sort(a + 1 , a + 1 + n);
    int ans = 0, sum = 0;
    for(int l = 0 ; l < k ; l ++){
        sum += a[l];
        int res = sum;
        if(res <= p) ans = max(ans, l);
        for(int j = l + k ,cnt = 1; j <= n ; j += k, ++ cnt){
            if(res + a[j] > p) break;
            res += a[j];
            ans = max(ans, cnt * k +  l);
        }
    }
    printf("%d\n", ans);
}

int main(){
    int T;
    for(cin >> T; T -- ; solve());
}