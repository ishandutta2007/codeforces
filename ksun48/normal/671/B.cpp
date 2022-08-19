#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL n, k;
    scanf("%lld%lld", &n, &k);
    LL c[n];
    LL sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld", &c[i]);
        sum += c[i];
    }
    sort(c, c+n);
    LL a = sum / n;
    LL b = a;
    while(b * n < sum) b++;

    LL s1 = 0;
    LL e1 = a+1;
    while(s1 + 1 < e1){
        LL m1 = (s1 + e1) / 2;
        LL need = 0;
        for(int j = 0; j < n; j++){
            need += max(m1 - c[j], 0LL);
        }
        if(need <= k){
            s1 = m1;
        } else {
            e1 = m1;
        }
    }
    LL s2 = b-1;
    LL e2 = 10000000000000000LL;
    while(s2 + 1 < e2){
        LL m2 = (s2 + e2) / 2;
        LL need = 0;
        for(int j = 0; j < n; j++){
            need += max(c[j] - m2, 0LL);
        }
        if(need <= k){
            e2 = m2;
        } else {
            s2 = m2;
        }
    }
    printf("%lld\n", max(b,e2) - min(a,s1));
}