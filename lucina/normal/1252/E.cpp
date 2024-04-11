#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=1e9+7;
static const int Mx = 100;
/// test

void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,int b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL

struct matrix{
    int m[Mx][Mx];
    static const long long mod2 = 1LL * mod * mod;
    matrix() {
        memset(m, 0, sizeof(m));
    }
    int * operator [](int r){
        return m[r];
    }
    void print(){
        eprintf("===========\n");
        for(int i = 0 ; i < Mx ;i  ++)
            for(int j = 0 ;j < Mx ;j ++)
                eprintf("%d%c", m[i][j], j == Mx - 1 ? '\n' : ' ');
        eprintf("===========\n");
    }
    friend matrix operator + (matrix & x, matrix & y){
        matrix res;
        for(int i = 0 ; i < Mx ; i ++)
            for(int j = 0 ;j < Mx ;j ++)
                res[i][j] = add(x[i][j], y[i][j]);
        return res;
    }
    friend matrix operator * ( matrix  & x, matrix & y){
        matrix res;
        for(int i = 0 ; i < Mx ; i ++)
            for(int j =0 ;j < Mx ; j ++){
                long long c = 0;
                for(int r = 0 ; r < Mx ; r ++){
                    c += 1LL * x[i][r] * y[r][j];
                    if(c >= mod2) c -= mod2;
                }
            res[i][j] = c % mod;
        }
        return res;
    }
};
matrix power(matrix x, long long y){
    matrix res;
    for(int i = 0  ;i < Mx ;i ++)
        res[i][i] = 1;
    for(; y > 0 ; y >>= 1){
        if(y & 1){
           res = res * x;
        }
        x = x * x;
    }
    return res;
}

int main(){
    matrix r, g;
    long long n ; int m;
    scanf("%lld%d",&n,&m);
    for(int i=0;i<m-1;i++){
        g[i+1][i]=1;
        r[0][i]=1;
    }
    g[0][m-1]=1;
    g[m-1][m-1]=1;
    r[0][m-1]=1;
    while(n){
        if(n & 1){
         r = r * g;
        }
        n>>=1;
        g = g * g;
    }
    printf("%d\n",r[0][0]);
}