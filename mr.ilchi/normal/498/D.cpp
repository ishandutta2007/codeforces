#include <bits/stdc++.h>
using namespace std;

const int mod = 60;
const int MAXN = 100000+10;

int n;
int f[MAXN],a[MAXN];

int go (int v){
    int t = 0;
    while (v<n && t!=mod){
        t+= (t%a[v] == 0) + 1;
        v++;
    }
    if (t > mod)
        return v-1;
    return v;
}

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (int j=0; j<=n; j++)
        f[j] = go(j);
    int q; scanf("%d", &q);
    for (int o=0; o<q; o++){
        char ord; scanf(" %c", &ord);
        int x,y; scanf("%d%d", &x, &y); x--;
        if (ord == 'A'){
            y--;
            int ans = 0;
            while (f[x] < y){
                ans+= mod;
                x = f[x];
            }
            while (x != y){
                ans+= ans%a[x] == 0; ans++;
                x++;
            }
            printf("%d\n", ans);
        }else if (ord == 'C'){
            a[x] = y;
            for (int i=x; i>=0 && f[i]>x; i--)
                f[i] = go(i);
        }
    }
    return 0;
}