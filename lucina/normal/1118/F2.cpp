#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const int mod = 998244353, LOG = 18; /// 998244353

inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

inline int rd(){
	int x=0,fl=1;char ch=gc();
	for (;ch<48||ch>57;ch=gc())if(ch=='-')fl=-1;
	for (;48<=ch&&ch<=57;ch=gc())x=(x<<3)+(x<<1)+(ch^48);
	return x*fl;
}


void plusle(int &a, int b){
    if((a += b) >= mod) a -= mod;
}
int add(int a, int b){
    return (a += b) >= mod ? a - mod : a;
}
int mul(int a, int b){
    return 1LL * a * b % mod;
}
int n, k, f[nax][2];

vector<int> a[nax];
/// LCA stuff
static int tin[nax], tout[nax], timer, up[nax][19], col[nax];
void finish(){
    printf("0");
    exit(0);
}

void pre_lca(int nod, int pa){
    up[nod][0] = pa;
    tin[nod] = ++ timer;
    for(int i = 1 ; i <= LOG  ; i ++)
        up[nod][i] = up[up[nod][i - 1]][i - 1];
    for(int i : a[nod]){
        if(i == pa) continue;
        pre_lca(i, nod);
    }
    tout[nod] = timer ++ ;
}
bool ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v){
    if(ancestor(u, v)) return u;
    if(ancestor(v, u)) return v;
    for(int i = LOG ;i  >= 0 ; i --){
        if(!ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int  pre[nax], suf[nax];
int lc[nax];


int dfs(int nod, int pa){
    int allcol = -1, it = 0;
    int const SZ = (int)a[nod].size();
    pair<int, int> st[SZ];
    int sz = 0;
    for(int i : a[nod]){
        if(i == pa) continue;
        int x = dfs(i, nod);
        if(x != 0){
            if(x > 0 && allcol != -1 &&  allcol != x) finish();
            if(x > 0) allcol = x;
            st[++ sz] = make_pair(i, x);
        }
    }
    if(col[nod] > 0 && allcol != -1 && allcol != col[nod]){
        finish();
    }
    if(col[nod] == 0 && sz == 0){
        return 0;
    }
    if(col[nod] == 0 && allcol == -1){
        /// you can carried forward at most one subtree or not carry at all
        pre[0] = 1;
        for(int i = 1 ; i <= sz; i ++){
            int u = st[i].first;
            pre[i] = mul(pre[i - 1], add(f[u][0], f[u][1]));
        }
        suf[sz + 1] = 1;
        for(int i = sz ; i >= 1 ; i --){
            int u = st[i].first;
            suf[i] = mul(suf[i + 1], add(f[u][0], f[u][1]));
        }
        int res = 0;
        for(int i = 1 ; i <= sz ; i ++){
            int u = st[i].first;
            plusle(res, mul(mul(pre[i - 1], suf[i + 1]), f[u][1]));
        }
        f[nod][1] = res;
        f[nod][0] = pre[sz];
        return -1;
    }
    f[nod][1] = 1;
    for(int i = 1 ;i <= sz ;i ++){
        int u = st[i].first;
        if(st[i].second == -1)
            f[nod][1] = mul(f[nod][1], add(f[u][0], f[u][1]));
        else if(st[i].second > 0)
            f[nod][1] = mul(f[nod][1], f[u][1]);
    }
    if(col[nod] == 0) return allcol;
    return lc[col[nod]] == nod ? -1 : col[nod] ;
}

int main(){
    tout[0] = 1e9;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &col[i]);
    for(int i = 1 ;i < n ;i ++){
        int u, v;
        u = rd() ,  v = rd();
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    pre_lca(1, 0);
    for(int i = 1 ;i <= n; i++){
        if(col[i]){
            lc[col[i]] = (lc[col[i]] > 0) ? lca(lc[col[i]], i) : i;
        }
    }
    for(int i = 1 ;i <= k ; i++){
        if(col[lc[i]] != 0 && col[lc[i]] != i){
            puts("0");
            return 0;
        }
        col[lc[i]] = i;
    }
    dfs(1, 0);
    printf("%d\n", f[1][1]);
}