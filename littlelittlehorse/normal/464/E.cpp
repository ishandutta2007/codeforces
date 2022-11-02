#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    node *next;
    int where, cost;
} *first[100001], a[200001];

int SS, n, m, l, S, T, root[100001], num, pre[100001];

struct tree{
    int l, r, value, hash1, hash2;
} f[10000001];

bool b[100001];
const int P = 1000000007, M = 9999971;
int u[100101], c[100001];

const int Max = 100020;

bool check(int k1, int k2, int Left, int Right){
    if (Left == Right)
    {
    //  printf("%d %d\n", Left, f[k1].hash1);
        if (!f[k1].hash1) return true;
        return false;
    }
    int i = (Left + Right) >> 1;
//  printf("! %d %d %d %d %d %d %d %d %d %d\n", k1, k2, f[k1].r, f[k2].r, Left, Right, f[f[k1].r].hash1 , f[f[k2].r].hash1, f[f[k1].r].hash2, f[f[k2].r].hash2);
    if (f[f[k1].r].hash1 == f[f[k2].r].hash1 && f[f[k1].r].hash2 == f[f[k2].r].hash2)
          return check(f[k1].l, f[k2].l, Left, i);
    return check(f[k1].r, f[k2].r, i + 1, Right);
}

struct zhj{
    int pos, root, where;
    zhj(){};
    zhj(int A, int B, int C){
        pos = A; root = B; where = C;
    }
};

struct cmp{
    bool operator ()(zhj &x, zhj &y){
        return !check(x.root, y.root, 0, Max);
    }
};

priority_queue<zhj, vector<zhj>, cmp> e;

inline void makelist(int x, int y, int z){
    a[++l].where = y; a[l].cost = z;
    a[l].next = first[x]; first[x] = &a[l];
}

inline void buildtree(int k, int Left, int Right){
    f[k].value = Left; f[k].hash1 = f[k].hash2 = 0;
    if (Left == Right) return;
    int i = (Left + Right) >> 1;
    f[k].l = ++num; f[k].r = ++num;
    buildtree(f[k].l, Left, i);
    buildtree(f[k].r, i + 1, Right);
}

int calc(int k, int Left, int Right){
    if (Left == Right)
    {
        if (f[k].hash1) 
        {
        //  printf("%d\n", Left);
            return u[Left];
        }
        return 0;
    }
    int i = (Left + Right) >> 1;
    return (calc(f[k].l, Left, i) + calc(f[k].r, i + 1, Right)) % P;
}
  
inline void write(){
    //printf("!\n");
    printf("%d\n", calc(root[T], 0, Max));
//  for (int i = 1; i <= T; i++) printf("%d %d\n", i, pre[i]);
//  printf("\n");
    int cnt = 0;
    for (int now = T; now != S; now = pre[now]) c[++cnt] = now;
    c[++cnt] = S;
    printf("%d\n", cnt);
    for (int i = cnt; i; i--)
    {
        printf("%d", c[i]);
        if (i != 1) printf(" ");
    }
    printf("\n");
}

int find(int k, int Left, int Right, int s, int t){
//if (k <= 100 && k)    printf("%d %d %d %d %d %d %d %d\n", k, Left, Right, s, t, f[k].value, f[k].l, f[k].r);
    if (Left == s && Right == t) return f[k].value;
    int i = (Left + Right) >> 1;
    if (t <= i) return find(f[k].l, Left, i, s, t);
    else if (s > i) return find(f[k].r, i + 1, Right, s, t);
    else return min(find(f[k].l, Left, i, s, i), find(f[k].r, i + 1, Right, i + 1, t));
}

inline void dhh(int k, int Left, int Right){
    f[k].hash1 = (f[f[k].l].hash1 + f[f[k].r].hash1) % P;
    f[k].hash2 = (f[f[k].l].hash2 + f[f[k].r].hash2) % M;
    f[k].value = min(f[f[k].l].value, f[f[k].r].value);
}

inline void update(int k1, int k2, int k3, int Left, int Right, int s, int t){
    //printf("%d %d %d %d %d %d %d\n", k1, k2, k3, Left, Right, s, t);
    if (Left == s && Right == t) 
    {
        f[k1] = f[k3];
        return;
    }
    int i = (Left + Right) >> 1;
    if (t <= i) 
    {
        f[k1].l = ++num; f[k1].r = f[k2].r;
        update(f[k1].l, f[k2].l, f[k3].l, Left, i, s, t);
    }
    else
    if (s > i)  
    {
        f[k1].r = ++num; f[k1].l = f[k2].l;
        update(f[k1].r, f[k2].r, f[k3].r, i + 1, Right, s, t);
    }
    else
    {
        f[k1].l = ++num;
        update(f[k1].l, f[k2].l, f[k3].l, Left, i, s, i);
        f[k1].r = ++num;
        update(f[k1].r, f[k2].r, f[k3].r, i + 1, Right, i + 1, t);
    }
    dhh(k1, Left, Right);
}

inline void change(int k1, int k2, int Left, int Right, int x){
    if (Left == Right)
    {
    //  printf("%d %d %d\n", k1, Left, u[Left]);
        f[k1].value = 1 << 30; f[k1].hash1 = u[Left] % P; f[k1].hash2 = u[Left] % M;
        return;
    }
    int i = (Left + Right) >> 1;
    if (x <= i) 
    {
        f[k1].r = f[k2].r; f[k1].l = ++num;
        change(f[k1].l, f[k2].l, Left, i, x);
    }
    else
    {
        f[k1].l = f[k2].l; f[k1].r = ++num;
        change(f[k1].r, f[k2].r, i + 1, Right, x);
    }
    dhh(k1, Left, Right);
//  printf("! %d %d %d\n", k1, f[k1].hash1, f[k2].hash2);
}

inline void work(int S, int T, int x){
    int pos = find(root[S], 0, Max, x, Max);
//  printf("%d %d %d %d\n", S, T, x, pos);
    zhj now(T, ++num, S);
    if (pos == x)
    {
        f[num].l = f[root[S]].l; f[num].r = f[root[S]].r;
    }
    else
    update(now.root, root[S], root[SS], 0, Max, x, pos - 1);
    zhj sx(T, ++num, S);
    //printf("%d %d %d\n", S, T, x);
    change(sx.root, now.root, 0, Max, pos);
    e.push(sx);
}
    
int main(){
//  freopen("e.in", "r", stdin);
//  freopen("e.out", "w", stdout);
    u[0] = 1;
    for (int i = 1; i <= Max; i++) u[i] = u[i - 1] << 1, u[i] %= P;
    scanf("%d%d", &n, &m);
    memset(first, 0, sizeof(first)); l = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        makelist(x, y, z); makelist(y, x, z);
    }
    scanf("%d%d", &S, &T); SS = S;
    e.push(zhj(S, 1, 0));
    memset(b, false, sizeof(b));
    num = 1;
    buildtree(1, 0, Max);
//  cerr << num << endl;
    for (; !e.empty();)
    {
        zhj m = e.top(); e.pop();
        if (b[m.pos]) continue;
        root[m.pos] = m.root;
        pre[m.pos] = m.where;
        b[m.pos] = true;
        if (m.pos == T)
        {
            write();
            return 0;
        }
        for (node *x = first[m.pos]; x; x = x->next) work(m.pos, x->where, x->cost);    
    }    
    printf("-1\n");
}