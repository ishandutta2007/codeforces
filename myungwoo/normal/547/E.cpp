#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define MAXL 400005
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int TS, ST;
int N, L, Q;
int S[MAXL], SA[MAXL], lcp[MAXL][20], SP[MAXL], len[MAXN], num[MAXL];
char buf[MAXN];
vector <vector<int>> tree;

struct {
    int s, e;
} A[MAXN];

void SuffixArray()
{
    int m = 128+N;
    vector <int> cnt(max(L, m)+1, 0), x(L+1, 0), y(L+1, 0);
    for (int i=1;i<=L;i++) cnt[x[i] = S[i]]++;
    for (int i=1;i<=m;i++) cnt[i] += cnt[i-1];
    for (int i=L;i;i--) SA[cnt[x[i]]--] = i;
    for (int len=1,p=1;p<L;len<<=1,m=p){
        p = 0;
        for (int i=L-len;++i<=L;) y[++p] = i;
        for (int i=1;i<=L;i++) if (SA[i] > len) y[++p] = SA[i] - len;
        for (int i=0;i<=m;i++) cnt[i] = 0;
        for (int i=1;i<=L;i++) cnt[x[y[i]]]++;
        for (int i=1;i<=m;i++) cnt[i] += cnt[i-1];
        for (int i=L;i;i--) SA[cnt[x[y[i]]]--] = y[i];
        swap(x, y); p = 1; x[SA[1]] = 1;
        for (int i=1;i<L;i++){
            x[SA[i+1]] =
                SA[i]+len <= L && SA[i+1]+len <= L &&
                y[SA[i]] == y[SA[i+1]] && y[SA[i]+len] == y[SA[i+1]+len] ? p : ++p;
        }
    }
}

void LCP()
{
    vector <int> rank(L+1, 0);
    for (int i=1;i<=L;i++) rank[SA[i]] = i;
    int k = 0;
    for (int i=1;i<=L;lcp[rank[i++]][0]=k){
        if (k) k--;
        for (int j=SA[rank[i]-1];S[i+k]==S[j+k];k++);
    }
    for (int j=1;j<20;j++){
        for (int i=2;i+(1 << (j-1))<=L;i++){
            lcp[i][j] = min(lcp[i][j-1], lcp[i+(1 << (j-1))][j-1]);
        }
    }
}

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i=1;i<=N;i++){
        scanf("%s", buf);
        SP[L+1] = i;
        for (len[i]=0;buf[len[i]];len[i]++) S[++L] = buf[len[i]], num[L] = i;
        S[++L] = 128+i;
    }
    SuffixArray(), LCP();
    for (int i=1;i<=L;i++) if (SP[SA[i]]){
        int x = SP[SA[i]], s = i, e = i;
        for (int j=20;j--;){
            if (e + (1 << j) > L) continue;
            if (lcp[e+1][j] >= len[x])
                e += (1 << j);
        }
        for (int j=20;j--;){
            if (s - (1 << j) < 1) continue;
            if (lcp[s - (1 << j) + 1][j] >= len[x])
                s -= (1 << j);
        }
        A[x] = {s, e};
    }
    for (TS=1;TS<L;TS<<=1); TS <<= 1;
    tree.resize(TS); ST = TS/2-1;
    for (int i=1;i<=L;i++) tree[ST+i].pb(num[SA[i]]);
    for (int i=ST;i;i--){
        auto &l = tree[i+i], &r = tree[i+i+1];
        for (int j=0,k=0;j<sz(l)||k<sz(r);){
            if (k == sz(r) || j < sz(l) && l[j] < r[k])
                tree[i].pb(l[j++]);
            else
                tree[i].pb(r[k++]);
        }
    }
    while (Q--){
        int lo, hi, t;
        scanf("%d%d%d", &lo, &hi, &t);
        int ans = 0;
        for (int l=ST+A[t].s,r=ST+A[t].e;l<=r;l>>=1,r>>=1){
            if (l&1){
                ans += upper_bound(all(tree[l]), hi) - lower_bound(all(tree[l]), lo);
                l++;
            }
            if (!(r&1)){
                ans += upper_bound(all(tree[r]), hi) - lower_bound(all(tree[r]), lo);
                r--;
            }
        }
        printf("%d\n", ans);
    }
}