#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10,mod = 1e9+7;
void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,long long b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}
using ll = long long;
vector<int> prime;
ll calc(ll x, ll n){
    ll cur = x,sum = 0;
    while(x <= n){
        sum += (n / x);
        if(x > n / cur) break;
        x *= cur;
    }
    return sum;
}

int main(){
    ll x,n;
    cin >> x >> n;
    for(ll i = 2 ;i * i <= x; i++){
        if(x % i == 0){
            prime.push_back((int)i);
            while(x % i == 0)
                x /= i;
        }
    }
    if(x > 1) prime.push_back((int)x);
    int ans = 1;
    for(int i:prime){
        ans = mul(ans, power(i, calc((ll)i,n)));
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/