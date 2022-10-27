#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10;

int t, a[3], g[8];
int num[nax];
vector<int> p[8];


long long solve(){

    for(int i = 0 ; i < 3 ; i ++)
        scanf("%d", a + i);

    long long ans = 0, c = 0;

    for(int i = 1 ;i < 8 ; i ++){
        int res = 0;
        for(int j = 0 ;j < 3 ;j ++){
            if(i >> j & 1){
                res = __gcd(res, a[j]);
            }
        }
        g[i] = num[res];
    }
    //fprintf(stderr, "\n");
    for(int i =  1 ;i < 64 ;  i ++){
        int cnt = 0;
        int x[3] = {};

        for(int j = 0 ;j < 6 ;j ++){
            if((i >> j) & 1){
                cnt ++;
                for(int k = 0 ; k < 3 ; ++ k){
                        x[k] |= (1 << p[j][k]);
                }
            }
        }
            ans += ((cnt & 1) ? 1LL : -1LL) * g[x[0]] * g[x[1]] * g[x[2]];
            ///Q: in same loop if we assume first and second element to be equal?
            ///A: it should have bit of each others
            c += ((cnt & 1) ? 1LL : -1LL) * (g[x[0] | x[1]] ) * g[x[2]];
    }
    ///fprintf(stderr, "%lld %lld %d\n", ans, c, g[7]);
    return (ans + c * 3 + g[7] * 2) / 6;
    /**
    Then, try inclusion exclusion of all permutation
    */

}

int main(){
    for(int i = 1 ; i < nax ; i ++)
        for(int j = i ;j < nax ;j += i)
            ++ num[j];

    int cnt = 0;
    for(int i = 0 ; i < 3 ; i ++){
        for(int j =0 ;j < 3 ; j ++){
            if(i == j) continue;
            p[cnt ++] = {i, j, 3 - i - j};
        }
    }
    scanf("%d", &t);
    while(t --){
        printf("%lld\n",solve() ) ;
    }
}