#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
using ll = long long ;
ll s;
struct seg{
    int l, r;
    seg() : l(), r() {}
    seg(int x, int y) : l(x), r(y){}
    bool operator < (const seg & x) const{
        return l < x.l;
    }
    void read(){
        scanf("%d %d", &l ,&r);
    }
}a[maxn];
int n;
bool ch(int x){
    ll cost = 0;
    vector<seg> v;
    int tm = 0;
    for(int i = 1 ;i<= n;i++){
        if(a[i].l <= x){
            v.push_back(a[i]);
        }
        else tm++;
    }
    if(tm >= (n / 2 + 1))return false;
    int res =  (n / 2 + 1) - tm ;
    vector<seg> another; // not anime :P Nonsense
    for(seg i: v){
        if(i.r >= x){
            another.push_back(i);
        }
    }
    if(res > (int)another.size()) return false;
    for(int i = 1 ; i<= res; i++){
        cost += x - another.back().l;
        another.pop_back();
    }
    return cost <= s;
}

void solve(){
    scanf("%d %lld", &n, &s);
    int nax = 0;
    for(int i = 1 ;i <= n;i++){
        a[i].read();
        nax = max(nax, a[i].r);
        s -= a[i].l;
    }
    sort(a + 1, a + 1 + n);
    int middle= n + 1 >> 1;
    int l = a[middle].l , r = nax, mid, ans = a[middle].l;
    while(l <= r){
        mid = l + r >> 1;
        if(ch(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%d\n", ans);
}

int main(){
    int T;
    for(scanf("%d", &T); T --;){
        solve();
    }
}