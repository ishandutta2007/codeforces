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

#define MAXN 1000016

int Q,X=2,Y=3,N=4,ans=2;
int mom[MAXN][19],dep[MAXN];

int dist(int a,int b)
{
    int i,ret=dep[a]+dep[b];
    if (dep[a] < dep[b]) swap(a,b);
    for (i=0;i<19;i++) if (((dep[a]-dep[b])>>i)&1) a = mom[a][i];
    if (a == b) return ret-dep[a]-dep[a];
    for (i=19;i--;) if (mom[a][i] != mom[b][i]) a = mom[a][i], b = mom[b][i];
    a = mom[a][0];
    return ret-dep[a]-dep[a];
}

int main()
{
    int i;
    for (i=2;i<5;i++) mom[i][0] = 1, dep[i] = 1;
    for (scanf("%d",&Q);Q--;){
        int n; scanf("%d",&n);
        mom[++N][0] = n; dep[N] = dep[n]+1;
        for (i=1;i<19;i++) mom[N][i] = mom[mom[N][i-1]][i-1];
        dep[++N] = dep[n]+1;
        for (i=0;i<19;i++) mom[N][i] = mom[N-1][i];
        int dx = dist(N,X), dy = dist(N,Y);
        if (dx > dy){
            if (ans < dx) ans = dx, Y = N;
        }else{
            if (ans < dy) ans = dy, X = N;
        }
        printf("%d\n",ans);
    }
}