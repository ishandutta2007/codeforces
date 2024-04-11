#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7, nax = 2e5 + 10;
///clean code

void plusle(int &a, int b){
    if( (a += b) >= mod) a -= mod;
}
void minun(int  &a, int b){
    if(( a -= b) < 0) a += mod;
}
int add(int a, int b){
    return ((a += b) >= mod) ? a - mod : a;
}
int sub(int a, int b){
    return ( (a -= b) < 0 ) ? a + mod : a;
}
int mul(int a, int b){
    return (1LL * a * b) % mod;
}

template<class T = ll> struct fenwick{
    T bit[nax];
    T get(int idx){
        T res = 0;
        for(; idx > 0 ; idx -= idx & - idx )
            res += bit[idx];
        return res;
    }
    void update(int idx, int val){
        for(; idx < nax ; idx += idx & - idx)
            bit[idx] += val;
    }
    T get(int l,int r){
        if(l > r) return 0;
        return get(r) - get(l - 1);
    }
};
struct modfenwick{
    int bit[nax];
    modfenwick(){
        memset(bit, 0, sizeof(bit));
    }
    int get(int idx){
        int res = 0;
        for(; idx > 0 ; idx -= idx & - idx )
            plusle(res, bit[idx]);
        return res;
    }
    void update(int idx, int val){
        for(; idx < nax ; idx += idx & - idx)
            plusle(bit[idx], val);
    }
    int get(int l,int r){
        if(l > r) return 0 ;
        return sub(get(r), get(l - 1));
    }
};
int n, q, a[nax], w[nax];
modfenwick fm;
fenwick<ll> f1;

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 1 ;i <= n ;i ++){
        scanf("%d", a + i);
        a[i] -= i;
    }
    for(int i = 1 ;i <= n ; i ++){
        scanf("%d", w + i);
        f1.update(i, w[i]);
        fm.update(i, mul(a[i], w[i]));
    }
    while(q -- ){
        int x, y;
        scanf("%d %d", &x, &y);
        if(x < 0){
            x = -x ;
            int res = ((-mul(a[x], w[x]) ) + mod);
            if(res == mod) res = 0;
            fm.update(x, res);
            f1.update(x, -w[x]);
            w[x] = y;
            f1.update(x, y);
            fm.update(x, mul(a[x], y));
        }
        else{
            int l  = x, r =  y, ans = x;
            /*while(l <= r){
                int mid = l + r >> 1;
                if(f1.get(x, mid) * 2 >= sum){
                    ans = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }*/
            ///let's try binary lifting
            ///sum[1, x - 1] * 2  + sum[x, i] * 2 < sum[x, y] +  sum[1, x - 1] * 2
            ll sum = f1.get(x,  y) + f1.get(1, x - 1) * 2;

            int lim = y;
            int pos = 0; ll cur = 0;
            for(int  i = __lg(lim) ; i >=0 ; i --){
                if( pos + (1 << i) <= lim && (cur + f1.bit[pos + (1 << i)]) * 2 < sum ){
                    pos += (1 << i);
                    cur += f1.bit[pos];
                }
            }
            ll res = 0;
            int c = min(y, pos + 1);
            //printf("sum = %lld pos = %d\n",sum, c);
            if(x < c){
            res += (1LL * a[c] *(f1.get(x, c) % mod));
            res -= fm.get(x, c);
            }
            if(y > c){
            res -= (1LL * a[c] *(f1.get(c + 1, y) % mod)) ;
            res += fm.get(c + 1 , /*r*/ y ); // ok funny enough
            }
            res %= mod;
            if(res < 0)res += mod;
            printf("%lld\n", res);
        }
    }
    /**
    sum[1, x - 1] * 2 sum[x, i] * 2 < sum[x, y] +
    */
}