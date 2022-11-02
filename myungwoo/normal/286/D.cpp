#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
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
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef pair<int,int> pii;
typedef long long lld;

#define MAXN 200005
#define TS 524288

int Q,M,N,T[MAXN],ans,sum,cnt;
int tree[TS],ST=TS/2-1;
vector <int> X;

struct WALL{
    WALL(int s=0,int e=0,int t=0): s(s),e(e),t(t) {}
    int s,e,t;
    bool operator < (const WALL &ot)const{
        return t < ot.t;
    }
};
vector <WALL> W;
vector <pii> in;
vector <pii> out;

void write(int l,int r,int v)
{
    for (;l<=r;l>>=1,r>>=1){
        if (l&1) tree[l++] = v;
        if (!(r&1)) tree[r--] = v;
    }
}

int get(int n)
{
    int ret=2e9;
    for (;n;n>>=1) put_min(ret,tree[n]);
    return ret;
}

int main()
{
    int i,j,s,e,t,p,q;
    scanf("%d%d",&Q,&M);
    for (i=1;i<=M;i++){
        scanf("%d%d%d",&s,&e,&t); X.pb(s), X.pb(e);
        W.pb(WALL(s,e,t));
    }
    sort(all(X)); X.erase(unique(all(X)),X.end()); N = sz(X);
    sort(all(W));
    for (i=1;i<TS;i++) tree[i] = 2e9;
    for (i=M;i--;){
        int l = ST+(lower_bound(all(X),W[i].s)-X.begin())+1;
        int r = ST+(lower_bound(all(X),W[i].e)-X.begin());
        write(l,r,W[i].t);
    }
    for (i=1;i<N;i++){
        T[i] = get(ST+i);
        in.pb(mp(T[i]-X[i],i));
        out.pb(mp(T[i]-X[i-1],i));
    }
    sort(all(in)), sort(all(out));
    for (i=p=q=0;i<Q;i++){
        scanf("%d",&t);
        while (q < sz(in) && in[q].fr <= t) sum += X[in[q].sc]-T[in[q].sc], q++, cnt++;
        while (p < sz(out) && out[p].fr <= t) sum -= X[out[p].sc]-T[out[p].sc], ans += X[out[p].sc]-X[out[p].sc-1], p++, cnt--;
        printf("%d\n",ans+sum+t*cnt);
    }
}