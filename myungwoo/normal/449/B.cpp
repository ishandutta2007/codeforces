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

int N,M,K,ans;
int S[MAXN];
lld D[MAXN];
bool chk[MAXN],V[MAXN];

vector <int> con[MAXN],conv[MAXN];
vector <pii> list;
priority_queue <pli> que;

int main()
{
    int i,j,k;
    scanf("%d%d%d",&N,&M,&K);
    while (M--){
        scanf("%d%d%d",&i,&j,&k);
        con[i].pb(j); conv[i].pb(k);
        con[j].pb(i); conv[j].pb(k);
    }
    for (i=2;i<=N;i++) D[i] = 1e17;
    for (i=1;i<=K;i++){
        scanf("%d%d",&j,&k);
        list.pb(mp(j,k));
        if (D[j] > k) D[j] = k;
    }
    for (i=1;i<=N;i++) if (D[i] < 1e17) que.push(mp(-D[i],i));
    while (!que.empty()){
        int q = que.top().second; lld d = -que.top().first; que.pop();
        if (V[q]) continue;
        V[q] = 1;
        for (i=sz(con[q]);i--;){
            int k = con[q][i]; lld v = conv[q][i];
            if (D[k] >= D[q]+v) D[k] = D[q]+v, chk[k] = 1, que.push(mp(-D[k],k));
        }
    }
    for (i=0;i<K;i++){
        int j = list[i].first, k = list[i].second;
        if (D[j] != k || chk[j]) ans++;
        else chk[j] = 1;
    }
    printf("%d\n",ans);
}