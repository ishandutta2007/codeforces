#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 300010;
int n, a[N], b[N], cnt[N];
vector<int> num[N];
struct T{
    int l, r, v;
}t[N << 4];

void build(int p, int l, int r){
    t[p].l = l, t[p].r = r, t[p].v = 0;
    if(l == r) { t[p].v = 0; return; }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}

void change(int p, int x, int k){
    if(t[p].l == t[p].r) { t[p].v = k; return; }
    int mid = (t[p].l + t[p].r) >> 1;
    if(x <= mid) change(p << 1, x, k);
    else change(p << 1 | 1, x, k);
    t[p].v = max(t[p << 1].v, t[p << 1 | 1].v);
}

int query(int p, int x, int y){
    if(x <= t[p].l && t[p].r <= y) return t[p].v;
    int mid = (t[p].l + t[p].r) >> 1, res = 0;
    if(x <= mid) res = max(res, query(p << 1, x, y));
    if(mid + 1 <= y) res = max(res, query(p << 1 | 1, x, y));
    return res;
}

bool check(){
    
    for(int i = 1; i <= n; i++){
        if(++cnt[b[i]] > num[b[i]].size()) return false;
        int pos = num[b[i]][cnt[b[i]] - 1];
        if(query(1, b[i] + 1, n) > pos) return false;
        change(1, b[i], pos);
    }
    return true;
}
int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d", &n);

        build(1, 1, n);

        for(int i = 1; i <= n; i++)
            scanf("%d", a + i), num[a[i]].push_back(i);
        for(int i = 1; i <= n; i++)
            scanf("%d", b + i);
        
        puts(check() ? "YES" : "NO");
        for(int i = 1; i <= n; i++) 
            cnt[i] = a[i] = b[i] = 0, num[i].clear();
        
    }
    return 0;
}