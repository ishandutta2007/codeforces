#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int bit[4][11][11][N];
char s[N],c[15];
int n;
int C(char x){
    if(x == 'A') return 0;
    if(x == 'T') return 1;
    if(x == 'G') return 2;
    return 3;
}
void update(int * ft, int pos, int val){
    for(; pos < N; pos += (pos & - pos)) ft[pos] += val;
}
int query(int * ft, int pos){
    int sum = 0;
    for(; pos > 0; pos -= (pos & -pos)) sum += ft[pos];
    return sum;
}
int main(){
    int q;
    scanf("%s", s + 1);
    scanf("%d", &q);
    n = strlen(s + 1);
    int K[11] = {};
    for(int i = 1; i <= n; i++){
        int pt = C(s[i]);
        for(int j = 1; j <= 10; j++){
            update(bit[pt][j][i % j], i, 1);
            assert(query(bit[pt][j][i % j], i) - query(bit[pt][j][i % j], i -1) == 1);
        }
    }
    for(int qi = 1; qi <= q; qi++){
        int x;
        scanf("%d", &x);
        if(x == 1){
            int pos;
            scanf("%d %s", &pos, c);
            for(int i = 1; i <= 10; i++){
                assert(query(bit[C(s[pos])][i][pos % i], pos) - query(bit[C(s[pos])][i][pos % i], pos - 1) == 1);
                update(bit[C(s[pos])][i][pos % i], pos, -1);
               // assert(query(bit[C(s[pos])][i][pos % i], pos) - query(bit[C(s[pos])][i][pos % i], pos - 1) == 0);
                update(bit[C(c[0])][i][pos % i], pos, 1);
            }
            s[pos] = c[0];
        }
        else{
            int l, r;
            scanf("%d %d %s",&l, &r, c + 1);
            int len = strlen(c + 1), k = 0, sum = 0;
            for(int i = 1; c[i] != '\0' && l + i - 1 <= r; i++){
                if(k == len) k = 0;
                sum += query(bit[C(c[i])][len][(l +i - 1) % len], r) - query(bit[C(c[i])][len][(l + i -1) % len], l - 1);
            }
            printf("%d\n", sum);
        }
    }

}
/*
ATGCATGC
4
1 4 T
2 1 8 ATGC
2 2 6 TTT
2 2 6 TA
*/