#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 200005

int N, Q;
int pos[MAXN];

struct Z{
    int x, idx;
} A[MAXN];

int find_rightmost(int x)
{
    int s = 1, e = N, t = 0;
    while (s <= e){
        int m = (s+e) >> 1;
        if (A[m].x <= x) s = m+1, t = m;
        else e = m-1;
    }
    return t;
}

int find_leftmost(int x)
{
    int s = 1, e = N, t = 0;
    while (s <= e){
        int m = (s+e) >> 1;
        if (A[m].x >= x) e = m-1, t = m;
        else s = m+1;
    }
    return t;
}

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i=1;i<=N;i++){
        scanf("%d", &A[i].x); A[i].idx = i;
    }
    sort(A+1, A+N+1, [](const Z &a, const Z &b){
        return a.x < b.x;
    });
    for (int i=1;i<=N;i++) pos[A[i].idx] = i;
    while (Q--){
        int t, l;
        scanf("%d%d", &t, &l); t = pos[t];
        if (N == 1){ puts("1"); continue; }
        for (;;){
            int tmp = l;
            int r = find_rightmost(A[t].x+l);
            l -= A[r].x - A[t].x;
            int lt = find_leftmost(A[r].x-l);
            l -= A[r].x - A[lt].x;
            if (lt == t && r != t) l %= (A[r].x - A[t].x) * 2;
            t = lt;
            if (t == 1)
                l %= (A[N].x - A[1].x) * 2;
            if (tmp == l) break;
        }
        printf("%d\n", A[t].idx);
    }
}