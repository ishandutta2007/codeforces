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

#define MAXN 100005

int N, P, Q;
int stk[MAXN]; int scnt;

struct Z{
    int x, y;
} A[MAXN];

int ccw(int ax, int ay, int bx, int by, int cx, int cy)
{
    lld k = (lld)(bx-ax)*(cy-ay) - (lld)(cx-ax)*(by-ay);
    if (k > 0) return 1;
    if (k) return -1;
    return 0;
}

int ccw(const Z &a, const Z &b, const Z &c){ return ccw(a.x, a.y, b.x, b.y, c.x, c.y); }

int main()
{
    scanf("%d%d%d", &N, &P, &Q);
    for (int i=1;i<=N;i++) scanf("%d%d", &A[i].x, &A[i].y);
    int mx_x = 0, mx_y = 0;
    for (int i=1;i<=N;i++)
        mx_x = max(mx_x, A[i].x), mx_y = max(mx_y, A[i].y);
    A[++N] = {mx_x, 0};
    A[++N] = {0, mx_y};
    A[++N] = {0, 0};
    for (int i=2;i<=N;i++)
        if (A[1].y > A[i].y || A[1].y == A[i].y && A[1].x > A[i].x)
            swap(A[1], A[i]);
    sort(A+2, A+N+1, [](const Z &a, const Z &b){
        int k = ccw(A[1], a, b);
        if (k) return k > 0;
        return abs(a.x-A[1].x)+abs(a.y-A[1].y) < abs(b.x-A[1].x)+abs(b.y-A[1].y);
    });
    stk[scnt=1] = 1;
    for (int i=2;i<=N;i++){
        while (scnt > 1 && ccw(A[stk[scnt-1]], A[stk[scnt]], A[i]) <= 0) scnt--;
        stk[++scnt] = i;
    }
    double S = (double)Q / P, ans = 1e18;
    for (int i=2;i<scnt;i++){
        Z a = A[stk[i]], b = A[stk[i+1]];
        if (a.x == b.x){
            double rs = (double)(a.x-b.x)/(a.y-b.y);
            double c = a.x - rs*a.y;
            double y = c / (1 / S - rs);
            if (y < min(a.y, b.y)-eps || y > max(a.y, b.y)+eps) continue;
            ans = min(ans, Q / y);
        }else{
            double s = (double)(a.y-b.y)/(a.x-b.x); 
            double c = a.y - s*a.x;
            double x = c / (S - s);
            if (x < min(a.x, b.x)-eps || x > max(a.x, b.x)+eps) continue;
            ans = min(ans, P / x);
        }
    }
    printf("%.12f\n", ans);
}