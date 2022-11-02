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

#define MAXN 1000006

int N,M,S,E,deg[MAXN],D[MAXN];
bool V[MAXN];
deque <int> dq;
vector <int> con[MAXN];

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=0;i<M;i++) scanf("%d%d",&j,&k), con[k].pb(j), deg[j]++;
    scanf("%d%d",&S,&E);
    for (i=1;i<=N;i++) D[i] = 1e9; D[E] = 0;
    dq.pb(E);
    while (!dq.empty()){
        int q = dq.front(); dq.pop_front();
        if (q == S) break;
        if (V[q]) continue;
        V[q] = 1;
        for (i=sz(con[q]);i--;){
            k = con[q][i];
            if (!--deg[k]){
                if (D[k] > D[q]) D[k] = D[q], dq.push_front(k);
            }else{
                if (D[k] > D[q]+1) D[k] = D[q]+1, dq.pb(k);
            }
        }
    }
    printf("%d\n",D[S]==1e9?-1:D[S]);
}