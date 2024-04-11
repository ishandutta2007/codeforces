#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010, M = 1010;
int n, m, f[N];
//f[i]  i  i + 1 
struct Node{
    int l, r, t;
}e[M];
bool inline cmp(Node x, Node y){
    return x.t > y.t;
}
bool inline check(int l, int r, int t){
    for(int i = l; i < r; i++)
        if(f[i] == -1 || f[i] == t) return true;
    return false;
}
int main(){
    memset(f, -1, sizeof f);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int t, l, r; scanf("%d%d%d", &t, &l, &r);
        e[i] = (Node){l, r, t};
        
        
    }
    sort(e + 1, e + 1 + m, cmp);
    for(int i = 1; i <= m; i++){
        int l = e[i].l, r = e[i].r, t = e[i].t;
        if((!check(l, r, t))) { puts("NO"); return 0; }
        else for(int i = l; i < r; i++) 
            if(f[i] == -1)f[i] = t;
    }
    int last = n; printf("YES\n%d ", n);
    for(int i = 1; i < n; i++) 
        if(f[i]) printf("%d ", last);
        else printf("%d ", --last);
    
    return 0;
}