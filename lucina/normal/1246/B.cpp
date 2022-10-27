#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n, k, a[maxn];
bool isprime(int x){
    int j = sqrt(x);
    for(; j> 1 ;j --){
        if(x % j == 0) return false;
    }
    return true;
}
int ss[maxn];
int d[maxn], cc[maxn];

int main(){
   /* int ct = 0;
    for(int i =2 ;i<= 100000; i++){
        ct += isprime(i);
    }*/
    scanf("%d %d", &n, &k);
    for(int i = 1 ;i <= n;i++){
        scanf("%d", &a[i]);
        int x = a[i];
        int sq = sqrt(x);
        vector<pair<int,int>> v;
        for(int j = 2 ;j <= sq;j++){
            if(x % j == 0){
                int ct = 0;
                while(x % j == 0){
                    ct ++;
                    x /= j;
                }
                ct %= k;
              /*  if(a[i] == 24){
                    printf("%d %d\n", j, ct);
                }*/
                if(ct > 0)v.push_back(make_pair(j, ct));
            }
        }
        if(x > 0) v.push_back(make_pair(x, 1));
        int res = 1;
        for(auto it : v){
            for(int j = 0 ;j < it.second ;j++){
                res *= it.first;
            }
        }
        ss[res] ++;
        cc[i] = res;
        int demand = 1;
        for(auto it : v){
            for(int j = 0 ;j < k - it.second ;j++){
                demand *= it.first;
                if(demand > 100000){
                    demand = -1;
                    break;
                    }
            }
            if(demand == -1) break;
        }
        d[i] = max(0,demand);
    }
 /*   for(int i = 1 ;i<=n;i++){
        printf("%d ",d[i]);
    }
    printf("\n");
    for(int i = 1 ;i <= n; i++){
        printf("%d ",cc[i]);
    }
    printf("\n");*/
    long long ans = 0;
    for(int i = 1 ;i<= n;i++){
        ans += ss[d[i]];
        if(cc[i] == d[i]) ans --;
    }
    ans /= 2;
    printf("%lld\n",ans);
}
/*
    Good Luck
        -Lucina
*/