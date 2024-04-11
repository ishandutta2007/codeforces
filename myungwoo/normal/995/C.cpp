#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define pb push_back
#define sz(v) ((int)(v).size())

const int R = 1e6;
int N, M;
int res[MAXN];

struct Z {
    int x, y, l, r, s;
} A[MAXN];

void dfs(int n, int s)
{
    if (!n) return;
    res[n] = s;
    dfs(A[n].l, s);
    dfs(A[n].r, s*A[n].s);
}

int main()
{
    scanf("%d", &N);
    vector <int> stk;
    for (int i=1;i<=N;i++){
        scanf("%d%d", &A[i].x, &A[i].y);
        stk.push_back(i);
    }
    M = N;
    while (sz(stk) > 2){
        int c = stk.back(); stk.pop_back();
        int b = stk.back(); stk.pop_back();
        int a = stk.back(); stk.pop_back();
        vector <int> arr = {a, b, c};
        int rm = 0; M++;
        for (int i=0;i<3;i++) for (int j=i+1;j<3;j++){
            for (int k: {-1, 1}){
                int x = A[arr[i]].x + k*A[arr[j]].x;
                int y = A[arr[i]].y + k*A[arr[j]].y;
                if (hypot(x, y) > R) continue;
                A[M].l = arr[i]; A[M].r = arr[j]; A[M].s = k; A[M].x = x; A[M].y = y;
                rm = arr[3-i-j];
            }
        }
        assert(rm != 0);
        stk.push_back(M); stk.push_back(rm);
    }
    M++; A[M].l = stk[0]; A[M].r = stk[1]; A[M].s = 1;
    if (hypot(A[stk[0]].x+A[stk[1]].x, A[stk[0]].y+A[stk[1]].y) > 1.45*R) A[M].s = -1;
    dfs(M, 1);
    for (int i=1;i<=N;i++) printf("%d%s", res[i], i < N ? " " : "\n");
}