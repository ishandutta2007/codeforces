#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const nax = 3e5 + 10;
int n, s, a[nax];
ll p[nax];
int solve(){
    scanf("%d %d", &n, &s);
    for(int i = 1; i <= n; i ++){
        scanf("%d", a + i);
    }
    int ma = 0, ans = 0;
    for(int i = 1; i <= n;i ++){
        p[i] = p[i - 1] + a[i];
        if(p[i] <= s){
            ma = i;
        }
    }
    for(int i = 1; i <= n; i ++){
        int cur = i - 1;
        ll res = s - p[i - 1];
        if(res < 0) continue;
        int l = i + 1, r = n, mid , ans1 = i;
        while(l <= r){
            mid = l + r >> 1;
            if(p[mid] - p[i] <= res){
                ans1 = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cur += ans1 - i;
        if(cur > ma){
            ma = cur;
            ans = i;
        }
    }
    return ans;
}

int main(){
    int t;
    for(cin  >> t; t --; ){
        printf("%d\n", solve());
    }
}
/**
    Good Luck
        -Lucina
*/