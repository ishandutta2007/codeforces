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

const int MOD = 1e9+7;
int N,K,A[MAXN],par[MAXN];
int D[MAXN][2];
vector <int> con[MAXN];

int inv(int n)
{
    int ret = 1, v = n;
    for (int i=0;i<30;i++,v=(lld)v*v%MOD) if (((MOD-2)>>i)&1){
        ret = (lld)ret*v%MOD;
    }
    return ret;
}

void dfs(int n)
{
    int i,k;
    D[n][0] = 1;
    for (i=sz(con[n]);i--;){
        k = con[n][i];
        dfs(k);
        D[n][0] = (lld)D[n][0]*D[k][0]%MOD;
    }
    if (A[n]) D[n][1] = D[n][0];
    else{
        for (i=sz(con[n]);i--;){
            k = con[n][i];
            int d = (lld)D[n][0]*inv(D[k][0])%MOD;
            D[n][1] = (D[n][1]+(lld)D[k][1]*d%MOD)%MOD;
        }
        add(D[n][0],D[n][1],MOD);
    }
}

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=2;i<=N;i++) scanf("%d",par+i), ++par[i], con[par[i]].pb(i);
    for (i=1;i<=N;i++) scanf("%d",A+i), K += A[i];
    dfs(1);
    printf("%d\n",D[1][1]);
}