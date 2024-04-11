#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

struct node{
    node(){x=0;link[0]=link[1]=0;}
    node(int x):x(x){link[0] = link[1] = 0;}
    int c, x;
    node *link[2];
}*rootL, *rootU;

void update(node *rt,int s,int d,int l,int r,int v){
    if(s <= l && r <= d){
        rt->x = max(rt->x, v);
        return;
    }
    int m = (l+r)>>1;
    if(!(rt->link[0]))rt->link[0] = new node(-1);
    if(!(rt->link[1]))rt->link[1] = new node(-1);
    if(rt->x != -1){
        rt->link[0]->x = max(rt->link[0]->x, rt->x);
        rt->link[1]->x = max(rt->link[1]->x, rt->x);
        rt->x = -1;
    }
    if(s <= m)update(rt->link[0], s, d, l, m, v);
    if(m < d)update(rt->link[1], s, d, m+1, r, v);
}

int n, m;

void update(node *rt, int s, int d, int v){
    update(rt, s, d, 1, n, v);
}

int read(node *rt,int w,int l,int r){
    if(l == r)return rt->x;
    int m = (l+r)>>1;
    if(!(rt->link[0]))rt->link[0] = new node(-1);
    if(!(rt->link[1]))rt->link[1] = new node(-1);
    if(rt->x != -1){
        rt->link[0]->x = max(rt->link[0]->x, rt->x);
        rt->link[1]->x = max(rt->link[1]->x, rt->x);
        rt->x = -1;
    }
    if(w <= m)return rt->link[0] ? read(rt->link[0], w, l, m) : rt->x;
    else return rt->link[1] ? read(rt->link[1], w, m+1, r) : rt->x;
}

int read(node *rt,int v){
    return read(rt, v, 1, n);
}

int main() {
    rootL = new node(-1);
    rootU = new node(-1);
    update(rootL, 1, n, 0);
    update(rootU, 1, n, 0);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x, y;
        char ch[3];
        scanf("%d%d%s", &y, &x, ch);
        if(ch[0] == 'L'){
            int v = read(rootU, x);
    //      printf("%d\n",v);
            printf("%d\n", y - v);
            if(v != y)update(rootL, v+1, y, x);
            update(rootU, x, x, y);
        }
        else{
            int v = read(rootL, y);
    //      printf("%d\n",v);
            printf("%d\n", x - v);
            if(v != x)update(rootU, v+1, x, y);
            update(rootL, y, y, x);
        }
    }
    return 0;
}