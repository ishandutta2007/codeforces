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

#define MAXN 1004
#define MAXM 3008

int N,M,L[MAXM],R[MAXM],D[MAXN],ans;
vector <int> con[MAXN],V;

void proc(int mn)
{
    int i,j,k;
    set(D,0);
    priority_queue <pii> que;
    D[1] = 1e9; que.push(mp(1e9,1));
    while (!que.empty()){
        int d = que.top().fr;
        int q = que.top().sc;
        que.pop();
        if (D[q] != d) continue;
        for (i=0;i<sz(con[q]);i+=2){
            int k=con[q][i],m=con[q][i+1];
            if (L[m] <= mn & mn <= R[m] && L[m] <= D[q]){
                int nxt = min(D[q],R[m]);
                if (D[k] < nxt) D[k] = nxt, que.push(mp(D[k],k));
            }
        }
    }
    put_max(ans,D[N]-mn+1);
}

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=1;i<=M;i++){
        scanf("%d%d%d%d",&j,&k,L+i,R+i);
        con[j].pb(k); con[j].pb(i);
        con[k].pb(j); con[k].pb(i);
        V.pb(L[i]), V.pb(R[i]);
    }
    sort(all(V));
    for (i=0;i<sz(V);i++){
        proc(V[i]);
    }
    if (ans) printf("%d\n",ans);
    else puts("Nice work, Dima!");
}