#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10, mod = 998244353;

void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,long long b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}

int n, m, A, b;

int main(){
    scanf("%d %d %d", &n, &m ,&A);
    if(A >= mod) A %= mod;
    int ans = 1;
    int inv = power(2 , mod - 2);
    int pre = 0;
    for(int i = 1 ;i <= m ; i ++){
        scanf("%d", &b);
        int len = b - pre;
        ans = mul(ans, add(power(A, 2 * len), power(A, len)));
        ans = mul(ans, inv);
        pre = b;
    }
    ans = mul(ans, power(A, n - b - b));
    printf("%d\n", ans);
    /**
    Every segment is independent.
    Just multiply number of string in each segment.
    */
}