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

#pragma comment(linker,"/STACK:33554432")

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

int N,Q;
int A[MAXN],H[MAXN],ans[MAXN];
bool V[2000006];
vector <int> con[MAXN],prime;
map <int,int> P;

void dfs(int n,int f)
{
    int i;
    vector <int> p,tmp;
    int m = A[n];
    for (i=0;i<sz(prime)&&prime[i]*prime[i]<=m;i++) if (m%prime[i] == 0){
        p.pb(prime[i]);
        tmp.pb(P[prime[i]]);
        P[prime[i]] = n;
        while (m%prime[i] == 0) m /= prime[i];
    }
    if (m > 1){
        p.pb(m);
        tmp.pb(P[m]);
        P[m] = n;
    }
    for (int t: con[n]){
        if (t == f) continue;
        H[t] = H[n]+1; dfs(t,n);
    }
    ans[n] = 0;
    for (i=0;i<sz(p);i++){
        P[p[i]] = tmp[i];
        if (H[ans[n]] < H[tmp[i]]) ans[n] = tmp[i];
    }
    if (!ans[n]) ans[n] = -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,k;
    cin >> N >> Q;
    for (i=1;i<=N;i++) cin >> A[i];
    for (i=1;i<N;i++){
        cin >> j >> k;
        con[j].pb(k); con[k].pb(j);
    }
    prime.pb(2);
    for (i=3;i<2000000;i+=2) if (!V[i]){
        prime.pb(i);
        if (i > 2000000/i) continue;
        for (j=i*i;j<2000000;j+=i+i) V[j] = 1;
    }
    H[1] = 1;
    dfs(1,0);
    while (Q--){
        int type,x;
        cin >> type >> x;
        if (type == 1){
            cout << ans[x] << endl;
        }
        else{
            int v;
            cin >> v;
            A[x] = v;
            P.clear();
            dfs(1,0);
        }
    }
}