#include<bits/stdc++.h>
using namespace std;
int const nax = 5010, mod = 998244353;
void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,int b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}


int n, m, k, dp[nax][nax];

int main(){
    scanf("%d %d %d", &n, &m, &k);
    dp[0][0] = 1;
    /**
    number of tuple of length i that has j different element
    */
    for(int i = 1 ;i <= k ; i ++){
        for(int j = 1 ;j <= i ;j ++){
            plusle(dp[i][j], mul(dp[i-1][j], j));
            plusle(dp[i][j], mul(dp[i-1][j-1], n - j + 1));
        }
    }
    int ans = 0;
    m = power(m, mod - 2);
    int cur = m;
    for(int i = 1 ;i <= k ;i ++){
        plusle(ans, mul(cur, dp[k][i]));
        cur = mul(cur, m);
    }
    printf("%d\n", ans);
}