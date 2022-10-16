#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
typedef long long LL;
using namespace std;
const int N = 105, L = 26;
int n;
LL k, f[N][N][L], s[N][N], ans = 0;
//s[i][j]ij
//f[i][j][c]ijc
char str[N];
int main(){
    scanf("%d%lld%s", &n, &k, str + 1);
    for(int i = 1; i <= n; i++){
        f[i][1][str[i] - 'a'] = 1; 
        for(int j = 1; j <= n; j++){
            for(int c = 0; c < 26; c++){
                if(c + 'a' == str[i]) f[i][j][c] += s[i - 1][j - 1];
                else f[i][j][c] += f[i - 1][j][c];
                if(f[i][j][c] > k) f[i][j][c] = k;
                s[i][j] += f[i][j][c];
            }
            if(s[i][j] > k) s[i][j] = k;
        }
    }
    s[n][0] = 1;
    //
    for(int i = n; ~i; i--){
        if(s[n][i] > k){
            ans += (n - i) * k;
            k = 0;
            break;
        }
        ans += (n - i) * s[n][i];
        k -= s[n][i];
    }
    if(k) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}