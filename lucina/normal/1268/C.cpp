#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
//#define LOCAL
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr,  __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL
using ll = long long ;
int n;
template<class T = int> struct fenwick{
    T bit[nax];
    T get(int i){
        T res = 0;
        for(; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
    void update(int i, T val){
        for(; i <= n ;i += i & -i)
            bit[i] += val;
    }
    T get(int l, int r){
        if(l > r) return 0;
        return get(r) - get(l - 1);
    }
};
fenwick<int> f1;
fenwick<ll> f2;
int  a[nax];
ll inv ;

ll sq(ll x){
    return (x * (x + 1)) / 2;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n ; i++){
        int x;
        scanf("%d", &x);
        a[x] = i;
    }
    printf("0 ");
    f1.update(a[1], 1);
    f2.update(a[1], a[1]);
    for(int i = 2 ;i <= n ;i ++){
        inv += f1.get(a[i], n);
        f1.update(a[i], 1);
        f2.update(a[i], a[i]);
        int tar = (i + 1) / 2, cur = 0, idx = 0;
        for(int j = 18 ;j >= 0 ;j --){
            if(idx + (1 << j) <= n && cur + f1.bit[idx + (1 << j)] < tar){
                idx ^= 1 << j;
                cur += f1.bit[idx];
            }
        }
        if(++ cur != tar) throw;
        int mid = ++ idx;
        ll leftsum = 1LL * tar * (mid + 1) - f2.get(mid) - sq(tar);

        ll rightsum = f2.get(mid + 1 , n) - 1LL * (i / 2) * mid - sq(i / 2);

        printf("%lld ", inv + leftsum + rightsum);
    }
}