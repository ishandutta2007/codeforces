#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10, mod = 998244353;
void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,int b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}

int n, p[nax], inv[nax], suf[nax], pd[nax], q, ans;

int main(){
    int inv100 = power(100, mod - 2);
    scanf("%d %d", &n, &q );
    for(int i = 1 ;i <= n ;i ++){
        scanf("%d", &p[i]);
        p[i] = mul(p[i], inv100);
    }
    pd[n + 1] = 1;
    for(int i = n ; i >= 1 ; i --){
        pd[i] = mul(pd[i + 1], p[i]);
        suf[i] = add(suf[i + 1], power(pd[i], mod - 2));
    }
    auto calc = [&] (int l, int r){
        return mul( sub(suf[l] , suf[r]), pd[r]);
    };
    ans = suf[1];
    set<int> s = {1 , n + 1};
    set<int> :: iterator it;
    for(; q -- ;){
        int x, l , r;
        scanf("%d", &x);
        it = s.find(x);
        if(it == s.end()){
            s.insert(x);
            it = s.find(x);
            l = *prev(it);
            r = *next(it);
          //  printf("l = %d r = %d x = %d\n", l , r ,x);
            plusle(ans, add(calc(l, x), calc(x, r) ));
            minun(ans, calc(l, r));
            printf("%d\n", ans);
        }
        else{
            l = *prev(it);
            r = *next(it);
           // printf("l = %d r = %d x = %d\n", l , r ,x);
            s.erase(it);
            minun(ans, add(calc(l, x), calc(x , r)));
            plusle(ans, calc(l, r));
            printf("%d\n", ans);
        }
    }

}
/*
    Good Luck
        -Lucina
*/