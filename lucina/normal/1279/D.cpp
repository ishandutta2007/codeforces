#include<bits/stdc++.h>
using namespace std;

int const nax = 1e6 + 10, mod = 998244353;

void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,int b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}

int n;
int ct[nax], k[nax];
vector<int> a[nax];
int sum ;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &k[i]);
        a[i].resize(k[i]);
        for(int j = 0 ;j < k[i] ;j ++){
            scanf("%d", &a[i][j]);
            ct[a[i][j]] ++ ;
            /// want by ct different children
        }
    }
    int rn = power(n, mod - 2);
    for(int i = 1 ;i <= n; i ++){
        int cur = rn;
        cur = mul(cur, power(k[i], mod - 2));
        for(int j = 0 ;j < k[i];j ++){
            plusle(sum, mul(cur, mul(rn, ct[a[i][j]])));
        }
    }
    printf("%d\n", sum);

}/**
    Good Luck
        -Lucina
*/