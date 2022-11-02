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

#define MAXN 300005

map <int, int> A, idx;
vector <pii> B;
int Q, N;
int bit[MAXN];

int get_val(int x)
{
    int &ret = A[x];
    if (!ret) ret = x;
    return ret;
}

inline int get_changed(int s, int e)
{
    return upper_bound(all(B), mp(e+1, 0)) - lower_bound(all(B), mp(s, 0));
}

int read(int x)
{
    int ret = 0;
    for (;x;x-=(x&-x)) ret += bit[x];
    return ret;
}

void write(int x, int v)
{
    for (;x<=N;x+=(x&-x)) bit[x] += v;
}

int main()
{
    for (scanf("%d", &Q);Q--;){
        int a, b;
        scanf("%d%d", &a, &b);
        int p = get_val(a), q = get_val(b);
        A[b] = p, A[a] = q;
    }
    for (auto &it: A) B.pb(it);
    N = sz(B);
    for (int i=0;i<N;i++) idx[B[i].first] = i+1, write(i+1, 1);
    lld ans = 0;
    for (auto &p: B){
        int x = p.first, v = p.second, pos = idx[v];
        write(pos, -1);
        int cnt = read(pos-1);
        if (x < v){
            int changed = get_changed(x+1, v-1);
            cnt += v-1-x - changed;
        }
        else if (x > v){
            int changed = get_changed(v+1, x-1);
            cnt += x-1-v - changed;
        }
        ans += cnt;
    }
    cout << ans << endl;
}