#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, q, nxt[nax], p[nax][26];
char s[nax];

int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for(int i = 1 ;i <= n ; i ++){
        for(int j = 0 ;j < 26 ;j ++)
            p[i][j] = p[i - 1][j];
        p[i][s[i] - 'a'] ++;
    }
    scanf("%d", &q);
    while(q -- ){
        int x, y;
        scanf("%d %d", &x, &y);
        if(x == y){
            puts("Yes");
            continue;
        }
        if(y - x == 1){
            if(s[x] == s[y]){
                puts("No");
            }
            else puts("Yes");
            continue;
        }
        int c[26], d[26], ct = 0;
        for(int i = 0 ; i < 26 ; i ++)
            c[i] = p[y][i] - p[x - 1][i];
        for(int i = 0 ; i < 26 ; i ++){
            if(c[i] > 0) ct ++;
        }
        /// at least irreducible
        if(ct > 2){
            puts("Yes");
            continue;
        }
        if(ct == 1){
            puts("No");
            continue;
        }
        puts(s[x] == s[y] ? "No" : "Yes");
    }
}