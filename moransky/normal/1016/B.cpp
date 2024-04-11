#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef unsigned long long ULL;
const int N = 1010, B = 221;
int n, m, q, len;
char s[N], t[N]; 
ULL P[N], S[2][N];
ULL inline get(int l, int r, int c){
    return S[c][r] - S[c][l - 1] * P[r - l + 1];
}
int main(){
    scanf("%d%d%d%s%s", &n, &m, &q, s + 1, t + 1);
    P[0] = 1;
    for(int i = 1; i <= n; i++){
        P[i] = P[i - 1] * B;
        S[0][i] = S[0][i - 1] * B + s[i];
        S[1][i] = S[1][i - 1] * B + t[i];
    }
    while(q--){
        int l, r, res = 0; scanf("%d%d", &l, &r);
        for(int i = l; i <= r - m + 1; i++)
            if(get(i, i + m - 1, 0) == get(1, m, 1))res++;
        printf("%d\n", res);
    }
    return 0;
}