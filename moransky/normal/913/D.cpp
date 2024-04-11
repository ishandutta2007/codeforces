#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, T;
bool vis[N];
struct Node{
    int a, t, id;
    bool operator < (const Node &x) const{
        return t < x.t;
    }
}e[N];

//x
bool inline check(int x){
    int now = 0, res = 0;
    for(int i = 1; i <= n; i++){
        if(now + e[i].t > T) break;
        if(e[i].a >= x) {
            now += e[i].t, res++;
        }
        if(res == x) return true;
    }
    return false; 
}

int main(){
    scanf("%d%d", &n, &T);
    for(int i = 1; i <= n; i++) 
        scanf("%d%d", &e[i].a, &e[i].t), e[i].id = i;
    sort(e + 1, e + 1 + n);
    int l = 0, r = n;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%d\n%d\n", r, r);
    int now = 0, res = 0;
    for(int i = 1; i <= n; i++){
        if(now + e[i].t > T) break;
        if(e[i].a >= r) {
            now += e[i].t, res++;
            printf("%d ", e[i].id);
        }
        if(res == r) break;
    }
    return 0;
}