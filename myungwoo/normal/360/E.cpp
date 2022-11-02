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
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;

#define MAXN 10004

int N,M,K,S1,S2,F;
int T[MAXN],value[101],L[101],R[101];
lld D[MAXN];
vector <int> conr[MAXN],cons[MAXN];
priority_queue <pli> que;

int main()
{
    int i,j,k,d,q,t,x;
    scanf("%d%d%d%d%d%d",&N,&M,&K,&S1,&S2,&F);
    for (i=1;i<=M;i++){
        scanf("%d%d%d",&j,&k,&d);
        conr[j].push_back(k), conr[j].push_back(d);
    }
    for (i=1;i<=K;i++){
        scanf("%d%d%d%d",&j,&k,L+i,R+i);
        cons[j].push_back(k); cons[j].push_back(i);
    }
    if (S1 == S2){
        puts("DRAW");
        for (i=1;i<=K;i++) printf("%d ",L[i]);
        puts("");
        return 0;
    }
    for (i=1;i<=N;i++) D[i] = 1e17;
    for (i=1;i<=K;i++) value[i] = L[i];
    D[S1] = D[S2] = 0;
    T[S1] = 1, T[S2] = 2;
    que.push(mp(0,S1));
    que.push(mp(0,S2));
    while (!que.empty()){
        lld d = que.top().fr;
        q = que.top().sc;
        que.pop();
        if (-d != D[q]) continue;
        t = T[q];
        for (i=0;i<sz(conr[q]);i+=2){
            k = conr[q][i]; d = conr[q][i+1];
            if (D[k] > D[q]+d)
                D[k] = D[q]+d, T[k] = T[q], que.push(mp(-D[k],k));
            else if (D[k] == D[q]+d)
                T[k] |= T[q];
        }
        for (i=0;i<sz(cons[q]);i+=2){
            k = cons[q][i], x = cons[q][i+1];
            d = L[x];
            if (t&2) d = R[x];
            value[x] = (int)d;
            if (D[k] > D[q]+d)
                D[k] = D[q]+d, T[k] = T[q], que.push(mp(-D[k],k));
            else if (D[k] == D[q]+d)
                T[k] |= T[q];
        }
    }
    if (T[F] == 1) puts("WIN");
    else if (T[F] == 3) puts("DRAW");
    else puts("LOSE");
    if (T[F]&1){
        for (i=1;i<=K;i++) printf("%d ",value[i]);
        puts("");
    }
}