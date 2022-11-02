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
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef pair<int,int> pii;
typedef long long lld;

#define MAXN 3003

int N,K;
int G[MAXN],X[MAXN],order[MAXN],size[MAXN],Xsum[MAXN];
vector <int> con[MAXN],en[MAXN];
bool vis[MAXN];

struct EDGE{
    int a,b,c;
    bool operator < (const EDGE &ot)const{
        return c>ot.c;
    }
} E[MAXN];

void dfs(int n,int m)
{
    int i,k,e;
    G[n] = K; size[K]++; Xsum[K] += X[n];
    for (i=sz(con[n]);i--;){
        k = con[n][i], e = en[n][i];
        if (e >= m && !G[k]) dfs(k,m);
    }
}

void set_group(int m)
{
    int i;
    K = 0;
    for (i=1;i<=N;i++) G[i] = 0;
    for (i=1;i<=N;i++) if (!G[i]){
        ++K;
        size[K] = Xsum[K] = 0;
        dfs(i,m);
    }
}

bool proc()
{
    int i,sum=0;
    for (i=1;i<=K;i++) sum += Xsum[i];
    for (i=1;i<=K;i++) if (sum-Xsum[i] < size[i]) return 0;
    return 1;
}

bool cmp(const int &a,const int &b){ return X[a]>X[b]; }

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=1;i<N;i++) scanf("%d%d%d",&E[i].a,&E[i].b,&E[i].c);
    for (i=1;i<=N;i++) scanf("%d",X+i), order[i] = i;
    sort(E+1,E+N); sort(order+1,order+N+1,cmp);
    for (i=1;i<N;i++){
        con[E[i].a].pb(E[i].b), en[E[i].a].pb(i);
        con[E[i].b].pb(E[i].a), en[E[i].b].pb(i);
    }
    for (i=1;i<N;i++){
        set_group(i+1);
        if (proc()) break;
    }
    printf("%d\n",E[i].c);
}