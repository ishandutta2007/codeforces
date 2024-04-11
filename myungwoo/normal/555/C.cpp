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

int N, Q;
set <int> VX, VY;

struct NODE{
    NODE(): mx_v(0), left(0), right(0) {}
    int mx_v;
    NODE *left, *right;
} *rootX, *rootY;

int get_max(NODE *now, int s, int e, int x)
{
    if (x < s || x > e || !now) return 0;
    int m = (s+e) >> 1;
    int ret = max(get_max(now->left, s, m, x), get_max(now->right, m+1, e, x));
    return max(ret, now->mx_v);
}

void write(NODE *now, int s, int e, int l, int r, int v)
{
    if (e < l || s > r) return;
    if (l <= s && e <= r){
        now->mx_v = max(now->mx_v, v);
        return;
    }
    if (!now->left) now->left = new NODE(), now->right = new NODE();
    int m = (s+e) >> 1;
    write(now->left, s, m, l, r, v);
    write(now->right, m+1, e, l, r, v);
}

int main()
{
    scanf("%d%d", &N, &Q);
    rootX = new NODE(); rootY = new NODE();
    while (Q--){
        int ans = 0;
        char c; int x, y;
        scanf("%d%d %c", &x, &y, &c);
        if (c == 'L'){
            if (!VY.count(y)){
                VY.insert(y);
                int t = get_max(rootY, 1, N, y);
                ans = x - t;
                write(rootX, 1, N, t+1, x, y);
            }
        }else{
            if (!VX.count(x)){
                VX.insert(x);
                int t = get_max(rootX, 1, N, x);
                ans = y - t;
                write(rootY, 1, N, t+1, y, x);
            }
        }
        printf("%d\n", ans);
    }
}