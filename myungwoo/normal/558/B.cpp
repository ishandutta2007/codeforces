#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MAXV 1000006
#define pb push_back
#define sz(v) ((int)(v).size())

int N;
int A[MAXN];
vector <int> occ[MAXV];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d", A+i), occ[A[i]].pb(i);
    int mx = 0, s = 0, e = 0;
    for (int i=1;i<MAXV;i++) if (!occ[i].empty()){
        int c = sz(occ[i]);
        int len = occ[i].back() - occ[i][0] + 1;
        if (mx < c || mx == c && e-s+1 > len)
            mx = c, s = occ[i][0], e = occ[i].back();
    }
    printf("%d %d\n", s, e);
}