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
#define TS 524288

int N, M;
int D[MAXN], F[MAXN];
pii tree[TS]; int ST = TS/2-1;
vector <int> XX;
vector <pii> ylist[MAXN*2];

struct Z{
    int a, b, c, d;
} A[MAXN];

void erase(int n)
{
    int x = A[n].a;
    if (ylist[x].back().sc != n) exit(1);
    ylist[x].pop_back();
    tree[ST+x] = ylist[x].back();
    for (x=(ST+x)>>1;x;x>>=1) tree[x] = min(tree[x+x], tree[x+x+1]);
}

int get(int l, int r)
{
    pii ret(2e9, 0);
    for (l+=ST,r+=ST;l<=r;l>>=1,r>>=1){
        if (l&1) ret = min(ret, tree[l++]);
        if (!(r&1)) ret = min(ret, tree[r--]);
    }
    return ret.sc;
}

int main()
{
    scanf("%d", &N);
    XX.pb(0);
    for (int i=1;i<=N;i++){
        scanf("%d%d%d%d", &A[i].a, &A[i].b, &A[i].c, &A[i].d);
        XX.pb(A[i].a); XX.pb(A[i].c);
    }
    sort(all(XX));
    XX.erase(unique(all(XX)), XX.end());
    M = sz(XX);
    for (int i=1;i<=N;i++){
        A[i].a = lower_bound(all(XX), A[i].a) - XX.begin() + 1;
        A[i].c = lower_bound(all(XX), A[i].c) - XX.begin() + 1;
        ylist[A[i].a].pb(mp(A[i].b, i));
    }
    for (int i=1;i<=M;i++){
        ylist[i].pb(mp(2e9, 0));
        sort(all(ylist[i]), greater<pii>());
        tree[ST+i] = ylist[i].back();
    }
    for (int i=ST;i;i--) tree[i] = min(tree[i+i], tree[i+i+1]);

    for (int i=1;i<=N;i++) D[i] = 2e9;
    A[0] = {1, 0, 1, 0};
    queue <int> que;
    D[0] = 0; que.push(0);
    while (!que.empty()){
        int q = que.front(); que.pop();
        for (;;){
            int t = get(1, A[q].c);
            if (!t || A[t].b > A[q].d) break;
            erase(t);
            D[t] = D[q]+1; F[t] = q; que.push(t);
        }
    }

    if (D[N] == 2e9){ puts("-1"); return 0; }
    vector <int> path;
    for (int i=N;i;i=F[i]) path.pb(i);
    reverse(all(path));
    printf("%d\n", sz(path));
    for (int t: path) printf("%d ", t); puts("");
}