#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long ;
int n;
const ll inf  = 1e17;

struct segtree{
    static const int Mx = 4 * nax;
    ll sg[Mx];
    ll tag[Mx];
    void pull(int v){
        sg[v] = min(sg[v * 2], sg[v * 2 + 1]);
    }
    void push(int v){
        if(tag[v] == 0) return ;
        if(v * 2 + 1 < Mx){
            sg[v * 2] += tag[v];
            sg[v * 2 + 1] += tag[v];
            tag[v * 2] += tag[v];
            tag[v * 2 + 1] += tag[v];
        }
        tag[v] = 0;
    }
    void update(int v, int x, int y, int l, int r, int val){
        push(v);
        if(l > r || x > y) return;
        if(l == x && r == y){
            tag[v] += val;
            sg[v] += val;
            push(v);
            return ;
        }
        int mid = x + y >> 1;
        update(v * 2 ,  x, mid, l, min(r, mid), val);
        update(v * 2 + 1 , mid + 1 , y , max(l, mid + 1), r, val);
        pull(v);
    }
    void update(int l, int r, ll val){
        update(1, 1, n, l , r, val);
    }
};
segtree sg;
int a[nax], pos[nax], c[nax];
ll b[nax];

int main(){
    scanf("%d", &n);
    for(int i = 1 ;i <= n ; i ++){
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    for(int i = 1 ;i <= n ;i ++)
        scanf("%d", c + i);
   for(int i = 1 ;i <= n; i ++){
        sg.update(pos[i], n , c[pos[i]]);
    }
    ll ans = sg.sg[1];
    for(int i = 1 ;i <= n ;i ++){
        sg.update(pos[i], n - 1, -c[pos[i]]);
        sg.update(1, pos[i] - 1, c[pos[i]]);
        ans = min(ans, sg.sg[1]);
    }
    printf("%lld", ans);
}

/*
    Good Luck
        -Lucina
*/