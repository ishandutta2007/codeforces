#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

map<int, int> countLucky;

bool is_lucky(int num){
    while(num){
        int digit = num % 10;
        if(digit != 4 && digit != 7) return false;
        num /= 10;
    }
    return true;
}


const int MaxN = 100005;
const int Mod = 1000000007;

int N, K;
int tab[MaxN];


void input(){
	scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d", &tab[i]);
    }
}

int factorials[MaxN];
int invFactorials[MaxN];

int pow_mod(int a, int n){
    if(!n) return 1;
    int res = pow_mod(a, n/2);
    res = ((LL)res * res) % Mod;
    if(n % 2 == 1) res = ((LL)res * a) % Mod;
    return res;
}

int inv_mod(int a){
    return pow_mod(a, Mod-2);
}

void preproc_fact(int size){
    factorials[0] = 1;
    invFactorials[0] = 1;
    for(int i = 1; i <= size; i++){
        factorials[i] = ((LL)factorials[i-1] * i) % Mod;
        invFactorials[i] = inv_mod(factorials[i]);
    }
}

int get_newton(int n, int k){
    if(k < 0 || k > n) return 0;
    int result = factorials[n];
    result = ((LL)result * invFactorials[k]) % Mod;
    result = ((LL)result * invFactorials[n-k]) % Mod;
    return result;
}




int main(){
	input();

    preproc_fact(N+10);

    int unlucky = 0;
    for(int i = 0; i < N; i++){
        if(is_lucky(tab[i]))
            countLucky[tab[i]]++;
        else
            unlucky++;
    }


    int numDiffLucky = (int)countLucky.size();
    vector<int> waysLucky(numDiffLucky+1, 0);
    waysLucky[0] = 1;

    for(auto P: countLucky){
        int num = P.first, ways = P.second;

        for(int i = numDiffLucky-1; i >= 0; i--){
            waysLucky[i+1] = (waysLucky[i+1] + (LL)waysLucky[i] * ways) % Mod;
        }
    }

    int total = 0;

    for(int i = 0; i <= numDiffLucky; i++){
//        printf("%d -> %d\n", i, waysLucky[i]);
        int addend = waysLucky[i];
//        printf("[%d,%d]\n", unlucky, K-i);
//        printf("newton(%d,%d) = %d\n", unlucky, K-i, get_newton(unlucky, K-i));
        addend = ((LL)addend * get_newton(unlucky, K-i)) % Mod;
        total = (total + addend) % Mod;
    }

    printf("%d\n", total);


}