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

int N,M,K,U,T;
bool chk[301],w[301][301];
vector <pii> edge;

int main()
{
    int i,j,k;
    scanf("%d%d%d",&N,&M,&K);
    if (K == N || M > (N-1)*(N-2)/2+(N-K)){ puts("-1"); return 0; }
    for (i=1;i<=K;i++) scanf("%d",&k), chk[k] = 1;
    for (i=1;i<=N;i++){
        if (chk[i]) T = i;
        else U = i;
    }
    edge.pb(mp(U,T)); w[U][T] = w[T][U] = 1;
    for (i=1;i<=N;i++) if (i != U && i != T) edge.pb(mp(i,U)), w[i][U] = w[U][i] = 1;
    for (i=1;i<N;i++) for (j=i+1;j<=N;j++) if (!w[i][j]){
        if (i == T || j == T || sz(edge) >= M) continue;
        w[i][j] = w[j][i] = 1;
        edge.pb(mp(i,j));
    }
    for (i=1;i<=N;i++) if (!chk[i] && i != U){
        if (sz(edge) < M) edge.pb(mp(i,T));
    }
    for (i=0;i<sz(edge);i++) printf("%d %d\n",edge[i].fr,edge[i].sc);
}