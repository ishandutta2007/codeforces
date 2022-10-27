#include<bits/stdc++.h>
using namespace std;
using pii = pair<int , int >;
using ll = long long;
//#define LOCAL
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL

int const nax = 3e5 + 10;

int n, t, a, b;
pii p[nax];
/**
1
6 20 2 5
1 1 0 1 0 0
0 8 2 9 11 6

*/

int solve(){
    scanf("%d %d %d %d", &n , &t, &a, &b);
    int h = 0, e = 0, ans = 0;
    for(int i = 1; i <= n; i ++){
        scanf("%1d", &p[i].second);
        if(p[i].second) h ++;
        else e ++ ;
        }
    for(int i = 1 ;i <= n; i ++)
        scanf("%d", &p[i].first);
    sort(p + 1,  p + 1 + n);
    ll sum = 0;
    for(int i = 1; i<= n;i ++){
        eprintf("%d %d\n", p[i].first, p[i].second);
    }
    for(int i = 1 ;i <= n; i ++){
        int next = p[i].first;
        if(sum < next){
            eprintf("i = %d sum = %lld next = %d\n", i, sum, next);
            int res = 0, has = next - sum - 1;
            if(e > 0){
                res += min(e, has / a);
                has -= a * min(e, has / a);
            }
            if(h > 0)
                res += min(h, has / b);
            ans = max(ans, i - 1 + res);
        }
        int j = i;
        while(p[j].first == p[i].first && j <= n){
            sum += p[j].second ? b : a;
            if(p[j].second) h --;
            else e -- ;
            ++ j;
        }
        i = j - 1;
    }
    if(sum <= t) return n;
    return ans;

}

int main(){
    int T;
    for(cin >> T ; T --; printf("%d\n", solve()));
}