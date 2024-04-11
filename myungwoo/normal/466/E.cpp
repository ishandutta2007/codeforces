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

int N,M,K,X;
int H[MAXN],V[MAXN],par[MAXN],in[MAXN],out[MAXN];
int S[MAXN],MH[MAXN];
bool chk[MAXN];
vector <int> con[MAXN];

struct QUERY{
    int t,x,y;
};
vector <QUERY> Q;

void dfs(int n)
{
    in[n] = ++K;
    for (int k: con[n]){
        H[k] = H[n]+1; dfs(k);
    }
    out[n] = K;
}

int find(int n){
    return par[n]==n?n:(par[n]=find(par[n]));
}

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=0;i<M;i++){
        int t,x,y=0;
        scanf("%d%d",&t,&x);
        if (t != 2) scanf("%d",&y);
        if (t == 1) con[y].pb(x), chk[x] = 1;
        Q.pb({t,x,y});
    }
    for (i=1;i<=N;i++) par[i] = i;
    for (i=1;i<=N;i++) if (!chk[i]) H[i] = 1, dfs(i);
    for (auto &q: Q){
        if (q.t == 1){
            int x = find(q.x), y = find(q.y);
            par[x] = y;
        }
        else if (q.t == 2){
            S[++X] = q.x;
            int x = find(q.x);
            MH[X] = H[x];
        }
        else{
            if (MH[q.y] <= H[q.x] && in[q.x] <= in[S[q.y]] && in[S[q.y]] <= out[q.x]) puts("YES");
            else puts("NO");
        }
    }
}