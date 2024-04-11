#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxVal = 500005;
const int MaxN = 200005;

int N, Q;
vector<int> divisors[MaxVal];
int tab[MaxN];
int pcount[MaxVal];
int coef[MaxVal];
int valRange;
bool isOn[MaxVal];
int primeDivs[MaxVal];


void sieve(){
    for(int p = 2; p < valRange; p++){
        if(primeDivs[p] != 0) continue;
        primeDivs[p] = 1;
        for(int i = 2*p; i < valRange; i += p){
            primeDivs[i]++;
        }
    }
}

void input(){
    scanf("%d%d", &N, &Q);
    valRange = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d", &tab[i]);
        valRange = max(valRange, tab[i]+1);
    }
}

void make_divs(){
    fill(coef, coef+MaxVal, 1);

    for(int d = 2; d*d < valRange; d++){
        for(int i = d*d; i < valRange; i += d*d){
            coef[i] = 0;
        }
    }
    
    for(int d = 1; d < valRange; d++){
        if(coef[d] == 0) continue;
        for(int i = d; i < valRange; i += d){
            divisors[i].push_back(d);
        }
    }

    for(int i = 1; i < valRange; i++){
//        printf("%d -> %d\n", i, primeDivs[i]);
        if(coef[i] != 0 && primeDivs[i] % 2 == 0)
            coef[i] = -1;
    }

//    for(int i = 1; i < valRange; i++){
//        printf("%d: %d    ", i, coef[i]);
//        for(int v : divisors[i]) printf("%d ", v);
//        printf("\n");
//    }
}

int main(){
    ios_base::sync_with_stdio(0);
    input();
    sieve();
    make_divs();
    fill(isOn, isOn+N+1, false);

    LL result = 0;

    for(int query = 1; query <= Q; query++){
        int beer;
        scanf("%d", &beer);

        int mulCoef = isOn[beer] ? -1 : 1;
        isOn[beer] = !isOn[beer];


        for(int div : divisors[tab[beer]]){
            if(!isOn[beer]) pcount[div]--;
            result -= mulCoef * coef[div] * pcount[div];
            if(isOn[beer]) pcount[div]++;
        }

        
        cout << result << "\n";
    }
}