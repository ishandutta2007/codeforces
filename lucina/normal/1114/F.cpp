#include<bits/stdc++.h>
using namespace std;
//#define LOCAL
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL
int const nax = 4e5 + 10, mod = 1e9 + 7;
using ll = long long ;
int a[nax], n, inv[305];
inline int mul(int a, int b){
    return 1LL * a * b % mod;
}
inline void mult(int &a, int b){
    a = 1LL * a * b % mod;
}
inline int power(int x, int y){
    int res = 1;
    for(; y > 0; y >>= 1, x = mul(x, x))
        if(y & 1) mult(res, x);
    return res;
}
vector<int> prime;
int to[305];
ll pmask[305];

bool isprime(int x){for(int i = 2 ; i * i <= x; i++)if(x % i == 0) return false; return true;}

void init(){
    int id = 0;
    for(int i = 2 ;i <= 300 ; i ++){
        if(isprime(i)){
            to[i] = id ++;
            prime.push_back(i);
        }
    }
    for(int i = 2 ; i <= 300 ;i ++){
        for(int j : prime){
            if(i % j == 0){
                pmask[i] ^= (1LL << to[j]);
            }
        }
    }
    for(int i = 1 ; i <= 300 ;  i ++)
        inv[i] = power(i , mod - 2);
}

struct lazysegtree{
    static const int Mx = nax * 4;
    int sg[Mx];
    int lazy[Mx];
    ll mask[Mx];
    ll tagmask[Mx];
    lazysegtree(){
        fill(sg, sg + Mx, 1);
        fill(lazy, lazy + Mx, 1);
    }
    void build(int v, int l, int r){
        if(l == r){
            sg[v] = a[l] ;
            mask[v] = pmask[a[l]];
            return ;
        }
        int mid = l + r >> 1;
        build(v * 2 , l , mid);
        build(v * 2 + 1 , mid + 1, r);
        sg[v] = mul(sg[v * 2], sg[v * 2  + 1]);
        mask[v] = (mask[v * 2] | mask[v * 2 + 1]);
    }
    inline void push(int v, int l, int r){
        if(lazy[v] != 1){
        mult(sg[v], power(lazy[v], r - l + 1));
        if(v * 2 + 1 < Mx){
        mult(lazy[v * 2 ], lazy[v]);
        mult(lazy[v * 2 + 1], lazy[v]);
        }
        lazy[v] = 1;
        }
        if(tagmask[v]){
            mask[v] |= tagmask[v];
            if(v * 2 + 1 < Mx){
            tagmask[v * 2] |= tagmask[v];
            tagmask[v * 2  + 1]  |= tagmask[v];
            }
            tagmask[v] = 0;
        }
    }
    inline void update(int v, int x, int y, int l, int r, int p, ll msk){
        push(v, x, y);
        if(l > r) return ;
        if(l == x && r == y){
            mult(lazy[v], p);
            tagmask[v] |= msk;
            push(v, l , r);
            return ;
        }
        int mid = x + y >> 1;
        update(v * 2 , x, mid, l, min(r, mid), p, msk);
        update(v * 2 + 1 , mid + 1, y , max(l , mid + 1), r, p, msk);
        sg[v] = mul(sg[v * 2], sg[v * 2 + 1]);
        mask[v] = (mask[v * 2] | mask[v * 2  + 1]);
    }
    inline pair<int, ll> query(int v, int x, int y, int l ,int r){
        push(v, x, y);
        if(l > r ) return make_pair(1, 0LL);
        if(l == x && r == y){
            return make_pair(sg[v], mask[v]);
        }
        int mid = x + y >> 1;
        auto x1 = query(v * 2 , x , mid, l, min(r, mid));
        auto x2 = query(v * 2 + 1, mid + 1, y, max(l, mid + 1), r);
        return make_pair( mul(x1.first, x2.first), (x1.second | x2.second) );
    }
    void update(int l, int r, int p, ll msk){
        update(1, 1, n, l, r, p, msk);
    }
    pair<int, ll> query(int l, int r){
        return query(1, 1, n, l, r);
    }
};
lazysegtree seg;
int q;
char s[15];

int main(){
    init();
    scanf("%d %d", &n , &q);
    for(int i = 1 ;i <= n; i ++){
        scanf("%d", &a[i]);
    }
    seg.build(1, 1, n);
    while(q --){
        scanf("%s", s);
        if(s[0] == 'M'){
            int l, r, x;
            scanf("%d %d %d", &l, &r , &x);
            seg.update(l, r, x, pmask[x]);
        }
        else{
            int l , r;
            scanf("%d %d", &l, &r);
            auto x = seg.query(l, r);
            int res = x.first;
            for(int i = 0 ; i < 62 ; i ++){
                if(x.second & (1LL << i)){
                    mult(res, prime[i] - 1);
                    mult(res, inv[prime[i]]);
                }
            }
            printf("%d\n", res);
        }
    }
}