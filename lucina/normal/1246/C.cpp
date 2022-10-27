#include<bits/stdc++.h>
using namespace std;
int const mod = 1e9 + 7;
void plusle(int &a, int b){
    if((a += b) >= mod) a -= mod;
}
void minun(int &a, int b){
    if((a -= b) < 0) a += mod;
}
int add(int a, int b){
    return ((a += b) >= mod) ? a - mod : a;
}
int sub(int a, int b){
    return ((a -= b) < 0) ? a + mod : a;
}
int const nax = 2005;
int n, m;
char s[nax][nax];
int r[nax][nax], d[nax][nax];
int rs[nax][nax], cs[nax][nax];

/**
r[i][j] the number of ways to walk from (1, 1) to (i, j)
such that last direction is r and (i, j) is turning point;
d[i][j] is the same but downward
*/


int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1 ;i <= n; i ++){
        scanf("%s", s[i] + 1);
    }

    if(n == 1 && m == 1) return !printf("1");
    for(int i = 1 ; i <= n ; i ++){
        for(int j = m ; j >= 1 ;j --){
            rs[i][j - 1] = rs[i][j] + (s[i][j] == 'R');
        }
    }
    for(int j = 1 ; j <= m ; ++ j ){
        for(int i = n ; i >= 1 ; i --)
            cs[i - 1][j] = cs[i][j] + (s[i][j] == 'R');
    }
    r[1][1] = 1;
    d[1][1] = 1;

    minun(d[2][1], 1);
    minun(r[1][2], 1);
    for(int i = 1 ;i <= n ; i ++){
        for(int j = 1 ; j <= m ; j ++){
            plusle(r[i][j], r[i][j - 1]);
            plusle(d[i][j], d[i - 1][j]);
            int last = m + 1 - rs[i][j];
            plusle(r[i][j + 1], d[i][j]);
            minun(r[i][last], d[i][j]);
            last = n + 1 - cs[i][j];
            plusle(d[i + 1][j], r[i][j]);
            minun(d[last][j], r[i][j]);
        }
    }
    printf("%d\n", add(r[n][m], d[n][m]));
    /// very hard to implement for some reason...
}