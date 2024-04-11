/**************************************************************
    Problem: 1367
    User: rausen
    Language: C++
    Result: Accepted
    Time:5284 ms
    Memory:59400 kb
****************************************************************/
 
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
const int N = 1500000;
 
struct heap{
    int v, l, r, dep;   
}h[N];
int l[N], r[N], cnt[N], num[N], root[N];
int z[N];
int n, tot, Cnt;
 
inline int read(){
    int x = 0, sgn = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-') sgn = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return sgn * x;
}
 
int new_heap(int x){
    h[++Cnt].v = x;
    h[Cnt].l = h[Cnt].r = h[Cnt].dep = 0;
    return Cnt;
}
 
int Merge(int x, int y){
    if (!x || !y) return x + y;
    if (h[x].v < h[y].v)
        swap(x, y);
    h[x].r = Merge(h[x].r, y);
    if (h[h[x].l].dep < h[h[x].r].dep)
        swap(h[x].l, h[x].r);
    h[x].dep = h[h[x].r].dep + 1;
    return x;
}
 
int Top(int x){
    return h[x].v;
}
 
int Pop(int x){
    return Merge(h[x].l, h[x].r);
}
 
int main(){
    n = read();
    for (int i = 1; i <= n; ++i)
        z[i] = read() - i;
     
    for (int i = 1; i <= n; ++i){
        ++tot;
        root[tot] = new_heap(z[i]);
        cnt[tot] = 1, num[tot] = 1;
        l[tot] = i, r[tot] = i;
         
        while (tot > 1 && Top(root[tot]) < Top(root[tot - 1])){
            --tot;
            root[tot] = Merge(root[tot], root[tot + 1]);
            num[tot] += num[tot + 1], cnt[tot] += cnt[tot + 1], r[tot] = r[tot + 1];
            for(; cnt[tot] * 2 > num[tot] + 1; --cnt[tot])
                root[tot] = Pop(root[tot]);
        }
    }
     
    long long ans = 0;
    for (int i = 1; i <= tot; ++i)
        for (int j = l[i], w = Top(root[i]); j <= r[i]; ++j)
            ans += max(z[j] - w,w-z[j]);
    printf("%lld\n", ans);
    return 0;
}