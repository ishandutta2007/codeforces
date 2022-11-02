#include <bits/stdc++.h>
using namespace std;

#define MAXN 500005
#define TS 1048576
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())

int N, M;
int A[MAXN], L[MAXN], ans[MAXN];
int tree[TS], ST = TS/2-1;

struct QUERY{
    int l, r, idx;
} Q[MAXN];

struct INFO{
    int l, idx;
};

void write_val(int n, int v)
{
    for (n+=ST;n;n>>=1)
        tree[n] = min(tree[n], v);
}

int get_min(int l, int r)
{
    int ret = 2e9;
    for (l+=ST,r+=ST;l<=r;l>>=1,r>>=1){
        if (l&1) ret = min(ret, tree[l++]);
        if (!(r&1)) ret = min(ret, tree[r--]);
    }
    return ret;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;i++) scanf("%d", A+i);
    for (int i=1;i<=M;i++) scanf("%d%d", &Q[i].l, &Q[i].r), Q[i].idx = i;
    sort(Q+1, Q+M+1, [](const QUERY &a, const QUERY &b){
        return a.l > b.l;
    });
    map <int, int> latest;
    vector <INFO> arr;
    for (int i=1;i<=N;i++){
        int &v = latest[A[i]];
        if (v){
            L[i] = v;
            arr.push_back({L[i], i});
        }
        v = i;
    }
    sort(all(arr), [](const INFO &a, const INFO &b){
        return a.l > b.l;
    });
    for (int i=1;i<TS;i++) tree[i] = 2e9;
    for (int i=1,j=0;i<=M;i++){
        while (j < sz(arr) && arr[j].l >= Q[i].l){
            write_val(arr[j].idx, arr[j].idx-arr[j].l);
            j++;
        }
        ans[Q[i].idx] = get_min(Q[i].l, Q[i].r);
    }
    for (int i=1;i<=M;i++) printf("%d\n", ans[i] == 2e9 ? -1 : ans[i]);
}