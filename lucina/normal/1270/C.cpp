#include<bits/stdc++.h>
int const nax = 3e5 + 10;
using ll = long long ;

void solve(){
    int n , a;
    ll  sum = 0, x = 0;
    scanf("%d", &n);
    for(int i = 1; i<= n ;i ++){
        scanf("%d", &a);
        sum += a;
        x ^= a;
    }
    ll first_sum = sum;
    printf("2\n");
    printf("%lld ", x);
    first_sum += x;
    sum += x;
    ll touse = 0;
    for(int i = 0 ; (1LL << i) < sum ; i ++){
        int cur_bit = (touse & (1LL << i)) > 0;
        int next_bit = (sum & (1LL << (i + 1))) > 0;
        if(cur_bit == next_bit) continue;
        touse ^= (1LL << (i + 1));
        sum += (1LL << (i + 1));
        if(touse == sum / 2) break;
    }
    first_sum += touse;
    if(first_sum != touse * 2) throw;
    printf("%lld\n", touse);
}

int main(){
    int T;
    for(std :: cin >> T; T -- ; solve()){


    }
}
/*
    Good Luck
        -Lucina
*/