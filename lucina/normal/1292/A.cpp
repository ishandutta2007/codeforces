/**
..#.#.#.#
 
*/
#include<stdio.h>
int const nax = 3e5 + 10;
int n, q, sr, cc;
bool b[2][nax];
 
int main(){
    scanf("%d %d", &n, &q);
    
    for(; q -- ; ){
        int x, y;
        scanf("%d %d", &x, &y);
        x -- ;
        if(b[x][y]){
            if(b[x ^ 1][y]) sr --;
            if(y < n && b[x ^ 1][y + 1]) cc --;
            if(y > 1 && b[x ^ 1][y - 1]) cc --;
        }
        else{
            if(b[x ^ 1][y]) sr ++;
            if(y < n && b[x ^ 1][y + 1]) cc ++;
            if(y > 1 && b[x ^ 1][y - 1]) cc ++;
 
        }
        b[x][y] ^= 1;
        puts((cc == 0 && sr == 0) ? "Yes" : "No");
    }
    
}