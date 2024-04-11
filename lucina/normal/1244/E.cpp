#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
using ll = long long;
ll sum[maxn],k;
int n,a[maxn];
ll get(int l,int r){
    assert(l <= r);
    return sum[r] - sum[l - 1];
}
#define left fuck
#define right shit
bool ch(int x){
    ll res = 1e18;
    for(int i = 1 ;i <= n;i++){
        int left = a[i], right = x + a[i] ;
        int l = 1 , r = n, mid, ans = -1;
        ll tot = 1LL * i *a[i] - sum[i];
        l = 1 ,  r = n , ans = -1;
        if(a[n] > right){
            while(l <= r){
                mid = l + r >> 1;
                if(a[mid] > right){
                    ans = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
        assert(ans != -1);
        tot -= 1LL * right * (n - ans + 1);
        tot += get(ans ,n);
        }
        res = min(res, tot);

        /**
        Too stupid forgot to suppose it as maximum :P
        */
        left = a[i] - x;
        tot = get(i,n) - 1LL * (n - i + 1) * a[i];
        l = 1 , r = n  , ans = -1;
        if(a[1] < left){
            while(l <= r){
                mid = l + r >> 1;
                if(a[mid] < left){
                    ans = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            assert(ans != -1);
            tot -= get(1 , ans);
            tot += 1LL *left * ans;
        }
        res = min(res , tot);
    }
    return (res <= k);
}

int main(){
    scanf("%d %lld", &n,&k);
    for(int i =1 ;i<= n;i++){
        scanf("%d",&a[i]);
    }
    sort(a + 1 , a + 1 + n);
    for(int i = 1; i<= n; i++)
        sum[i] = sum[i - 1] + a[i];
    int l = 0 , r = 1e9, mid , ans = 1e9;
    while(l <= r){
        mid = l + r >> 1;
        if(ch(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    printf("%d\n",ans);
}
/*
    Virtual Round 592
*/