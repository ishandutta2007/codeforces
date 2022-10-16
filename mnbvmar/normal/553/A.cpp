#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int K;
int tab[1005];

int pwrs[1000005];
int invPwrs[1000005];

const int Mod = 1000000007;

int pow_mod(int a, int k){
    if(k == 0) return 1;
    int res = pow_mod(a, k/2);
    res = ((LL)res * res) % Mod;
    if(k % 2 == 1) res = ((LL)res * a) % Mod;
    return res;
}

int inv_mod(int a){
    return pow_mod(a, Mod-2);
}

void precomp(){
    pwrs[0] = invPwrs[0] = 1;
    for(int i = 1; i <= 1e6+3; i++){
        pwrs[i] = ((LL)pwrs[i-1] * i) % Mod;
        invPwrs[i] = ((LL)invPwrs[i-1] * inv_mod(i)) % Mod;
    }
}

void input(){
    scanf("%d", &K);
    for(int i = 0; i < K; i++) scanf("%d", &tab[i]);
}

int main(){
    input();
    precomp();

    LL result = 1;

    int total = 0;
    for(int i = 0; i < K; i++){
        total += tab[i];
        result = ((LL)result * pwrs[total-1]) % Mod;
        result = ((LL)result * invPwrs[tab[i]-1]) % Mod;
        result = ((LL)result * invPwrs[total-tab[i]]) % Mod;
    }
    cout << result << endl;
}