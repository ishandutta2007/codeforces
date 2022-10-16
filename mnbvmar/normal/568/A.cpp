#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 2000000;

bool prime[MaxN];
vector<int> primes;

void sieve(){
    fill(prime, prime+MaxN, true);
    for(int p = 2; p*p < MaxN; p++){
        if(!prime[p]) continue;
        for(int i = p*2; i < MaxN; i += p){
            prime[i] = false;
        }
    }

    for(int p = 2; p < MaxN; p++){
        if(prime[p]) primes.push_back(p);
    }
}

int p, q;

void input(){
    scanf("%d%d", &p, &q);
}

string tostr(int v){
    string a = "";
    while(v){
        a += (char)(v%10+'0');
        v /= 10;
    }
    reverse(a.begin(), a.end());
    return a;
}

bool palin(int v){
    string s = tostr(v);
    int l = (int)s.size();
    for(int i = 0; i < l; i++){
        if(s[i] != s[l-i-1]) return false;
    }
    return true;
}

int main(){
    input();
    sieve();

    int best = 0;
    int curP = 0, curR = 0;
    for(int i = 1; i < MaxN; i++){
        if(prime[i] && i>1) curP++;
        if(palin(i)) curR++;

        if((LL)q*curP <= (LL)p*curR){
            best = i;
        }
    }

    printf("%d\n", best);
}