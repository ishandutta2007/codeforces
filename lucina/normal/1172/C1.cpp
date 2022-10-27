#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL
int const mod = 998244353;
void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,int b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}
int inv(int x){return power(x, mod - 2);}

int const maxn = 2e5 + 10, nax = 3010;
int n , m, in[nax * 2];
int w[maxn], p, q, dp[nax][nax];
bool d[maxn];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1 ;i <= n ;i ++){
        scanf("%1d", &d[i]);
    }
    for(int i = 1 ;i <= n ;i ++){
        scanf("%d", &w[i]);
        d[i] ? (p += w[i]) : (q += w[i]);
    }
    /**
    Transition
    dp[x][y] the probability -> at step x
    such that NAOUU will visit like side y times
    */
    dp[0][0] = 1;
    for(int i = 0 ; i < nax * 2; i ++){
        in[i] = inv(sub(p + q + i  ,nax));
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ;j <= i ;j ++){
            int cursum = (p + q + 2 * j - i);
            if(cursum <= 0) continue;
            if(dp[i][j] == 0) continue;
            cursum = in[2 * j - i + nax];
            int go = p + j;///current sum =
            plusle(dp[i + 1][j + 1], mul(dp[i][j], mul(go,cursum)));
            go = q - i + j;
            if(go > 0)
            plusle(dp[i + 1][j], mul(dp[i][j], mul(go, cursum)));
        }
    }
    int x = 0 , y = 0;
    for(int i = 0 ; i <= m ; i++){
        plusle(x, mul(dp[m][i], p + i));
        if(q > m - i)
        plusle(y, mul(dp[m][i], q - m + i));
    }
    x = mul(x, inv(p));
    y = mul(y, inv(q));
    for(int i = 1 ;i <= n ; i++){
        printf("%d\n", mul(w[i], d[i] ? x : y));
    }
}