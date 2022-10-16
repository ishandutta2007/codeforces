#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 200010, M = 50010;
char s[N], t[N];
int n, m, sum[N][26], g[26], len;
//[1, x]
bool inline check(int x){
    for(int i = 0; i < 26; i++)
        if(sum[x][i] < g[i]) return false;
 
    return true;
}
int main(){
    scanf("%d%s%d", &n, s + 1, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++) sum[i][j] = sum[i - 1][j];
        sum[i][s[i] - 'a']++;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < 26; j++) g[j] = 0;
        scanf("%s", t + 1); 
        len = strlen(t + 1);
        for(int i = 1; i <= len; i++) g[t[i] - 'a']++;


        int l = 1, r = n;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", r);
    }
    return 0;
}